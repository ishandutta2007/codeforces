#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 10;
vector<int> G[maxn];

long long c2(int n) { return n * 1ll * (n - 1) / 2; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m; while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> deg(maxn);
        for (int j : G[i]) {
            for (int u : G[j]) ++deg[u];
        }
        for (int j = 1; j <= n; ++j) {
            if (i != j) ans += c2(deg[j]);
        }
    }
    cout << ans << endl;
    return 0;
}