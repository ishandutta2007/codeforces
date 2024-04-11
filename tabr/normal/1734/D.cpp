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
        int n, k;
        cin >> n >> k;
        k--;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long t = 0, mn = 0;
        vector<pair<long long, long long>> right, left;
        for (int i = k + 1; i < n; i++) {
            t += a[i];
            mn = min(t, mn);
            if (t > 0 || i == n - 1) {
                right.emplace_back(t, mn);
                t = mn = 0;
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            t += a[i];
            mn = min(t, mn);
            if (t > 0 || i == 0) {
                left.emplace_back(t, mn);
                t = mn = 0;
            }
        }
        reverse(left.begin(), left.end());
        reverse(right.begin(), right.end());
        long long now = a[k];
        while (!left.empty() && !right.empty()) {
            if (left.back().second + now >= 0) {
                now += left.back().first;
                left.pop_back();
            } else if (right.back().second + now >= 0) {
                now += right.back().first;
                right.pop_back();
            } else {
                break;
            }
        }
        cout << (left.empty() || right.empty() ? "Yes" : "No") << '\n';
    }
    return 0;
}