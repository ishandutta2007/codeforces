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

        vector<int> a(n + 2);
        for (auto &i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());

        long long sum = accumulate(a.begin(), a.begin() + n, 0LL);
        if (sum == a[n] || sum == a[n + 1]) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << "\n";
        } else {
            int i = 0;
            while (i < n && sum - a[i] + a[n] != a[n + 1]) {
                ++i;
            }

            if (i == n) {
                cout << -1 << "\n";
            } else {
                for (int j = 0; j <= n; ++j) {
                    if (j != i) {
                        cout << a[j] << " ";
                    }
                }
                cout << "\n";
            }
        }
    }
}