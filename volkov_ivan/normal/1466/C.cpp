#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        bool flag = 1;
        if (i > 0 && s[i - 1] == s[i])
            flag = 0;
        if (i > 1 && s[i - 2] == s[i])
            flag = 0;
        if (!flag) {
            res++;
            for (int nxt = 'a'; nxt <= 'z'; nxt++) {
                bool ok = 1;
                for (int j = i - 3; j <= i + 3; j++) {
                    if (0 <= j && j < n && s[j] == nxt) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    s[i] = nxt;
                    break;
                }
            }
        }
    }
    cout << res << "\n";
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
}