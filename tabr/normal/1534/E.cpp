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
    auto ask = [&](vector<int> a) {
        cout << "?";
        for (int i : a) {
            cout << " " << i + 1;
        }
        cout << endl;
        int x;
#ifdef tabr
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        if ((int) a.size() != k) {
            debug(n, k, "NG");
        }
        // assert((int) a.size() == k);
        x = 1;
#else
        cin >> x;
#endif
        return x;
    };
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (k - j <= n - i) {
                debug(i, i + k - j * 2);
                g[i].emplace_back(i + k - j * 2);
            }
        }
    }
    queue<int> que;
    int inf = (int) 1e9;
    vector<int> d(n + 1, inf);
    que.emplace(0);
    d[0] = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int to : g[v]) {
            if (d[to] == inf) {
                d[to] = d[v] + 1;
                que.emplace(to);
            }
        }
    }
    if (d[n] == inf) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> a(1, n);
    while (a.back() != 0) {
        int v = a.back();
        for (int to = 0; to < n; to++) {
            bool ok = false;
            for (int from : g[to]) {
                if (from == v && d[to] == d[v] - 1) {
                    a.emplace_back(to);
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
            assert(to != n - 1);
        }
        debug(v);
    }
    int ans = 0;
    reverse(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i + 1 < (int) a.size(); i++) {
        int x = a[i], y = a[i + 1];
        int iflip = -1;
        for (int j = 0; j <= min(x, k); j++) {
            if (k - j <= n - x && y == x + k - j * 2) {
                iflip = j;
                break;
            }
        }
        assert(iflip != -1);
        vector<int> c, e;
        debug(x, y);
        // debug(iflip);
        // debug(b);
        for (int j = 0; j < n; j++) {
            if ((int) c.size() < iflip && b[j] == 1) {
                b[j] = 0;
                c.emplace_back(j);
            } else if ((int) e.size() < k - iflip && b[j] == 0) {
                b[j] = 1;
                e.emplace_back(j);
            }
        }
        c.insert(c.end(), e.begin(), e.end());
        // debug(b);
        ans ^= ask(c);
    }
    cout << "! " << ans << endl;
    return 0;
}