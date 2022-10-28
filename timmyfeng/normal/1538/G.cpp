#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        int low = 0, high = 1000000000;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            bool ok_a = min(a, b) <= min(x, y) / mid;
            bool ok_b = a == b || mid <= (x - min(a, b) * mid) / abs(b - a) + (y - min(a, b) * mid) / abs(b - a);
            if (ok_a && ok_b) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        cout << high << "\n";
    }
}