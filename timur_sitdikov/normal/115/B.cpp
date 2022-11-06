#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   
    char g[155][155];
    int i, j, pos, pos2, ans=0, n, m;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) scanf("%s", &g[i]);
    for(i=0, pos=0; i<n; i++)
    {
        pos2=pos;
        if (!(i&1))
        {
            for(j=pos; j<m; j++) if (g[i][j]=='W') pos2=j;
            if (i!=n-1) for(j=pos; j<m; j++) if (g[i+1][j]=='W' && pos2<j) pos2=j;
            ans+=pos2-pos; pos=pos2;
        }
        else
        {
            for(j=pos; j>=0; j--) if (g[i][j]=='W') pos2=j;
            if (i!=n-1) for(j=pos; j>=0; j--) if (g[i+1][j]=='W' && pos2>j) pos2=j;
            ans-=pos2-pos; pos=pos2;
        }
    }
    for(i=n-1; i>=0; i--)
        for(j=0; j<m; j++) 
            if (g[i][j]=='W') goto l;
l:  ans+=i;
    if (i==-1) ans=0;
    printf("%d", ans);
}