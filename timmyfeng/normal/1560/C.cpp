#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        int low = 0, high = 40000;
        while (low < high) {
            int mid = (low + high) / 2;
            if (mid * mid < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        int dist = low * low - k;
        if (dist >= low) {
            cout << 2 * low - 1 - dist << " " << low << "\n";
        } else {
            cout << low << " " << 1 + dist << "\n";
        }
    }
}