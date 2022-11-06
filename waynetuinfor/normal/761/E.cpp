#include <bits/stdc++.h>
using namespace std;

const int maxn = 30 + 10;
const int dx[4] = { 1, 0, 0, -1 }, dy[4] = { 0, 1, -1, 0 };
vector<int> G[maxn];
pair<long long, long long> ans[maxn];

void dfs(int now, int fa, int d, int prv) {
    size_t ptr = 0;
    for (int u : G[now]) if (u != fa) {
        if (prv != -1 && ptr == 3 - prv)  ++ptr;
        ans[u] = make_pair(ans[now].first + dx[ptr] * (1ll << d), ans[now].second + dy[ptr] * (1ll << d));
        dfs(u, now, d - 1, ptr);
        ++ptr;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (G[i].size() > 4) return cout << "NO" << endl, 0;
    }
    cout << "YES" << endl;
    ans[1] = make_pair(0, 0);
    dfs(1, 0, n + 1, -1);
    for (int i = 1; i <= n; ++i) cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}