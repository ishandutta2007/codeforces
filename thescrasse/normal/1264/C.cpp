// 1264C
// Beautiful Mirrors with queries

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, q, p[maxn], u, ps[maxn][2];
bool ch[maxn];
set<array<ll, 3>> s;
array<ll, 3> o;

ll fxp(ll b, ll e) {
    ll r;
    if (e == 0) return 1;
    if (e % 2) {
        r = fxp(b, e - 1); return (b * r) % mod;
    } else {
        r = fxp(b, e / 2); return (r * r) % mod;
    }
}

ll inv(ll x) {
    return fxp(x, mod - 2);
}

void fx(ll &x) {
    x %= mod; x += mod; x %= mod;
}

ll rq(ll l, ll r) {
    ll a, b, c, d, e, f;
    a = ps[l - 1][0]; c = ps[r][0];
    b = (c - a) * inv(a + 1); fx(b);
    d = ps[l - 1][1]; f = ps[r][1];
    e = f - d * (b + 1); fx(e);
    return e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q; ch[1] = true;
    for (i = 1; i <= n; i++) {
        cin >> p[i];
    }

    ps[0][0] = 0; ps[0][1] = 0;
    for (i = 1; i <= n; i++) {
        k = 100 * inv(p[i]) - 1; fx(k);
        ps[i][0] = (k + 1) * ps[i - 1][0] + k; fx(ps[i][0]);
        ps[i][1] = (k + 1) * (ps[i - 1][1] + 1); fx(ps[i][1]);
    }

    /* for (i = 1; i <= n; i++) {
        cout << ps[i][0] << ' ' << ps[i][1] << nl;
    }
    cout << nl; */

    s.insert({1, n, rq(1, n)}); res = rq(1, n);

    while (q--) {
        cin >> u;
        auto it = s.lower_bound({u, -INF, -INF});
        if (ch[u] == false) {
            it--; o = (*it); s.erase(it);
            ch[u] = true; res -= o[2];
            a = rq(o[0], u - 1); b = rq(u, o[1]);
            s.insert({o[0], u - 1, a}); res += a;
            s.insert({u, o[1], b}); res += b;
        } else {
            ch[u] = false;
            a = (*it)[1]; res -= (*it)[2];
            auto it1 = it; it1--;
            b = (*it1)[0]; res -= (*it1)[2];
            s.erase(it); s.erase(it1);
            c = rq(b, a);
            s.insert({b, a, c}); res += c;
        }
        fx(res);
        cout << res << nl;
    }

    return 0;
}