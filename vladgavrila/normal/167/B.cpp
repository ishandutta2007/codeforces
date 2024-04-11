#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 210

double sol, d[maxn][maxn][2*maxn];
int p[maxn];
int bags[maxn];
int n, k, l;

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d%d", &n, &l, &k);

    for(int i=1; i<=n; ++i)
        scanf("%d", &p[i]);
    for(int j=1; j<=n; ++j)
        scanf("%d", &bags[j]);

    d[0][0][min(n+k, 2*n)]=1.0;
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=i; ++j)
            for(int b=0; b<=2*n; ++b)
            {
                d[i+1][j+1][min(2*n, b+bags[i+1])]+=d[i][j][b]*p[i+1]/100;
                d[i+1][j][b]+=d[i][j][b]*(100-p[i+1])/100;
            }

    for(int j=l; j<=n; ++j)
        for(int b=n; b<=2*n; ++b)
            sol+=d[n][j][b];

    printf("%.6lf\n", sol);
    return 0;
}