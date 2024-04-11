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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        cout << "? " << n << " ";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
        int r0, d, r1;
        cin >> r0 >> d;
        r0--;
        r1 = r0;
        vector<int> depth(n), pv(n, -1), ch(n);
        function<void(int)> dfs = [&](int v) {
            for (int to : g[v]) {
                if (to == pv[v]) {
                    continue;
                }
                depth[to] = depth[v] + 1;
                pv[to] = v;
                ch[to] = ch[v];
                dfs(to);
            }
        };
        int cur = 0;
        while (cur < d) {
            depth = ch = vector<int>(n, -1);
            depth[r0] = depth[r1] = 0;
            ch[r0] = r0;
            ch[r1] = r1;
            dfs(r0);
            dfs(r1);
            vector<int> a;
            int x = (d - cur + 1) / 2;
            for (int i = 0; i < n; i++) {
                if (depth[i] == x) {
                    a.emplace_back(i + 1);
                }
            }
            cout << "? " << a.size() << " ";
            for (int i : a) {
                cout << i << " ";
            }
            cout << endl;
            int y;
            cin >> x >> y;
            x--;
            if (ch[x] == r1) {
                r1 = x;
            } else {
                r0 = x;
            }
            if (cur == 0) {
                int z = r1;
                while (pv[z] != r0) {
                    z = pv[z];
                }
                pv[r0] = z;
            }
            cur += (d - cur + 1) / 2;
        }
        cout << "! " << r0 + 1 << " " << r1 + 1 << endl;
        string b;
        cin >> b;
    }
    return 0;
}