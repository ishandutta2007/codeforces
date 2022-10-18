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
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> g(n, vector<vector<int>>(2));
    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;
        g[y][t].emplace_back(x);
    }
    vector<vector<int>> d(n, vector<int>(2, n));
    d[n - 1][0] = 0;
    d[n - 1][1] = 0;
    queue<int> que;
    que.emplace(n - 1);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        int c = max(d[v][0], d[v][1]);
        for (int t = 0; t < 2; t++) {
            for (int to : g[v][t]) {
                if (d[to][t] < n) {
                    continue;
                }
                d[to][t] = c + 1;
                if (max(d[to][0], d[to][1]) < n) {
                    que.emplace(to);
                }
            }
        }
    }
    cout << (max(d[0][0], d[0][1]) != n ? max(d[0][0], d[0][1]) : -1) << '\n';
    for (int i = 0; i < n; i++) {
        cout << (d[i][0] < d[i][1] ? 1 : 0);
    }
    cout << '\n';
    return 0;
}