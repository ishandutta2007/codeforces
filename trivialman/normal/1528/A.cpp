#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, x, y;
int l[N], r[N];
vector<int> g[N];
LL dp[N][2];

void dfs(int x, int fa) {
    dp[x][0] = dp[x][1] = 0;
    for (int u : g[x])
        if (u != fa) {
            dfs(u,x);
            dp[x][0] += max(dp[u][0] + abs(l[x] - l[u]), dp[u][1] + abs(l[x] - r[u]));
            dp[x][1] += max(dp[u][0] + abs(r[x] - l[u]), dp[u][1] + abs(r[x] - r[u]));
        }
}

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n) g[i].clear();

        rep(i, 1, n) scanf("%d%d", l + i, r + i);
        rep(i, 1, n - 1) {
            scanf("%d%d", &x, &y);
            g[x].PB(y), g[y].PB(x);
        }

        dfs(1, 0);
        printf("%lld\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}