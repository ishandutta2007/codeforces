#include<stdio.h>
int dat[6][1001];
int loc[6][1001];
int d[1001];
int main()
{
    int n, k, i, j, l;
    scanf("%d%d", &n, &k);
    for(i=1; i<=k; i++)for(j=1; j<=n; j++)
    {
        scanf("%d", &dat[i][j]);
        loc[i][dat[i][j]] = j;
    }
    for(i=1; i<=n; i++)
    {
        int t = dat[1][i];
        int max = 0;
        for(j=1; j<=n; j++)
        {
            for(l=1; l<=k; l++)
            {
                if(loc[l][j] >= loc[l][t]) break;
            }
            if(l!=k+1) continue;
            if(max < d[j]) max = d[j];
        }
        d[t] = max+1;
    }
    int max = 0;
    for(i=1; i<=n; i++) if(d[i] > max) max = d[i];
    printf("%d", max);
    return 0;
}