#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> count(m);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++count[a % m];
        }

        int ans = 0;
        for (int i = 1, j = m - 1; i < j; ++i, --j) {
            if (count[i] > count[j]) {
                swap(count[i], count[j]);
            }

            if (count[j] > 0) {
                ans += max(1, count[j] - count[i]);
            }
        }

        ans += count[0] > 0;
        ans += m % 2 == 0 && count[m / 2] > 0;

        cout << ans << "\n";
    }
}