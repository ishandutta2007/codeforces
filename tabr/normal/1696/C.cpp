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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k;
        cin >> k;
        vector<long long> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
        }
        auto Eval = [&](vector<long long> c) {
            vector<pair<long long, long long>> d;
            for (auto x : c) {
                long long y = 1;
                while (x % m == 0) {
                    y *= m;
                    x /= m;
                }
                if (!d.empty() && d.back().first == x) {
                    d.back().second += y;
                } else {
                    d.emplace_back(x, y);
                }
            }
            return d;
        };
        if (Eval(a) == Eval(b)) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}