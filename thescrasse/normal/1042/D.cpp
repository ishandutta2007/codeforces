#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e10
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, res, flag[10], a[2 * maxn], b[2 * maxn], fn[2 * maxn];
map<ll, ll> m;

void upd(ll p, ll x) {
    // cout << "upd " << p << ' ' << x << nl;
    while (p <= 2 * n) {
        // cout << p << nl;
        fn[p] += x;
        p += p & (-p);
    }
}

ll ps(ll p) {
    ll r = 0;
    while (p >= 1) {
        r += fn[p];
        p -= p & (-p);
    }
    // cout << p << ' ' << r << nl;
    return r;
}

ll rs(ll l, ll r) {
    // cout << "rs " << l << ' ' << r << nl;
    if (l == 1) return ps(r);
    return ps(r) - ps(l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i < 2 * maxn; i++) fn[i] = 0;

    cin >> n >> t; n++; t--; a[1] = 0;
    for (i = 2; i <= n; i++) {
        cin >> a[i]; a[i] += a[i - 1]; a[i + n] = a[i] - t;
    }

    for (i = 1; i <= 2 * n; i++) b[i] = a[i];

    sort(b + 1, b + 2 * n + 1);
    for (i = 1; i <= 2 * n; i++) m[b[i]] = i;

    // for (i = 1; i <= 2 * n; i++) cout << i << ' ' << a[i] << ' ' << m[a[i]] << nl;

    res = 0;
    for (i = 1; i <= n; i++) {
        res += rs(m[a[i + n]], 2 * n);
        upd(m[a[i]], 1);
    }

    // for (i = 1; i <= 2 * n; i++) cout << i << ' ' << fn[i] << nl;

    cout << res;

    return 0;
}