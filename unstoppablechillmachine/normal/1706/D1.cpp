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
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        int answer = 3000;
        for (int mx_value = 3000; mx_value >= 0; mx_value--) {
            bool ok = true;
            int mn_value = mx_value, cur = 1;
            for (int i = 0; i < n; i++) {
                while (a[i] / cur > mx_value && cur < k) {
                    cur++;
                }
                if (a[i] / cur > mx_value) {
                    ok = false;
                    break;
                }
                mn_value = min(mn_value, a[i] / cur);
            }
            if (ok) {
                answer = min(answer, mx_value - mn_value);
            }
        }
        cout << answer << '\n';
    }
    return 0;
}