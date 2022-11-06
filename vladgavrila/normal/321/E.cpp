#include <cstdio>

using namespace std;

#define maxn 4010
#define maxk 810
#define inf 1000000000

int n, k;
int v[maxn][maxn], cost[maxn][maxn], d[maxk][maxn];
char s[3*maxn];

void compute(int lvl, int left, int right, int qleft, int qright)
{
    int sol=inf, bst=0, med=(left+right)/2;

    for(int i=qleft; i<=qright && i<med; ++i)
        if(d[lvl-1][i]+cost[i+1][med]<sol)
        {
            sol=d[lvl-1][i]+cost[i+1][med];
            bst=i;
        }

    d[lvl][med]=sol;

    if(left==right)
        return;

    compute(lvl, left, med, qleft, bst);
    compute(lvl, med+1, right, bst, qright);
}

int main()
{
   // freopen("e.in", "r", stdin);
   // freopen("e.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            scanf("%d", &v[i][j]);
            v[i][j]+=v[i][j-1];
        }
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            v[i][j]+=v[i-1][j];

    for(int i=1; i<=n; ++i)
        for(int j=i; j<=n; ++j)
            cost[i][j]=(v[i-1][i-1]+v[j][j]-v[i-1][j]-v[j][i-1])/2;

    for(int i=1; i<=n; ++i)
        d[0][i]=inf;

    for(int i=1; i<=k; ++i)
    {
        d[i][0]=inf;
        compute(i, 1, n, 0, n);
    }

    printf("%d\n", d[k][n]);

    return 0;
}