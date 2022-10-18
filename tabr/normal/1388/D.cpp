#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] > 0) {
            b[i]--;
            g[i].emplace_back(b[i]);
            g[b[i]].emplace_back(i);
        }
    }
    vector<int> order;
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
            if (a[to] > 0) {
                a[v] += a[to];
            }
        }
    };
    function<void(int, int)> dfs2 = [&](int v, int p) {
        sort(g[v].begin(), g[v].end(), [&](int i, int j) {
            return a[i] > a[j];
        });
        bool done = false;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (!done && a[to] < 0) {
                order.emplace_back(v);
                done = true;
            }
            dfs2(to, v);
        }
        if (!done) {
            order.emplace_back(v);
        }
    };
    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            dfs(i, -1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            dfs2(i, -1);
        }
    }
    cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
    for (int i : order) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}