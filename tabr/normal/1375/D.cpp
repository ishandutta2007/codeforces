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
        vector<int> a(n);
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto mex = [&]() {
            vector<int> c(n + 1);
            for (int i = 0; i < n; i++) {
                c[a[i]]++;
            }
            for (int i = 0; i <= n; i++) {
                if (c[i] == 0) {
                    return i;
                }
            }
            return -1;
        };
        vector<int> x;
        // while (mex() != n) {
        //     int id = -1;
        //     int m = mex();
        //     for (int i = 0; i <= n; i++) {
        //         if (b[i] > 1 || (b[i] != 0 && i == n)) {
        //             for (int j = 0; j < n; j++) {
        //                 if (a[j] == i) {
        //                     id = j;
        //                     b[i]--;
        //                     break;
        //                 }
        //             }
        //             break;
        //         }
        //     }
        //     assert(id != -1);
        //     x.emplace_back(id);
        //     a[id] = m;
        //     b[m]++;
        // }
        for (int i = 0; i < n; i++) {
            if (b[a[i]] != 0) {
                a[i] = mex();
                x.emplace_back(i);
            }
            b[a[i]]++;
        }
        debug(a);
        b.resize(n);
        iota(b.begin(), b.end(), 0);
        while (a != b) {
            int m = mex();
            // debug(a, m);
            if (m == n) {
                for (int i = 0; i < n; i++) {
                    if (i != a[i]) {
                        a[i] = m;
                        x.emplace_back(i);
                        break;
                    }
                }
            } else {
                a[m] = m;
                x.emplace_back(m);
            }
        }
        debug(a);
        assert(x.size() <= 2 * n);
        cout << x.size() << '\n';
        for (int i : x) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}