#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 1e5+5;

double f[maxn][15];
int sel[maxn][15];

ll a[maxn];

int ans[maxn] , cnt;

int main()
{

    int n,d; scanf("%d%d",&n,&d);

    for(int i=0;i<=n;++i) for(int j=0;j<=9;++j) f[i][j] = -1;

    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);

    for(int i=1;i<=n;++i) for(int j=0;j<=9;++j)
    {
        if( a[i] % 10 == j ) f[i][j] = log( a[i] ) , sel[i][j] = -1;

        if( i == 1 ) continue;

        if( f[i-1][j]!=-1 && f[i-1][j] > f[i][j] )
        {
            f[i][j] = f[i-1][j];
            sel[i][j] = -2;
        }

        for(int k=0;k<=9;++k) if( k * a[i] % 10 == j )
        {
            if( f[i-1][k] == -1 ) continue;
            if( f[i-1][k] + log( a[i] ) > f[i][j] )
            {
                f[i][j] = f[i-1][k] + log( a[i] );
                sel[i][j] = k;
            }
        }
    }

    if(f[n][d]==-1)
    {
        printf("-1");
        return 0;
    }

    cnt = 0; int now = d;
    for(int i=n;i>=1;--i)
    {
        if(sel[i][now]==-1)
        {
            ans[++cnt] = a[i];
            break;
        }
        else if(sel[i][now]==-2)
        {
            continue;
        }
        else
        {
            ans[++cnt] = a[i];
            now = sel[i][now];
            continue;
        }
    }

    printf("%d\n",cnt);
    for(int i=1;i<=cnt;++i) printf("%d ",ans[i]);
    return 0;
}
/*
6 4
4 11 8 2 1 13

3 1
2 4 6

5 7
1 3 1 5 3


6 3
8 9 4 17 11 5

5 6
2 2 2 2 2

3 0
1 1 1

*/