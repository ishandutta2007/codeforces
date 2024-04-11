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
        int n, k;
        cin >> n >> k;
        vector<int> a(2 * n);
        for (auto &x : a) {
            cin >> x;
        }
        sort(a.begin(), a.end());
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] + k > a[i + n]) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}