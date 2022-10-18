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
    int n;
    cin >> n;
    // n = f[26];
    vector<vector<int>> g(n);
    vector<int> e(n - 1);
    vector<int> f(30);
    f[0] = f[1] = 1;
    for (int i = 2; i < 30; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    debug(f);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(i);
        g[y].emplace_back(i);
        e[i] = x ^ y;
    }
    if (!binary_search(f.begin(), f.end(), n)) {
        cout << "NO" << '\n';
        return 0;
    }
    vector<vector<int>> sz(30, vector<int>(n));
    vector<vector<int>> pe(30, vector<int>(n, -1));
    int z;
    function<bool(int, int, int)> eval = [&](int v, int p, int k) {
        if (k <= 2) {
            return true;
        }
        vector<int> was;
        function<void(int, int)> dfs = [&](int vv, int pp) {
            was.emplace_back(vv);
            sz[z - k][vv] = 1;
            for (int id : g[vv]) {
                if (e[id] == -1 || (e[id] ^ vv) == pp) {
                    continue;
                }
                int to = e[id] ^ vv;
                pe[z - k][to] = id;
                dfs(to, vv);
                sz[z - k][vv] += sz[z - k][to];
            }
        };
        dfs(v, p);
        bool res = false;
        for (int i : was) {
            if (pe[z - k][i] == -1) {
                sz[z - k][i] = 0;
                debug(k, i);
                continue;
            }
            int pv = e[pe[z - k][i]] ^ i;
            int te = e[pe[z - k][i]];
            e[pe[z - k][i]] = -1;
            if (sz[z - k][i] == f[k - 1]) {
                res |= eval(i, pv, k - 1) && eval(pv, i, k - 2);
                e[pe[z - k][i]] = te;
                break;
            } else if (sz[z - k][i] == f[k - 2]) {
                res |= eval(i, pv, k - 2) && eval(pv, i, k - 1);
                e[pe[z - k][i]] = te;
                break;
            }
            e[pe[z - k][i]] = te;
        }
        return res;
    };
    string ans = "NO";
    for (int i = 0; i < 30; i++) {
        if (f[i] == n) {
            z = i;
            if (eval(0, -1, i)) {
                ans = "YES";
            }
        }
    }
    cout << ans << '\n';
    return 0;
}