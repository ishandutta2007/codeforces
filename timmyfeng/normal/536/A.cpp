#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long a, b;
    cin >> a >> b >> n;

    for (int i = 0; i < n; ++i) {
        long long l, t, m;
        cin >> l >> t >> m;

        if (t < a) {
            cout << -1 << "\n";
            continue;
        }

        long long lo = l - 1, hi = (t - a) / b + 1;
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;

            long long length = mid - l + 1;
            long long sum = (a + (l - 1) * b) * length +
                b * length * (length - 1) / 2;

            if (sum <= m * t) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        cout << (hi < l ? -1 : hi) << "\n";
    }
}