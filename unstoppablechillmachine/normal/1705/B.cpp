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
        int sum = 0, cnt_zeros = 0;
        for (int i = 0; i + 1 < n; i++) {
            sum += a[i];
            cnt_zeros += (a[i] == 0 && sum > 0);
        }
        cout << sum + cnt_zeros << '\n';
    }
    return 0;
}