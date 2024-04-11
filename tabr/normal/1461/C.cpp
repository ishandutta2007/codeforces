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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        while (!a.empty() && a.back() == (int)a.size()) {
            a.pop_back();
        }
        double ans = 1;
        while (m--) {
            int r;
            double p;
            cin >> r >> p;
            if (r >= (int)a.size()) {
                ans *= 1 - p;
            }
        }
        if (a.empty()) {
            ans = 0;
        }
        cout << fixed << setprecision(10) << 1 - ans << '\n';
    }
    return 0;
}