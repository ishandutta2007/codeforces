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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a;
        vector<int> c;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < (n + i) / m; j++) {
                a.emplace_back((n + i) / m);
                c.emplace_back(i);
            }
        }
        assert((int) a.size() == n);
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; i++) {
            b[i].second = i;
        }
        for (int x = 0; x < k; x++) {
            for (int i = 0; i < n; i++) {
                if (i == 0 || c[i] != c[i - 1]) {
                    cout << '\n';
                    cout << a[i] << " ";
                }
                if (a[i] == a[0]) {
                    b[i].first++;
                }
                cout << b[i].second + 1 << " ";
            }
            sort(b.begin(), b.end());
        }
        assert(b[n - 1].first - b[0].first <= 1);
    }
    return 0;
}