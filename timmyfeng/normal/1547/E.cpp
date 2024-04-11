#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(k), prefix(n, INT_MAX), suffix(n, INT_MAX);
        for (int i = 0; i < k; ++i) {
            cin >> a[i]; --a[i];
        }

        for (int i = 0; i < k; ++i) {
            int t;
            cin >> t;
            prefix[a[i]] = suffix[a[i]] = t;
        }

        for (int i = 1; i < n; ++i) {
            if (prefix[i - 1] < INT_MAX) {
                prefix[i] = min(prefix[i], prefix[i - 1] + 1);
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (suffix[i + 1] < INT_MAX) {
                suffix[i] = min(suffix[i], suffix[i + 1] + 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << min(prefix[i], suffix[i]) << " ";
        }
        cout << "\n";
    }
}