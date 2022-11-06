#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

#define maxn 1010

int n, i, j, k, sol;
int v[maxn], f[maxn];
set<int> g;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &k);
        f[k]++;
        sol=max(sol, f[k]);
        g.insert(k);
    }
    printf("%d %d\n", sol, g.size());
    return 0;
}