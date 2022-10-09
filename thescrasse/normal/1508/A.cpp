#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], l[4], x, y;
string s[4];
vector<ll> rs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; rs.clear();
        for (i = 1; i <= 3; i++) {
            cin >> s[i]; s[i] = '#' + s[i];
        }

        for (i = 1; i <= 3; i++) l[i] = 1;
        while (true) {
            /* for (i = 1; i <= 3; i++) cout << l[i] << ' ';
            cout << nl;
            for (i = 1; i <= 3; i++) cout << s[i][l[i]] << ' ';
            cout << nl; */
            if (l[1] <= 2 * n && l[2] <= 2 * n && l[3] <= 2 * n) {
                x = 0; y = 0;
                for (i = 1; i <= 3; i++) {
                    // cout << s[i][l[i]] << ' ';
                    if (s[i][l[i]] == '0') x++;
                    else y++;
                }
                // cout << nl;
                // cout << "x, y = " << x _ y << nl;
                if (x >= 2) {
                    for (i = 1; i <= 3; i++) {
                        if (s[i][l[i]] == '0') l[i]++;
                    }
                    rs.pb(0);
                } else {
                    for (i = 1; i <= 3; i++) {
                        if (s[i][l[i]] == '1') l[i]++;
                    }
                    rs.pb(1);
                }
            } else {
                for (i = 1; i <= 3; i++) {
                    flag[0] = 1;
                    for (j = 1; j <= 3; j++) {
                        if (l[i] > 2 * n || (l[j] <= 2 * n && l[i] < l[j])) flag[0] = 0;
                    }

                    if (flag[0] == 1) {
                        for (j = l[i]; j <= 2 * n; j++) {
                            if (rs.size() == 3 * n) break;
                            if (s[i][j] == '0') rs.pb(0);
                            else rs.pb(1);
                        }
                        break;
                    }
                }
                break;
            }
        }

        for (auto u : rs) cout << u;
        cout << nl;
    }

    return 0;
}