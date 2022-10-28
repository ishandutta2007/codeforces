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

        vector<int> prefix(n), suffix(n);

        for (int i = 0; i < n; ++i) {
            cin >> suffix[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> prefix[i];
        }

        for (int i = n - 2; i >= 0; --i) {
            suffix[i] += suffix[i + 1];
        }

        for (int i = 1; i < n; ++i) {
            prefix[i] += prefix[i - 1];
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, max(i == 0 ? 0 : prefix[i - 1], i == n - 1 ? 0 : suffix[i + 1]));
        }

        cout << ans << "\n";
    }
}