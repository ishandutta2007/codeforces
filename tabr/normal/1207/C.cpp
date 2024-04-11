#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int tt;
    cin >> tt;
    rep(qq, 0, tt) {
        ll n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        s += "000";
        vector<int> c;
        c.push_back(1);
        ll ans = n * a + (n + 1) * b;
        int m = 1;
        rep(i, 0, n - 1) {
            if (s[i] == s[i + 1])
                c[m - 1]++;
            else if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1') {
                c[m - 1] += 2;
                i++;
            } else {
                c.push_back(1);
                m++;
            }
        }
        rep(i, 1, m - 1) {
            if (i % 2 == 1) {
                ans += (c[i] + 1) * b;
            } else {
                ans += min(2 * a, (c[i] - 1) * b);
            }
        }
        if (c.size() > 1)
            ans += 2 * a;
        cout << ans << endl;
    }
    return 0;
}