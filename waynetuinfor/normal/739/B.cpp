#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, lg = 20;
vector<pair<int, int>> G[maxn];
long long a[maxn], dis[maxn], p[lg][maxn], ans[maxn], cnt[maxn];

void dfs(int, int, long long);
int dfs2(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        int p, w; cin >> p >> w;
        G[p].push_back(make_pair(i, w));
    }
    dfs(1, 0, 0); dfs2(1, 0);
    for (int i = 1; i <= n; ++i) cout << cnt[i] << ' '; cout << endl;
    return 0;
}

void dfs(int x, int fa, long long w) {
    p[0][x] = fa; dis[x] = w;
    for (int k = 1; k < lg; ++k) {
        p[k][x] = p[k - 1][p[k - 1][x]];
    }
    for (auto u : G[x]) if (u.first != fa) dfs(u.first, x, w + u.second);
    int cur = x;
    for (int k = lg - 1; k >= 0; --k) {
        if (!p[k][cur]) continue;
        if (dis[x] - a[x] <= dis[p[k][cur]]) cur = p[k][cur];
    }
    // cout << "x = " << x << " cur = " << cur << endl;
    ++ans[p[0][x]]; --ans[p[0][cur]];
}

int dfs2(int x, int fa) {
    int t = ans[x];
    for (auto u : G[x]) if (u.first != fa) {
        t += dfs2(u.first, x);
    }
    cnt[x] = t;
    return t;
}