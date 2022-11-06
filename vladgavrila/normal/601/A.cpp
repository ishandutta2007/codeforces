#include <cstdio>

using namespace std;

#define maxn 410

int n, m, q0;
int v[maxn][maxn];
int q[maxn], d[maxn], f[maxn];

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<=m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a][b]=v[b][a]=1;
    }

    if(v[1][n]==1)
    {
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(i!=j)
                    v[i][j]=1-v[i][j];
    }

    q[++q0]=1;
    f[1]=1;

    for(int i=1; i<=q0; ++i)
    {
        int nod = q[i];

        for(int j=1; j<=n; ++j)
        {
            if(v[nod][j]==1 && f[j]==0)
            {
                f[j]=1;
                d[j]=d[nod]+1;
                q[++q0]=j;
            }
        }
    }

    if(f[n]==0)
        printf("%d\n", -1);
    else
        printf("%d\n", d[n]);


    return 0;
}