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
    int n, m;
    cin >> n >> m;
    int sq = ceill(sqrtl(n));
    vector<vector<int>> g(n);
    vector<int> dep(n, -1), par(n, -1);
    vector<bool> dsu(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    function<void(int)> dfs = [&](int v) {
        vector<int> bk;
        for (int to : g[v]) {
            if (dep[to] == -1) {
                par[to] = v;
                dep[to] = dep[v] + 1;
                dfs(to);
            } else {
                bk.emplace_back(to);
            }
        }
        if (bk.size() >= sq - 1) {
            int ed, tmp = 0;
            for (int to : bk) {
                if (tmp < dep[v] - dep[to]) {
                    ed = to;
                    tmp = dep[v] - dep[to];
                }
            }
            vector<int> res;
            tmp = v;
            while (tmp != ed) {
                res.emplace_back(tmp);
                tmp = par[tmp];
            }
            res.emplace_back(ed);
            cout << 2 << endl;
            cout << res.size() << endl;
            for (int val : res) {
                cout << val + 1 << " ";
            }
            cout << endl;
            exit(0);
        } else {
            bool ok = true;
            for (int to : g[v]) {
                if (dsu[to]) {
                    ok = false;
                }
            }
            if (ok) {
                dsu[v] = true;
            }
        }
    };
    dep[0] = 0;
    dfs(0);
    cout << 1 << endl;
    for (int i = 0, cnt = 0; i < n && cnt < sq; i++) {
        if (dsu[i]) {
            cout << i + 1 << " ";
            cnt++;
        }
    }
    cout << endl;
    return 0;
}