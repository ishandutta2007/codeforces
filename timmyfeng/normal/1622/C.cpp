#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; 
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        ranges::sort(a, greater<int>());

        long long sum = accumulate(a.begin(), a.end(), 0LL), ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, max(0LL, sum - k + i) / (i + 1) + i);
            sum += a[n - 1] - a[i];
        }

        cout << ans << "\n";
    }
}