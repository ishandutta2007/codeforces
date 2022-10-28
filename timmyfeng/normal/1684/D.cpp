#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        long long sum = accumulate(a.begin(), a.end(), 0LL);

        for (int i = 0; i < n; ++i) {
            a[i] -= n - i - 1;
        }

        sort(a.rbegin(), a.rend());

        long long answer = sum, prefix = 0;
        for (int i = 0; i < k; ++i) {
            prefix += a[i] + i;
            answer = min(answer, sum - prefix);
        }

        cout << answer << "\n";
    }
}