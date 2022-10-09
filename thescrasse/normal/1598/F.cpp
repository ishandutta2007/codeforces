#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 400010
#define maxb 1048586

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mk, sm[maxb], dp[maxb][2], mk1, x;
string s;

struct rbs_segment {
    ll mn, sz, tt;
    vector<vector<ll>> f;

    rbs_segment(): mn(0), sz(0), tt(0), f({}) {}
    rbs_segment(string s): mn(0), sz(0), tt(0), f({}) {
        sz = s.size(); f.resize(2 * sz + 5);
        ll i = 0, cr = 0;
        for (auto u : s) {
            if (u == '(') cr++;
            else cr--;
            mn = min(mn, cr);
            f[sz + cr].pb(i);
            i++;
        }
        tt = cr;
    }

    ll cnt(ll p, ll x) {
        if (x < -sz || x > sz) return 0;
        if (f[sz + x].empty()) return 0;
        return (upper_bound(f[sz + x].begin(), f[sz + x].end(), p) - f[sz + x].begin());
    }

    ll fst(ll x) {
        if (x < -sz || x > sz) return INF;
        if (f[sz + x].empty()) return INF;
        return (*f[sz + x].begin());
    }
};

rbs_segment rb[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s; rb[i] = rbs_segment(s);
    }

    for (mk = 0; mk < (1 << n); mk++) {
        for (i = 0; i < n; i++) {
            if (((mk >> i) & 1) == 0) continue;
            mk1 = mk ^ (1 << i);
            sm[mk] = sm[mk1] + rb[i].tt;
            break;
        }
    }

    for (mk = 0; mk < (1 << n); mk++) {
        dp[mk][0] = -INF;
    }
    dp[0][0] = 0;

    for (mk = 0; mk < (1 << n); mk++) {
        for (i = 0; i < n; i++) {
            if (((mk >> i) & 1) == 0) continue;
            mk1 = mk ^ (1 << i);
            dp[mk][1] = max({dp[mk][1], dp[mk1][0], dp[mk1][1]});

            if (sm[mk1] + rb[i].mn >= 0) {
                dp[mk][0] = max(dp[mk][0], dp[mk1][0] + rb[i].cnt(INF, -sm[mk1]));
            } else {
                x = rb[i].fst(-sm[mk1] - 1);
                dp[mk][1] = max(dp[mk][1], dp[mk1][0] + rb[i].cnt(x, -sm[mk1]));
                // cout << "mk, mk1, x, cnt =" _ mk _ mk1 _ x _ rb[i].cnt(x, -sm[mk1]) << nl;
            }
        }
        dp[mk][1] = max(dp[mk][1], dp[mk][0]);
    }

    /*  for (mk = 0; mk < (1 << n); mk++) {
        cout << mk _ dp[mk][0] _ dp[mk][1] << nl;
    } */

    res = max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]);
    cout << res << nl;

    return 0;
}