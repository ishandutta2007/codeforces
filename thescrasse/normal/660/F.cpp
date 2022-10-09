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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll p0[maxn], p1[maxn];

ll rsum(ll l, ll r) {
    if (l > r) return 0;
    ll rs = p1[r] - p1[l - 1] + (- l + 1) * (p0[r] - p0[l - 1]);
    // cout << "rsum" _ l _ r _ rs << nl;
    res = max(res, rs); return rs;
}

void solve(ll l, ll r, ll cl, ll cr) {
    // cout << "solve" _ l _ r _ cl _ cr << nl;
    if (l > r) return;
    ll m = (l + r) / 2;
    ll rs = rsum(m, cl - 1);
    array<ll, 2> mx = {-INF, -INF};
    for (i = max(m, cl); i <= cr; i++) {
        rs += ((i - m + 1) * a[i]);
        mx = max(mx, {rs, i});
        res = max(res, rs);
    }
    solve(l, m - 1, cl, mx[1]);
    solve(m + 1, r, mx[1], cr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        p0[i] = p0[i - 1] + a[i]; p1[i] = p1[i - 1] + (i * a[i]);
    }

    solve(1, n, 1, n);
    cout << res << nl;

    return 0;
}