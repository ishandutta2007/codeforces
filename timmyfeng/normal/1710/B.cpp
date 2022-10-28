#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<pair<long long, long long>> rains(n);
        map<long long, int> deriv2;
        for (auto &[x, p] : rains) {
            cin >> x >> p;
            deriv2[x - p] += 1;
            deriv2[x] -= 2;
            deriv2[x + p] += 1;
        }

        long long max1 = LLONG_MIN, max2 = LLONG_MIN;

        long long pos = deriv2.begin()->first, slope = 0, y = 0;
        for (auto [x, d] : deriv2) {
            y += slope * (x - pos);
            pos = x, slope += d;

            if (y > m) {
                // add point (x, y)
                // pi - xi >= y - m - x
                // pi + xi >= y - m + x
                max1 = max(max1, y - m - x);
                max2 = max(max2, y - m + x);
            }
        }

        for (auto [x, p] : rains) {
            cout << (p - x >= max1 && p + x >= max2);
        }
        cout << "\n";
    }
}