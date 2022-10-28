#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long k, x;
        cin >> k >> x;

        long long low = 1, high = 2 * k - 1;
        while (low < high) {
            long long mid = (low + high) / 2;

            long long total;
            if (mid <= k) {
                total = mid * (mid + 1) / 2;
            } else {
                total = k * (k + 1) / 2 + (mid - k) * (k - 1 + k - (mid - k)) / 2;
            }

            if (total < x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        cout << low << "\n";
    }
}