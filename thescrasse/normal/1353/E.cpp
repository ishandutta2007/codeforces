#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, l, kb, ks, dp[1000010][2], rs[1000010], ps[1000010];
string s;

ll rs1(ll l, ll r) {
    if (l == 0) return ps[r];
    return ps[r] - ps[l - 1];
}

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> k >> s;

        /* k1 = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == '1') k1++;
            if (i >= k - 1) {
                if (s[i - k + 1] == '1') k1--;
            }
            rs[i] = k1;
        } */

        ps[0] = (s[0] == '1');
        for (i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + (s[i] == '1');
        }

        for (i = 0; i < n; i++) {
            if (i >= k) {
                dp[i][1] = (s[i] == '0') + dp[i - k][1];
            } else {
                dp[i][1] = (s[i] == '0');
            }
            if (i >= 1) {
                dp[i][1] += rs1(max((ll)0, i - k + 1), i - 1);
            }
            if (i >= k) {
                dp[i][1] = min(dp[i][1], (s[i] == '0') + rs1(0, i - 1));
            }
        }

        res = min(rs1(0, n - 1), dp[n - 1][1]);
        for (i = 0; i < n - 1; i++) {
            res = min(res, dp[i][1] + rs1(i + 1, n - 1));
        }

        cout << res << endl;
    }

    return 0;
}