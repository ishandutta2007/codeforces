// 1513E
// Cost Equilibrium

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll tt, fc[maxn], nv[maxn], x, y;
map<ll, ll> f;

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

ll bnm(ll a, ll b) {
    ll r = fc[a];
    r *= nv[b]; r %= mod;
    r *= nv[a - b]; r %= mod;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    fc[0] = 1; nv[0] = 1;
    for (i = 1; i < maxn; i++) {
        fc[i] = (i * fc[i - 1]) % mod; nv[i] = inv(fc[i]);
    }

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; tt += a[i];
    }

    if (tt % n != 0) {
        cout << 0 << nl; return 0;
    }
    k = tt / n;

    for (i = 1; i <= n; i++) {
        if (a[i] == k) continue;
        f[a[i]]++;
        if (a[i] < k) x++;
        else y++;
    }

    res = bnm(n, x + y);
    if (x >= 2 && y >= 2) {
        res *= fc[x]; res %= mod;
        res *= 2 * fc[y]; res %= mod;
    } else {
        res *= fc[x + y]; res %= mod;
    }

    for (auto u : f) {
        if (u.first != k) {
            res *= nv[u.second]; res %= mod;
        }
    }

    cout << res << nl;

    return 0;
}