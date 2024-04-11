#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        vector<int> b(n);
        for (auto &i : b) cin >> i;

        vector<int> balances = {0};
        for (int i = 0; i < n; ++i) {
            vector<int> new_balances;
            for (auto j : balances) {
                new_balances.push_back(abs(j + a[i] - b[i]));
                new_balances.push_back(abs(j + b[i] - a[i]));
            }

            balances = new_balances;

            ranges::sort(balances);
            balances.erase(begin(ranges::unique(balances)), end(balances));
        }

        int balance = balances[0];

        int sum_all = accumulate(begin(a), end(a), 0) + accumulate(begin(b), end(b), 0);

        int ans = (sum_all - balance) * (sum_all - balance) / 4 + (sum_all + balance) * (sum_all + balance) / 4;
        for (int i = 0; i < n; ++i) ans += (n - 2) * (a[i] * a[i] + b[i] * b[i]);

        cout << ans << "\n";
    }
}