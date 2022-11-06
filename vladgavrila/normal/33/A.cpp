#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 1010

int n, m, i, j, k, rd, rez, sol, r[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for(i=1; i<=m; ++i)
        r[i]=1000000000;
    for(i=1; i<=n; ++i)
    {
        scanf("%d%d", &rd, &rez);
        r[rd]=min(r[rd], rez);
    }
    for(i=1; i<=m; ++i)
        sol+=r[i];
    sol=min(sol, k);
    printf("%d\n", sol);
    return 0;
}