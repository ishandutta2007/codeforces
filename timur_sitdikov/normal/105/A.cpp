#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct par{char name[21]; int v;} pr1[20], pr2[20], pr[40];
int n, m, top, col[20], col1[20];

int cmp(const void *c1, const void *c2)
{return strcmp(((par*)c1)->name, ((par*)c2)->name);}

int main()
{ 
    double k;
    int i,j;
    scanf("%d %d %lf", &n, &m, &k);
    for(i=0; i<n; i++) scanf("%s %d", &pr1[i].name, &pr1[i].v);
    for(i=0; i<m; i++) scanf("%s", &pr2[i].name);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++) if (!strcmp(pr1[i].name, pr2[j].name)) 
        {col[j]=1; if ((int)(pr1[i].v*k+0.0001)<100) {pr1[i].v=0; col1[i]=1;}}
    for(i=0; i<n; i++)
        if (col1[i] || (int)(pr1[i].v*k+0.0001)>=100) 
        {strcpy(pr[top].name, pr1[i].name); pr[top++].v=(int)(pr1[i].v*k+0.0001);}
    for(j=0; j<m; j++)
        if (!col[j])
        {strcpy(pr[top].name, pr2[j].name); pr[top++].v=0;}
    qsort(pr, top, sizeof(par), cmp);
    printf("%d\n", top);
    for(i=0; i<top; i++)
        printf("%s %d\n", pr[i].name, pr[i].v);
}