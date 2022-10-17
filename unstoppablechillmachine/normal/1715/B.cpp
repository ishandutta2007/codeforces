#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, k, val, sum;
        cin >> n >> k >> val >> sum;
        if (k * val + n * (k - 1) < sum || k * val > sum) {
            cout << -1 << '\n';
            continue;
        }
        int rem = sum - k * val;
        for (int i = 1; i < n; i++) {
            if (rem <= k - 1) {
                cout << rem << ' ';
                sum -= rem;
                rem = 0;
            } else {
                cout << k - 1 << ' ';
                rem -= k - 1;
                sum -= k - 1;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}