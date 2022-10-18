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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n), c(n);
        vector<int> d(n);
        for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i] >> c[i];
            a[i]--, b[i]--, c[i]--;
            d[b[i]] = 1;
        }
        int x = (int) (min_element(d.begin(), d.end()) - d.begin());
        for (int i = 0; i < n; i++) {
            if (i == x) {
                continue;
            }
            cout << i + 1 << " " << x + 1 << '\n';
        }
    }
    return 0;
}