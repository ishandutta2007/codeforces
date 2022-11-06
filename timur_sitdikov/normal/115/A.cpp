#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

int prv[2005], n, ans=0;
char col[2005], pr[2005];

void dfs(int s, int d)
{
    int i;
    col[s]=1;
    for(i=s; i!=-1; i=prv[i]) d++;
    if (d>ans) ans=d;
}

int main()
{   
    int a, i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a);
        prv[i]=a;
    }
    for(i=1; i<=n; i++) 
        if (prv[i]!=-1) pr[prv[i]]=1;
    for(i=1; i<=n; i++)
        if (pr[i]!=-1) 
        {
            for(j=1; j<=n; j++) col[j]=0;
            dfs(i, 0);
        }
    printf("%d", ans);
}