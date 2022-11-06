#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 110

int n, i, sw, j, k, m, nr;
int v[maxn][maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    if(n>m)
    {
        swap(n, m);
        sw=1;
    }
    if((n==1) && (m==2) || (n==2 && m==2) || (n==1 && m==3))
    {
        printf("-1\n");
        return 0;
    }
    if(n==3 && m==3)
    {
        printf("1 4 7\n");
        printf("9 2 5\n");
        printf("6 8 3\n");
        return 0;
    }
    if(m%2==1)
    {
        for(int i=1+n%2; i<=n; i+=2)
        {
            for(int j=1; j<=m; ++j)
            {
                ++nr;
                v[i+(j-1)%2][j]=nr;
            }
            for(int j=1; j<=m; ++j)
            {
                ++nr;
                v[i+j%2][j]=nr;
            }
        }
        if(n%2==1)
        {
            for(int i=2; i<=m; i+=2)
            {
                ++nr;
                v[1][i]=nr;
            }
            for(int i=1; i<=m; i+=2)
            {
                ++nr;
                v[1][i]=nr;
            }
        }
    }
    else
    {
        for(int i=1; i<n; i+=2)
        {
            for(int j=1; j<=m; ++j)
            {
                ++nr;
                v[i+(j-1)%2][j]=nr;
            }
            for(int j=1; j<=m; ++j)
            {
                ++nr;
                v[i+j%2][j]=nr;
            }
        }
        if(n%2==1)
        {
            for(int i=2; i<=m; i+=2)
            {
                ++nr;
                v[n][i]=nr;
            }
            for(int i=1; i<=m; i+=2)
            {
                ++nr;
                v[n][i]=nr;
            }
        }
    }
    if(sw==0)
    {
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                printf("%d ", v[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                printf("%d ", v[j][i]);
            }
            printf("\n");
        }
    }
    return 0;
}