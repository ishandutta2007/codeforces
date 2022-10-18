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
        vector<int> k(n);
        vector<long long> c(m);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
            k[i]--;
        }
        sort(k.begin(), k.end());
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c[k[i]];
        }
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (k[i] > j) {
                ans -= c[k[i]] - c[j];
                j++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}