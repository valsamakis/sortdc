#include <stdio.h>
#include <stdlib.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

typedef struct {
    int data; // satellite data
} node;

/* the comparator */
static int compare(const void *p1, const void *p2) {
    const node *n1 = * (const node **) p1;
    const node *n2 = * (const node **) p2;
    
    return n1->data - n2->data;
}

void sortdc(size_t size) {
    node **array = (node **) malloc(size * sizeof (node *));
    
    int i = 0;
    for (; i < size; i++) {
        node *p = (node *) malloc(sizeof (node));
        p->data = (int) (size * frand());
        array[i] = p;
    }
    
    for (i = 0; i < size; i++) {
        printf("%d, ", array[i]->data );
    }
    
    qsort(array, size, sizeof (node *), compare);

    puts("\n");
    for (i = 0; i < size; i++) {
        printf("%d, ", array[i]->data );
    }
    puts("\n");
}
