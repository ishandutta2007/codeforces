// 2d lis lol

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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll dp[maxn];
vector<array<ll, 2>> v;

struct fenwick {
    vector<ll> fn, rb;

    fenwick(): fn({}), rb({}) {
        ll i;
        fn.resize(maxn);
        for (i = 0; i < maxn; i++) fn[i] = -INF;
    }

    void upd(ll p, ll x) {
        // cout << "upd" _ p _ x << nf;
        while (p < maxn) {
            rb.pb(p);
            fn[p] = max(fn[p], x); p += (p & (-p));
        }
    }

    ll pm(ll p) {
        // cout << "pm" _ p << nf;
        ll r = -INF;
        while (p > 0) {
            r = max(r, fn[p]); p -= (p & (-p));
        }
        return r;
    }

    void clear() {
        for (auto u : rb) fn[u] = -INF;
        rb.clear();
    }
};

fenwick fn;

bool cmp(array<ll, 3> a, array<ll, 3> b) {
    if (a[1] != b[1]) return (a[1] < b[1]);
    return (a[0] > b[0]);
}

void solve(ll l, ll r) {
    // cout << "solve" _ l _ r << nf;
    ll i;
    vector<array<ll, 3>> v;

    if (l == r) return;
    ll mid = (l + r) / 2;
    solve(l, mid);
    for (i = l; i <= r; i++) v.pb({i, a[i], b[i]});
    sort(v.begin(), v.end(), cmp); fn.clear();
    for (auto u : v) {
        if (u[0] > mid) {
            dp[u[0]] = max(dp[u[0]], fn.pm(u[2]) + 1);
        } else {
            fn.upd(u[2], dp[u[0]]);
        }
        // cout << u[0] _ u[1] _ u[2] _ dp[u[0]] << nl;
    }
    solve(mid + 1, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; n++;
    a[1] = 0; b[1] = 1;
    for (i = 2; i <= n; i++) {
        cin >> a[i]; b[i] = -a[i] + i; dp[i] = -INF;
    }

    for (i = 1; i <= n; i++) v.pb({b[i], i});
    sort(v.begin(), v.end());
    for (i = 0; i <= n - 1; i++) b[v[i][1]] = i + 1;

    solve(1, n);

    for (i = 1; i <= n; i++) {
        // cout << dp[i] << ' ';
        res = max(res, dp[i]);
    }
    // cout << nl;

    cout << res << nl;

    return 0;
}