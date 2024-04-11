#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll dp[maxn][8][8], mk1, mk2, m_tr, new_p, new_sep;
ll row, new_mk1, new_mk2;
string s;

ll calc_p[8] = {0, 1, 2, 4, 4, 2, 1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> s; n = s.size(); s = '#' + s;

    dp[0][0][0] = 1;
    for (i = 0; i < n; i++) {
        for (mk1 = 0; mk1 < 8; mk1++) {
            for (mk2 = 0; mk2 < 8; mk2++) {
                for (m_tr = 0; m_tr < 8; m_tr++) {
                    new_p = 0; new_sep = 0;
                    flag[0] = 1;
                    for (row = 0; row < 3; row++) {
                        if (((mk2 >> row) & 1) == 0) {
                            if (((m_tr >> row) & 1) == 1 && s[i + 1] == '0') {
                                flag[0] = 0; break;
                            } else if (((m_tr >> row) & 1) == 0 && s[i + 1] == '1') {
                                new_sep |= (1 << row);
                            }
                        }
                    }
                    if (flag[0] == 0) continue;

                    new_p = calc_p[m_tr];
                    new_mk1 = mk1 | new_p;
                    new_mk2 = mk2 | new_sep;

                    // cout << "transition:" _ i _ mk1 _ mk2 _ "->" _ i + 1 _ new_mk1 _ new_mk2 << nl;

                    dp[i + 1][new_mk1][new_mk2] += dp[i][mk1][mk2];
                    if (dp[i + 1][new_mk1][new_mk2] > mod) dp[i + 1][new_mk1][new_mk2] -= mod;
                }
            }
        }
    }

    /* for (mk1 = 0; mk1 < 8; mk1++) {
        for (mk2 = 0; mk2 < 8; mk2++) {
            if (mk1 == 0 || mk1 == 1 || mk1 == 2 || mk1 == 4) continue;
            res = (res + dp[n][mk1][mk2]) % mod;
        }
    } */

    for (mk2 = 0; mk2 < 8; mk2++) {
        res = (res + dp[n][7][mk2]) % mod;
    }

    /* for (i = 0; i <= n; i++) {
        for (mk1 = 0; mk1 < 8; mk1++) {
            for (mk2 = 0; mk2 < 8; mk2++) {
                cout << dp[i][mk1][mk2] << ' ';
            }
            cout << nl;
        }
        cout << nl;
    } */

    cout << res << nl;

    return 0;
}