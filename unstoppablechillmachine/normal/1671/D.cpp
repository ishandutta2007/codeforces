#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &it : a) {
            cin >> it;
        }
        int mn = a[0], mx = a[0];
        for (int i = 1; i < n; i++) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }

        int add_min = 1e9, add_max = 1e9;
        if (x <= mx) {
            add_max = 0;
        } else {
            add_max = min(x - a[0], x - a.back());
        }
        if (mn == 1) {
            add_min = 0;
        } else {
            add_min = min(a[0] - 1, a.back() - 1);
        }
        for (int i = 1; i < n; i++) {
            if (add_min != 0) add_min = min(add_min, 2 * min(a[i - 1], a[i]) - 2);
            if (add_max != 0) add_max = min(add_max, 2 * (x - max(a[i - 1], a[i])));
        }
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += abs(a[i] - a[i - 1]);
        }
        cout << add_min + add_max + sum << '\n';
    }
}