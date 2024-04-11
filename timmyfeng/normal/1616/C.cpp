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
        for (auto &i : a) cin >> i;

        if (n <= 2) {
            cout << 0 << "\n";
            continue;
        }

        int best = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // a'[k] = a[i] + (k - i) * (a[j] - a[i]) / (j - i)
                // (a'[k] - a[i]) * (j - i) = (a[j] - a[i]) * (k - i)

                int delta = 0;
                for (int k = 0; k < n; ++k) {
                    delta += (a[k] - a[i]) * (j - i) != (a[j] - a[i]) * (k - i);
                }
                best = min(best, delta);
            }
        }

        cout << best << "\n";
    }
}