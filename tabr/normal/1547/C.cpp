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
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int x = 0, y = 0;
        vector<int> c;
        while (x + y < m + n) {
            if (x == n) {
                if (b[y] == 0) {
                    k++;
                } else if (b[y] > k) {
                    x = m + n;
                    c.clear();
                    c.emplace_back(-1);
                    break;
                }
                c.emplace_back(b[y++]);
            } else if (y == m) {
                if (a[x] == 0) {
                    k++;
                } else if (a[x] > k) {
                    x = m + n;
                    c.clear();
                    c.emplace_back(-1);
                    break;
                }
                c.emplace_back(a[x++]);
            } else if (b[y] <= a[x]) {
                if (b[y] == 0) {
                    k++;
                } else if (b[y] > k) {
                    x = m + n;
                    c.clear();
                    c.emplace_back(-1);
                    break;
                }
                c.emplace_back(b[y++]);
            } else {
                if (a[x] == 0) {
                    k++;
                } else if (a[x] > k) {
                    x = m + n;
                    c.clear();
                    c.emplace_back(-1);
                    break;
                }
                c.emplace_back(a[x++]);
            }
        }
        for (int i : c) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}