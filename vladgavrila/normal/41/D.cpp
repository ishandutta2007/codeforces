#include <stdio.h>

using namespace std;

#define maxn 111

int n, m, i, j, k, poz, rest, sol;
int d[maxn][maxn][maxn], st[maxn][maxn][maxn];
char v[maxn][maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d\n", &n, &m, &k);
    ++k;
    for(int i=1; i<=n; ++i)
    {
        scanf("%s", v[i]+1);
        for(int j=1; j<=m; ++j)
            v[i][j]-='0';
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            for(int l=0; l<k; ++l)
                d[i][j][l]=-1;
    for(int i=1; i<=m; ++i)
        d[1][i][v[1][i]%k]=v[1][i];
    for(int i=1; i<n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            for(int l=0; l<k; ++l)
            {
                if(d[i][j][l]==-1)
                    continue;
                if(d[i+1][j+1][(l+v[i+1][j+1])%k]<d[i][j][l]+v[i+1][j+1])
                {
                    d[i+1][j+1][(l+v[i+1][j+1])%k]=d[i][j][l]+v[i+1][j+1];
                    st[i+1][j+1][(l+v[i+1][j+1])%k]=0;
                }
                if(d[i+1][j-1][(l+v[i+1][j-1])%k]<d[i][j][l]+v[i+1][j-1])
                {
                    d[i+1][j-1][(l+v[i+1][j-1])%k]=d[i][j][l]+v[i+1][j-1];
                    st[i+1][j-1][(l+v[i+1][j-1])%k]=1;
                }
            }
        }
    }
    sol=-1;
    for(int i=1; i<=m; ++i)
    {
        if(d[n][i][0]>sol)
        {
            sol=d[n][i][0];
            poz=i;
        }
    }
    if(sol==-1)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", sol);
    printf("%d\n", poz);
    rest=0;
    for(int i=1; i<n; ++i)
    {
        int nrest=(rest-v[n-i+1][poz]+10*k)%k;
        if(st[n-i+1][poz][rest]==0)
        {
            printf("L");
            poz--;
        }
        else
        {
            printf("R");
            poz++;
        }
        rest=nrest;
    }
    printf("\n");
    return 0;
}