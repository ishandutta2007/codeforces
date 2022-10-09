#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, tc, n, m, res, flag[10], a, b;
string s, t;

bool good(string s, string t) {
    ll r = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == '1') r++;
        if (t[i] == '1') r--;
    }
    return (r == 0);
}

ll diff(string s, string t) {
    ll r = 0;
    for (i = 0; i < n; i++) r += (s[i] != t[i]);
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> tc;
    while (tc--) {
        cin >> n >> s >> t; res = INF;

        k = diff(s, t);
        if (good(s, t)) res = min(res, k);

        for (auto &u : s) {
            if (u == '0') u = '1';
            else u = '0';
        }

        flag[0] = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == '0' && t[i] == '1') {
                flag[0] = 1; s[i] = '1'; break;
            }
        }

        k = diff(s, t);
        if (flag[0] == 1 && good(s, t) == true) res = min(res, k + 1);

        if (res == INF) cout << -1 << nl;
        else cout << res << nl;
    }

    return 0;
}