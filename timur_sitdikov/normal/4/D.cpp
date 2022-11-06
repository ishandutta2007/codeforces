#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct rec{int n, x, y;} rc[5000];

int cmp(const void *c1, const void *c2)
{return ((rec*)c1)->x-((rec*)c2)->x;}

int main()
{   
    int i, n, j, top=0, val[5000], prev[5000], a, b, stack[5000], max, maxi;
    scanf("%d %d %d", &n, &a, &b);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &rc[top].x, &rc[top].y);
        if (rc[top].x>a && rc[top].y>b) {rc[top].n=i+1; top++;}
    }
    n=top;
    qsort(rc, n, sizeof(rec), cmp);
    for(i=0; i<n; i++) {prev[i]=-1; val[i]=1;}
    for(i=1; i<n; i++)
        for(j=0; j<i; j++)
        {
            if (rc[j].x<rc[i].x && rc[j].y<rc[i].y && val[j]+1>val[i]) {val[i]=val[j]+1; prev[i]=j;}
        }
    for(maxi=-1, max=0, i=0; i<n; i++) if (max<val[i]) {max=val[i]; maxi=i;}
    for(i=maxi, top=-1; i!=-1; i=prev[i])
        stack[++top]=rc[i].n;
    printf("%d\n", top+1);
    for(; top>=0; top--) printf("%d ", stack[top]);
}