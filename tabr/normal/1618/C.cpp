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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> b, c;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                b.emplace_back(a[i]);
            } else {
                c.emplace_back(a[i]);
            }
        }
        long long ans = 0;
        for (int z = 0; z < 2; z++) {
            long long g = 0;
            for (auto i : b) {
                g = __gcd(g, i);
            }
            for (auto i : c) {
                if (i % g == 0) {
                    g = 0;
                    break;
                }
            }
            if (g) {
                ans = g;
                break;
            }
            swap(b, c);
        }
        cout << ans << '\n';
    }
    return 0;
}