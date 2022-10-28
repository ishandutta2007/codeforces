#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> h(n);
        for (auto &i : h) cin >> i;

        vector<long long> sum(n);
        for (int i = 1; i < n; ++i) {
            sum[i] = max(0, max(h[i - 1], h[i + 1]) - h[i] + 1);
        }

        for (int i = 3; i < n - 1; i += 2) {
            sum[i] += sum[i - 2];
        }

        if (n % 2) {
            cout << sum[n - 2] << "\n";
        } else {
            for (int i = n - 4; i > 0; i -= 2) {
                sum[i] += sum[i + 2];
            }

            long long answer = min(sum[n - 3], sum[2]);
            for (int i = 1; i + 3 < n; i += 2) {
                answer = min(answer, sum[i] + sum[i + 3]);
            }
            cout << answer << "\n";
        }
    }
}