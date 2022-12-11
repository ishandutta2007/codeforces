#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string b;
    cin >> b;
    string res = "1";
    for (int i = 1; i < n; i++) {
        int lst = res[i - 1] - '0' + b[i - 1] - '0'; 
        bool flag = 0;
        for (int t = 1; t >= 0; t--) {
            int cur = b[i] - '0' + t;
            if (cur != lst) {
                res += '0' + t;
                flag =  1;
                break;
            }
        }
        assert(flag);
    }
    cout << res << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}