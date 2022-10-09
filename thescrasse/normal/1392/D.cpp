#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, sz;
vector<array<ll, 2>> cn[2];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cn[0].clear(); cn[1].clear();
        cin >> n >> s; k = 1;
        for (i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                k++;
            } else if (s[i - 1] == 'L') {
                cn[0].pb({k, 1}); k = 1;
            } else {
                cn[1].pb({k, 1}); k = 1;
            }
        }

        if (s[n - 1] == 'L') cn[0].pb({k, 1});
        else cn[1].pb({k, 1});

        if (s[0] == s[n - 1]) {
            if (!cn[0].empty() && !cn[1].empty()) {
                if (s[n - 1] == 'L') {
                    sz = cn[0].size();
                    cn[0][0][1] = 0; cn[0][sz - 1][1] = 0;
                    cn[0].pb({cn[0][0][0] + cn[0][sz - 1][0], 1});
                } else {
                    sz = cn[1].size();
                    cn[1][0][1] = 0; cn[1][sz - 1][1] = 0;
                    cn[1].pb({cn[1][0][0] + cn[1][sz - 1][0], 1});
                }
            }
        }

        res = 0;
        for (auto u : cn[0]) {
            if (u[1] == 1) res += u[0] / 3;
            // cout << u[0] << ' ' << u[1] << nl;
        }
        for (auto u : cn[1]) {
            if (u[1] == 1) res += u[0] / 3;
            // cout << u[0] << ' ' << u[1] << nl;
        }

        if (cn[0].empty() || cn[1].empty()) {
            res = (n + 2) / 3;
        }

        cout << res << nl;
    }

    return 0;
}