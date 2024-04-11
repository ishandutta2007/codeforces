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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        vector<vector<int>> cnt(2, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            cnt[i % 2][a[i]] = max(cnt[i % 2][a[i]], cnt[1 - i % 2][a[i]] + 1);
        }
        for (int i = 1; i <= n; i++) {
            cout << max(cnt[0][i], cnt[1][i]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}