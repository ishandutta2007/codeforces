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

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());

        int left = n - 1, right = n - 1;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            left = max(left, i);
            while (left > i && a[i] + a[left] >= l) {
                --left;
            }
            right = max(right, i);
            while (right > i && a[i] + a[right] > r) {
                --right;
            }
            ans += right - left;
        }

        cout << ans << "\n";
    }
}