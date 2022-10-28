#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        vector<int> count_a(n + 1);
        for (auto i : a) ++count_a[i];

        int x = 1, y = n, balance = -n;
        for (int l = 1, r = 0; l <= n; ++l) {
            while (r < n && balance < k) {
                balance += 2 * count_a[++r];
            }

            if (balance >= k && r - l < y - x) {
                x = l, y = r;
            }

            balance -= 2 * count_a[l];
        }

        cout << x << " " << y << "\n";

        int l = 0; balance = 0;
        for (int r = 0; r < n && k > 1; ++r) {
            if (x <= a[r] && a[r] <= y) ++balance;
            else --balance;
            
            if (balance > 0) {
                cout << l + 1 << " " << r + 1 << "\n";
                l = r + 1, balance = 0, --k;
            }
        }

        cout << l + 1 << " " << n << "\n";
    }
}