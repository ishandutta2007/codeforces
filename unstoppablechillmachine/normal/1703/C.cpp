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
        vector<int> cur_val(n);
        for (auto &x : cur_val) {
            cin >> x;
        }
        for (int i = 0; i < n; i++) {
            int cnt;
            cin >> cnt;
            for (int j = 0; j < cnt; j++) {
                char c;
                cin >> c;
                int delta = 0;
                if (c == 'U') {
                    delta = -1;
                } else {
                    delta = 1;
                }
                cur_val[i] = (cur_val[i] + delta + 10) % 10;
            }
            cout << cur_val[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}