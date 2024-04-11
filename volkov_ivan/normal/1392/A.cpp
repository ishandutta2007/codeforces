#include <bits/stdc++.h>
//#define int long long

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
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i == 0) lst = x;
            if (x != lst) ok = 0;
        }
        cout << (ok ? n : 1) << "\n";
    }
    return 0;
}