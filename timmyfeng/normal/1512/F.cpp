#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long c;
        cin >> n >> c;

        vector<long long> a(n), b(n - 1);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }

        long long balance = 0, days = 0, ans = c;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, days + (c <= balance ? 0 : (c - balance + a[i] - 1) / a[i]));
            if (i < n - 1) {
                long long wait = b[i] <= balance ? 0 : (b[i] - balance + a[i] - 1) / a[i];
                balance += wait * a[i];
                days += wait;

                balance -= b[i];
                ++days;
            }
        }

        cout << ans << "\n";
    }
}