#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> b(n, vector<int>(2 * k));
    function<void(int, int)> dfs = [&](int v, int p) {
        b[v][0] ^= a[v];
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
            for (int i = 0; i < 2 * k; i++) {
                b[v][(i + 1) % (2 * k)] ^= b[to][i];
            }
        }
    };
    dfs(0, -1);
    vector<int> ans(n);
    function<void(int, int)> reroot = [&](int v, int p) {
        int c = 0;
        for (int i = k; i < 2 * k; i++) {
            c ^= b[v][i];
        }
        ans[v] = !!c;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            vector<int> bv = b[v];
            vector<int> bto = b[to];
            for (int i = 0; i < 2 * k; i++) {
                b[v][(i + 1) % (2 * k)] ^= b[to][i];
            }
            for (int i = 0; i < 2 * k; i++) {
                b[to][(i + 1) % (2 * k)] ^= b[v][i];
            }
            reroot(to, v);
            b[v] = bv;
            b[to] = bto;
        }
    };
    reroot(0, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}