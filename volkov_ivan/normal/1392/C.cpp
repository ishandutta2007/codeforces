#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        int lst = -1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i == 0) {
                lst = x;
                continue;
            }
            if (x < lst) res += lst - x;
            lst = x;
        }
        cout << res << "\n";
    }
    return 0;
}