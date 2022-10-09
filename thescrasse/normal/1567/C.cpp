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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mk, p10[20], wy[30], nn;
vector<ll> v;
string s;

ll solve(vector<ll> v) {
    ll s, r = 0;
    if (v.size() == 0) return 1;
    s = v.back(); v.pop_back();
    if (s >= 0) r += (solve(v) * wy[s]);
    if (v.size() >= 2) {
        v[(ll)v.size() - 2]--;
        r += (solve(v) * wy[s + 10]);
    }

    /* cout << "solve" << nl;
    for (auto u : v) cout << u << ' ';
    cout << nl;
    cout << "r = " << r << nl; */

    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    p10[0] = 1;
    for (i = 1; i <= 15; i++) p10[i] = 10 * p10[i - 1];

    for (i = 0; i <= 9; i++) wy[i] = i + 1;
    for (i = 10; i <= 18; i++) wy[i] = 19 - i;

    cin >> t;
    while (t--) {
        cin >> s; v.clear();
        for (i = 0; i < s.size(); i++) v.pb(s[i] - '0');
        res = solve(v);

        res -= 2;
        cout << res << nl;
    }

    return 0;
}