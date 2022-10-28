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

        int gcd_all = 0;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
            gcd_all = gcd(gcd_all, i);
        }

        vector<vector<int>> sparse(__lg(n) + 1, vector<int>(n));
        for (int i = 0; i <= __lg(n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    sparse[i][j] = a[j];
                } else {
                    sparse[i][j] = gcd(sparse[i - 1][j], sparse[i - 1][(j + (1 << (i - 1))) % n]);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int low = 1, high = n;
            while (low < high) {
                int mid = (low + high) / 2;

                int log = __lg(mid);
                int gcd_range = gcd(sparse[log][i], sparse[log][(i + mid - (1 << log)) % n]);
                if (gcd_range == gcd_all) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            ans = max(ans, low);
        }

        cout << ans - 1 << "\n";
    }
}