#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
bool pt[maxn];
int dp[2][maxn], sz[maxn], dep[maxn], p[20][maxn], n, m, d, t[2][maxn], ans, ts, tin[maxn], tout[maxn];

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

void dfs1(int now, int fa) {
    dp[0][now] = dp[1][now] = (pt[now] ? 0 : -1);
    tin[now] = ++ts;
    for (int u : G[now]) if (u != fa) {
        dfs1(u, now);
        if (dp[0][u] == -1) continue;
        if (dp[0][now] < dp[0][u] + 1) {
            dp[1][now] = dp[0][now]; t[1][now] = t[0][now];
            dp[0][now] = dp[0][u] + 1; t[0][now] = u;
        } else if (dp[1][now] < dp[0][u] + 1) {
            dp[1][now] = dp[0][u] + 1;
            t[1][now] = u;
        }
    }
    tout[now] = ts;
}

void dfs2(int now, int fa, int dis) {
    dp[1][now] = max(dp[1][now], dis); dp[0][now] = max(dp[0][now], dis);
    if (dp[0][now] <= d && dis <= d) ++ans;
    for (int u : G[now]) if (u != fa) {
        if (anc(t[0][now], u)) dfs2(u, now, (dp[1][now] == -1 ? -1 : dp[1][now] + 1));
        else dfs2(u, now, (dp[0][now] == -1 ? -1 : dp[0][now] + 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        pt[x] = true;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    dfs1(1, 0);  dfs2(1, 0, -1);
    cout << ans << endl;
    return 0;
}