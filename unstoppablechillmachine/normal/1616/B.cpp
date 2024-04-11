#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int pref = 0;
        bool was_smaller = false;
        while (pref + 1 < n) {
            if (s[pref + 1] < s[pref] || (s[pref + 1] == s[pref] && was_smaller)) {
                if (s[pref + 1] < s[pref]) {
                    was_smaller = true;
                }
                pref++;
            } else {
                break;
            }
        }
        string ans = s.substr(0, pref + 1);
        string ans2 = ans;
        reverse(all(ans2));
        cout << ans + ans2 << '\n';
    }
}