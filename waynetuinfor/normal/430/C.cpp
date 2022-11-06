#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn], ans;
int a[maxn], b[maxn];

void dfs(int now, int fa, vector<int> tag, vector<bool> mod, int dep) {
    if (mod[dep & 1]) a[now] ^= tag[dep & 1];
    // if (mod[dep & 1 ^ 1]) a[now] ^= tag[dep & 1 ^ 1] ^ 1;
    // cout << "now = " << now << endl;
    // for (int i = 0; i < 2; ++i) cout << tag[i] << ' '; cout << endl;
    // for (int i = 0; i < 2; ++i) cout << mod[i] << ' '; cout << endl;
    if (a[now] != b[now]) mod[dep & 1] = true, tag[dep & 1] ^= 1, ans.push_back(now);
    for (int u : G[now]) if (u != fa) dfs(u, now, tag, mod, dep + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    dfs(1, 0, { 0, 0 }, { false, false }, 0);
    cout << ans.size() << endl;
    for (int i : ans) cout << i << endl;
    return 0;
}