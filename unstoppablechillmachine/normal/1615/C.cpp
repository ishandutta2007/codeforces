#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int cnt_one = 0, cnt_zero = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (s[i] == '1') {
                    cnt_one++;
                } else {
                    cnt_zero++;
                }
            }
        }
        int ans = n + 1;
        if (cnt_one == cnt_zero) {
            ans = cnt_one * 2;
        }
        vector<int> check;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && t[i] == '0') {
                check.pb(i);
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && t[i] == '1') {
                check.pb(i);
                break;
            }
        }
        for (auto it : check) {
            string s2 = s, t2 = t;
            for (int i = 0; i < n; i++) {
                if (i != it) {
                    s2[i] ^= 1;
                }
            }
            int cnt_one = 0, cnt_zero = 0;
            for (int i = 0; i < n; i++) {
                if (s2[i] != t2[i]) {
                    if (s2[i] == '1') {
                        cnt_one++;
                    } else {
                        cnt_zero++;
                    }
                }
            }
            if (cnt_one == cnt_zero) {
                ans = min(ans, cnt_one * 2 + 1);
            }
        }
        if (ans == n + 1) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}