#include <stdio.h>

int g[101][101];

int main()
{
    int i, j, k, a, b, n, m, cc[101], min=1000000000;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) scanf("%d", &cc[i+1]);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b]=g[b][a]=1;
    }
    for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
            if (g[i][j])
                for(k=j+1; k<=n; k++)
                    if (g[i][k] && g[j][k] && cc[i]+cc[j]+cc[k]<min) min=cc[i]+cc[j]+cc[k];
    if (min==1000000000) printf("-1");
    else printf("%d", min);
                
}