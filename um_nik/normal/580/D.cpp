#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int N = 19;
const int M = 1 << N;
ll a[N];
ll dp[M][N];
ll g[N][N];
int n, m;

void read()
{
    int k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while(k--)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        scanf("%lld", &g[v][u]);
    }
    return;
}

int main()
{
    read();
    for (int mask = 0; mask < (1 << n) - 1; mask++)
        for (int x = 0; x < n; x++)
        {
            if (((mask >> x) & 1) == 0) continue;
            for (int y = 0; y < n; y++)
            {
                if ((mask >> y) & 1) continue;
                dp[mask | (1 << y)][y] = max(dp[mask | (1 << y)][y], dp[mask][x] + g[x][y]);
            }
        }
    ll ans = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int cnt = 0;
        for (int k = 0; k < n; k++)
            if ((mask >> k) & 1)
                cnt++;
        if (cnt != m) continue;
        ll s = 0;
        for (int i = 0; i < n; i++)
            s = max(s, dp[mask][i]);
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                s += a[i];
        ans = max(ans, s);
    }
    printf("%lld\n", ans);

    return 0;
}