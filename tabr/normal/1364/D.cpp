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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    queue<int> que;
    vector<bool> was(n);
    vector<int> depth(n, -1);
    vector<int> p(n, -1);
    vector<int> col(n, -1);
    que.emplace(0);
    depth[0] = 0;
    was[0] = true;
    col[0] = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int to : g[v]) {
            if (depth[to] != -1) {
                if (p[v] == to) {
                    continue;
                }
                vector<int> x, y;
                while (v != -1) {
                    x.emplace_back(v);
                    v = p[v];
                }
                while (to != -1) {
                    y.emplace_back(to);
                    to = p[to];
                }
                int lst = -1;
                while (x.size() && y.size() && x.back() == y.back()) {
                    lst = x.back();
                    x.pop_back();
                    y.pop_back();
                }
                x.emplace_back(lst);
                x.insert(x.end(), y.rbegin(), y.rend());
                if (x.size() <= k) {
                    cout << 2 << '\n';
                    cout << x.size() << '\n';
                    for (int i : x) {
                        cout << i + 1 << " ";
                    }
                    cout << '\n';
                } else {
                    cout << 1 << '\n';
                    for (int i = 0; i < (k + 1) / 2; i++) {
                        cout << x[i * 2] + 1 << " ";
                    }
                    cout << '\n';
                }
                return 0;
            }
            p[to] = v;
            col[to] = 1 ^ col[v];
            depth[to] = depth[v] + 1;
            que.emplace(to);
        }
    }
    int c1 = accumulate(col.begin(), col.end(), 0);
    if (c1 < (k + 1) / 2) {
        for (int &i : col) {
            i = 1 ^ i;
        }
    }
    cout << 1 << '\n';
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (col[i] == 1 && cnt < (k + 1) / 2) {
            cout << i + 1 << " ";
            cnt++;
        }
    }
    return 0;
}