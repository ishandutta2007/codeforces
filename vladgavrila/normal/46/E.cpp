#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define maxn 1510

int n, m, x;
long long crmax;
long long v[maxn][maxn], d[2][maxn];

int main()
{
 //   freopen("e.in", "r", stdin);
 //   freopen("e.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            scanf("%d", &x);
            v[i][j]=x+v[i][j-1];
        }
    }

    for(int i=1; i<=m; ++i)
        d[0][i]=v[1][i];

    for(int i=2; i<=n; ++i)
    {
        crmax=-1LL*1000000000*1000000000;
        if(i%2==1)
        {
            for(int j=1; j<=m; ++j)
            {
                if(j==1)
                    d[1][j]=crmax;
                else
                    d[1][j]=crmax+v[i][j];
                crmax=max(crmax, d[0][j]);
            }
        }
        else
        {
            for(int j=m; j; --j)
            {
                if(j==m)
                    d[1][j]=crmax;
                else
                    d[1][j]=crmax+v[i][j];
                crmax=max(crmax, d[0][j]);
            }
        }
        for(int j=1; j<=m; ++j)
            d[0][j]=d[1][j];
    }

    crmax=-1LL*1000000000*1000000000;
    for(int j=1; j<=m; ++j)
        crmax=max(crmax, d[0][j]);

    cout<<crmax<<"\n";

    return 0;
}