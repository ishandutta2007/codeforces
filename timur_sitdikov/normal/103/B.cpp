#include <stdio.h>

char g[101][101], col[101];
int n, par[101];

int dfs(int s)
{
    int i;
    col[s]=1;
    for(i=1; i<=n; i++)
        if (g[s][i])
        {
            if (col[i] && par[s]!=i) 
            {g[s][i]=g[i][s]=0; return 1;}
            else if (!col[i]) {par[i]=s; if (dfs(i)) return 1;}
        }
    return 0;
}

int main()
{
    int i, a, b, m;
    scanf("%d %d", &n, &m);
    if (n!=m) {printf("NO"); return 0;}
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b]=g[b][a]=1;
    }
    for(i=1; i<=n; i++) par[i]=-1;
    if (!dfs(1)) 
    {printf("NO"); return 0;}
    for(i=1; i<=n; i++) {col[i]=0; par[i]=-1;}
    if (dfs(1)) 
    {printf("NO"); return 0;}
    for(i=1; i<=n; i++) if (!col[i])  
    {printf("NO"); return 0;}
    printf("FHTAGN!");
}