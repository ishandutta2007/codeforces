#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<long long> a(n);
        for (auto &i : a) cin >> i;

        int gcd_b = 0;
        while (m--) {
            int b; cin >> b;
            gcd_b = gcd(gcd_b, b);
        }

        long long ans = LLONG_MIN;
        for (auto parity : {0, 1}) {
            long long ans_parity = 0;
            for (int i = 0; i < gcd_b; ++i) {
                int count_neg = 0;
                long long min_a = INT_MAX, sum_a = 0;
                for (int j = i; j < n; j += gcd_b) {
                    count_neg += (a[j] < 0);
                    min_a = min(min_a, abs(a[j]));
                    sum_a += abs(a[j]);
                }

                if (count_neg % 2 == parity) {
                    ans_parity += sum_a;
                } else {
                    ans_parity += sum_a - 2 * min_a;
                }
            }
            ans = max(ans, ans_parity);
        }

        cout << ans << "\n";
    }
}