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
    /*
    int m;
    cin >> m;
    vector<int> p(m);
    iota(p.begin(), p.end(), 0);
    cout << (m - 1) * (m) * (2 * m - 1) / 6 << '\n';
    int mx = 0;
    vector<int> d;
    do {
        vector<int> q(m);
        iota(q.begin(), q.end(), 0);
        int res = 0;
        do {
            vector<int> a = p;
            int t = 0;
            for (int i : q) {
                for (int j = 0; j < m; j++) {
                    if (i == a[j]) {
                        swap(a[i], a[j]);
                        t += (i - j) * (i - j);
                    }
                }
            }
            res = max(res, t);
        } while (next_permutation(q.begin(), q.end()));
        // debug(p, res);
        if (res > mx) {
            mx = res;
            d = p;
        }
    } while (next_permutation(p.begin(), p.end()));
    debug(mx, d);
    */
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        vector<pair<int, int>> q;
        long long a = 0;
        auto sw = [&](int i, int j) {
            swap(p[i], p[j]);
            q.emplace_back(i, j);
            a += 1LL * (i - j) * (i - j);
        };
        sw(0, n - 1);
        for (int i = 1; i < (n + 1) / 2; i++) {
            sw(i, n - 1);
        }
        for (int i = (n + 1) / 2; i < n - 1; i++) {
            sw(i, 0);
        }
        reverse(q.begin(), q.end());
        cout << a << '\n';
        for (int i : p) {
            cout << i + 1 << " ";
        }
        cout << '\n';
        cout << q.size() << '\n';
        for (auto [i, j] : q) {
            assert(p[j] == i);
            swap(p[i], p[j]);
            cout << i + 1 << " " << j + 1 << '\n';
        }
        assert(!prev_permutation(p.begin(), p.end()));
    }
    return 0;
}