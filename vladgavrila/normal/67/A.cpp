#include <stdio.h>

using namespace std;

#define maxn 1020
#define inf 1000000000

int n, i, j, k, mn;
char s[maxn];
int sol[maxn], d[maxn][maxn], st[maxn][maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    scanf("%s", s+2);

    for(int i=1; i<=n+1; ++i)
        d[1][i]=i;
    d[1][0]=d[1][n+1]=inf;

    for(int i=2; i<=n; ++i)
    {
        d[i][n+1]=inf;
        d[i][0]=inf;
        if(s[i]=='L')
        {
            mn=n+1;
            for(int j=n; j; --j)
            {
                d[i][j]=j+d[i-1][mn];
                st[i][j]=mn;
                if(d[i-1][j]<d[i-1][mn])
                    mn=j;
            }
        }
        else
        if(s[i]=='R')
        {
            mn=0;
            for(int j=1; j<=n; ++j)
            {
                d[i][j]=j+d[i-1][mn];
                st[i][j]=mn;
                if(d[i-1][j]<d[i-1][mn])
                    mn=j;
            }
        }
        else
        {
            for(int j=1; j<=n; ++j)
            {
                st[i][j]=j;
                d[i][j]=d[i-1][j]+j;
            }
        }
    }

    mn=0;
    for(int i=1; i<=n; ++i)
    {
        if(d[n][mn]>d[n][i])
            mn=i;
    }
    for(int i=n; i>=1; --i)
    {
        sol[i]=mn;
        mn=st[i][mn];
    }
    for(int i=1; i<=n; ++i)
    {
        printf("%d ", sol[i]);
    }
    printf("\n");
    return 0;
}