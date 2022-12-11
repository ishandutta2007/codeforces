#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 2e5 + 7;
set <int, greater<int>> g[N];

bool is_good(int x) {
    return ((*g[x].begin()) == x);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].insert(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((*g[i].begin()) == i)
            ans++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 3) {
            cout << ans << "\n"; 
        } else {
            int u, v;
            cin >> u >> v;
            ans -= is_good(u);
            ans -= is_good(v);
            if (t == 1) {
                g[u].insert(v);
                g[v].insert(u);
            } else {
                g[u].erase(v);
                g[v].erase(u);
            }
            ans += is_good(u);
            ans += is_good(v);
        }
    }
    return 0;
}