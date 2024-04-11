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

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        long long ans = 0;
        vector<int> prv(n);
        for (int i = 0; i < n; ++i) {
            ans += max(0, a[i] - 1 - prv[i]);
            prv[i] = max(0, prv[i] - a[i] + 1);
            for (int j = i + 2; j < n && j <= i + a[i]; ++j) {
                ++prv[j];
            }

            if (i < n - 1) {
                prv[i + 1] += prv[i];
            }
        }

        cout << ans << "\n";
    }
}