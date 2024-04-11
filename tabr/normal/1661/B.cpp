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
    const int n = 32768;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        g[(i + 1) % n].emplace_back(i);
        g[2 * i % n].emplace_back(i);
    }
    vector<int> d(n, -1);
    d[0] = 0;
    queue<int> que;
    que.emplace(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int to : g[v]) {
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                que.emplace(to);
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int a;
        cin >> a;
        cout << d[a] << '\n';
    }
    return 0;
}