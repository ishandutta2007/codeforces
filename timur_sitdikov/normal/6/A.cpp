#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return *(int*)c1-*(int*)c2;}

int main()
{   

    int a[4], i;
    for(i=0; i<4; i++) scanf("%d", &a[i]);
    qsort(a, 4, sizeof(int), cmp);
    if (a[0]+a[1]>a[2] || a[1]+a[2]>a[3]) {printf("TRIANGLE"); return 0;}
    if (a[0]+a[1]==a[2] || a[1]+a[2]==a[3]) {printf("SEGMENT"); return 0;}
    printf("IMPOSSIBLE");
}