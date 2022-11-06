#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1000101
#define inf 2000000000

int n, m, k;
int a[maxn], b[maxn], c[maxn], f[maxn];
int sol;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for(int i=1; i<=k; ++i)
    {
        int x;
        scanf("%d", &x);
        f[x]=1;
    }

    sol=inf;

    for(int i=1; i<=m; ++i)
        if(f[a[i]]+f[b[i]]==1)
            sol=min(sol, c[i]);

    if(sol==inf)
        sol=-1;

    printf("%d\n", sol);

    return 0;
}