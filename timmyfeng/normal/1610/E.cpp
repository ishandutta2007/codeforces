#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        int ans = n;
        for (int i = 0; i < n; ++i) {
            int len = 1, ptr = n - 1;
            while (a[ptr] > a[i]) {
                int low = i, high = ptr - 1;
                while (low < high) {
                    int mid = (low + high + 1) / 2;
                    if (2 * a[mid] <= a[ptr] + a[i]) {
                        low = mid;
                    } else {
                        high = mid - 1;
                    }
                }

                ptr = high;
                ++len;
            }
            len += ptr - i;

            ans = min(ans, n - len);
        }

        cout << ans << "\n";
    } 
}