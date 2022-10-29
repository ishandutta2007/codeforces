#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5 + 5;
const LL INF = 1e10;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, x, y, h[N];
bool leaf[N];
LL dp[N][2];
vector<int> g[N];

void dfs1(int x, int fa) {
    for (auto u : g[x])
        if (u != fa) {
            dfs1(u, x);
            leaf[x] = false, h[x] = max(h[x], h[u]);
        }
}

void dfs2(int x, int fa) {
    if (leaf[x]) {
        dp[x][0] = INF, dp[x][1] = h[x];
        return;
    }
    int ma1 = 0, ma2 = 0;
    for (auto u : g[x])
        if (u != fa) {
            if (h[u] >= ma1)
                ma2 = ma1, ma1 = h[u];
            else if (h[u] >= ma2)
                ma2 = h[u];
        }
    dp[x][1] = h[x] - ma1, dp[x][0] = dp[x][1] + h[x] - ma2;

    for (auto u : g[x])
        if (u != fa) {
            dfs2(u, x);
            dp[x][0] += min(dp[u][0], dp[u][1]);
            dp[x][1] += min(dp[u][0], dp[u][1]);
        }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> h[i];
    rep(i, 1, n - 1) cin >> x >> y, g[x].PB(y), g[y].PB(x);
    memset(leaf, true, sizeof leaf);
    int rt;
    rep(i, 1, n) if (h[i] > h[rt]) rt = i;
    dfs1(rt, 0);
    dfs2(rt, 0);
    cout << dp[rt][0];
    return 0;
}