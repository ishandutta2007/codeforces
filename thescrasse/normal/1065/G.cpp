#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 210

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll p;
string s[maxn], bsm;

ll cnt(ll ty, string s, string t, ll p) {
    ll n, m, i, j, f, r = 0;
    n = s.size(); m = t.size();
    if (ty == 0) p = min(p, n);
    else p = n;
    for (i = 0; i < p; i++) {
        f = 1;
        for (j = 0; j < m; j++) {
            if (ty == 0 && i > n - m) break;
            if (i + j >= n) break;
            if (s[i + j] < t[j]) {
                r++; f = 0; break;
            } else if (s[i + j] > t[j]) {
                f = 0; break;
            }
        }

        if (f == 1 && ty == 1 && i > n - m) r++;
        /* if (s == "10101101" && t == "10110") {
            cout << "i, r =" _ i _ r << nl;
        } */
    }
    // cout << "cnt" _ ty _ s _ t _ r << nl;
    return r;
}

bool good(string bsm) {
    ll i, j, k, r, dp[maxn];
    for (i = 0; i <= n; i++) {
        if (s[i] != "" && s[i].size() <= 3 * m) {
            dp[i] = cnt(1, s[i], bsm, 0); continue;
        }
        dp[i] = dp[i - 2] + dp[i - 1] +
            cnt(0,
                s[(i % 2) + 18].substr((ll)s[(i % 2) + 18].size() - m, m) + s[((i + 1) % 2) + 18].substr(0, m),
                bsm, m);
        dp[i] -= cnt(1,
            s[(i % 2) + 18].substr((ll)s[(i % 2) + 18].size() - m, m),
            bsm, 0);
        if (dp[i] > INF) return false;
    }

    /* cout << "bsm =" _ bsm << nl;
    for (i = 0; i <= n; i++) cout << dp[i] << ' ';
    cout << nl; */

    return (dp[n] < p);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n >> p >> m;
    s[0] = "0"; s[1] = "1";
    for (i = 2; i <= 20; i++) s[i] = s[i - 2] + s[i - 1];

    bsm = "";
    for (i = 1; i <= m; i++) {
        if (good(bsm + "1")) bsm += "1";
        else if (good(bsm + "0")) bsm += "0";
    }

    cout << bsm << nl;

    return 0;
}