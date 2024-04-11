#include <stdio.h>
#include <iostream>

using namespace std;

#define maxn 110
#define inf (1LL*1000000000*1000000000)

int n, m, k;
int c[maxn];
int p[maxn][maxn];
long long d[maxn][maxn][maxn];

int main()
{
    cin>>n>>m>>k;
    for(int i=1; i<=n; ++i)
        cin>>c[i];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            cin>>p[i][j];

    for(int i=0; i<=n; ++i)
        for(int j=0; j<=k; ++j)
            for(int l=0; l<=m; ++l)
                d[i][j][l]=inf;

    d[0][0][0]=0;

    for(int i=1; i<=n; ++i)
    {
        if(c[i]==0)
        {
            for(int j=1; j<=k; ++j)
                for(int cc=1; cc<=m; ++cc)
                    for(int pc=0; pc<=m; ++pc)
                    {
                        if(cc==pc)
                            d[i][j][cc]=min(d[i][j][cc], d[i-1][j][pc]+p[i][cc]);
                        else
                            d[i][j][cc]=min(d[i][j][cc], d[i-1][j-1][pc]+p[i][cc]);
                    }
        }
        else
        {
            int cc=c[i];
            for(int j=1; j<=k; ++j)
                for(int pc=0; pc<=m; ++pc)
                    if(pc==c[i])
                        d[i][j][cc]=min(d[i][j][cc], d[i-1][j][pc]);
                    else
                        d[i][j][cc]=min(d[i][j][cc], d[i-1][j-1][pc]);
        }
    }

    long long sol=inf;
    for(int cc=1; cc<=m; ++cc)
        sol=min(sol, d[n][k][cc]);

    if(sol!=inf)
        cout<<sol<<"\n";
    else
        cout<<"-1\n";
    return 0;
}