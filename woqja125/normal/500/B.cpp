#include<stdio.h>
int p[301], ans[301];
int l[301];
int M[301][301];
int v[301], c[301];
int n;
void dfs(int x, int N)
{
    v[x] = N;
    for(int i=1; i<=n; i++)
    {
        if(v[i] == 0 && M[x][i] == 1) dfs(i, N);
    }
}
int main()
{
    int i, j, C = 0;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", p+i);
        l[p[i]] = i;
    }
    for(i=1; i<=n; i++)for(j=1; j<=n; j++)scanf("%1d", &M[i][j]);
    for(i=1; i<=n; i++)
    {
        if(v[i] == 0) dfs(i, ++C);
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(c[j]) continue;
            if(v[i] != v[l[j]]) continue;
            c[j] = 1;
            ans[i] = j;
            break;
        }
        printf("%d ", ans[i]);
    }
    return 0;
}