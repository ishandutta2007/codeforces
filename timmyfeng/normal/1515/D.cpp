#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++(i < l ? left : right)[a - 1];
        }

        for (int i = 0; i < n; ++i) {
            while (left[i] > 0 && right[i] > 0) {
                --left[i], --right[i];
                --l, --r;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (left[i] >= 2 && l > r) {
                left[i] -= 2, l -= 2;
                ++ans;
            }

            while (right[i] >= 2 && r > l) {
                right[i] -= 2, r -= 2;
                ++ans;
            }
        }

        ans += max(l, r);

        cout << ans << "\n";
    }
}