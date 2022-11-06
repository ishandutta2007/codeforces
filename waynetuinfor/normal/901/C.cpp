#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
vector<int> G[maxn], bcc[maxn];
int tin[maxn], low[maxn], t, c, to[maxn], prv[maxn];
long long sum[maxn], sumd[maxn];
stack<int> stk;

void dfs(int now, int fa) {
    tin[now] = low[now] = ++t;
    stk.push(now);
    for (int u : G[now]) if (u != fa) {
        if (tin[u]) {
            low[now] = min(low[now], tin[u]);
            continue;
        }
        dfs(u, now);
        low[now] = min(low[now], low[u]);
        if (low[u] > tin[now]) {
            ++c;
            while (true) {
                int v = stk.top(); stk.pop();
                bcc[c].push_back(v);
                if (v == u) break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!tin[i]) {
        dfs(i, 0);
        if (stk.size()) {
            ++c;
            while (stk.size()) bcc[c].push_back(stk.top()), stk.pop();
        }
    }
    vector<pair<int, int>> forb;
    for (int i = 1; i <= c; ++i) {
        sort(bcc[i].begin(), bcc[i].end());
        if (bcc[i].size() > 1) forb.emplace_back(bcc[i].front(), bcc[i].back());
    }
    sort(forb.begin(), forb.end());
    fill(to, to + maxn, n);
    for (int i = 0; i < forb.size(); ++i) to[forb[i].first] = min(to[forb[i].first], forb[i].second - 1);
    for (int i = n - 1; i > 0; --i) to[i] = min(to[i], to[i + 1]), to[i] = max(to[i], i - 1);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + to[i];
    for (int i = 1; i <= n; ++i) sumd[i] = sumd[i - 1] + i;
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int p = upper_bound(to + l, to + r + 1, r) - to;
        long long ans = sum[p - 1] - sum[l - 1];
        ans += (r - p + 1) * 1ll * r;
        ans -= sumd[r] - sumd[l - 1] - (r - l + 1);
        cout << ans << endl;
    }
    return 0;
}