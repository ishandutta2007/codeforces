#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int cnt[maxn];

void dfs(int now, int fa, int d) {
    ++cnt[d];
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0, 1);
    double ans = 0.0;
    for (int i = 1; i <= n; ++i) ans += (double)cnt[i] / (double)i;
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}