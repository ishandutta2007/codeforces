#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int c[maxn];

void dfs(int now, int fa) {
    int ind = 1;
    for (int u : G[now]) if (u != fa) {
        while (ind == c[now] || ind == c[fa]) ++ind;
        c[u] = ind; ++ind; 
        dfs(u, now);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    c[1] = 1;
    dfs(1, 0);
    int ans = 1;
    for (int i = 1; i <= n; ++i) ans = max(ans, c[i]);
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) cout << c[i] << ' '; cout << endl;
    return 0;
}