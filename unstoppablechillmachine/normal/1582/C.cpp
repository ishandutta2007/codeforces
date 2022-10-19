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
        int ans = -1;
        string s;
        cin >> s;
        for (int c = 0; c < 26; c++) {
            string new_s;
            vector<int> huy;
            int cc = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a' + c) {
                    cc++;
                } else {
                    new_s.pb(s[i]);
                    huy.pb(cc);
                    cc = 0;
                }
            }
            huy.pb(cc);
            auto is_pal = [](string &s) {
                int l = 0, r = SZ(s) - 1;
                while (l < r) {
                    if (s[l++] != s[r--]) {
                        return false;
                    }
                }
                return true;
            };
            if (is_pal(new_s)) {
                int sum = SZ(new_s);
                int l = 0, r = SZ(huy) - 1;
                while (l < r) {
                    sum += 2 * min(huy[l++], huy[r--]);
                }
                if (l == r) {
                    sum += huy[l];
                }
                ans = max(ans, sum);
            }
        }
        if (ans == -1) {
            cout << ans << '\n';
        } else {
            cout << n - ans << '\n';
        }
    }
}