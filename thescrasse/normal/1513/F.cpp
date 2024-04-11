// 1513F
// Swapping Problem

// merge sort tree lol

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
#define ub 200010
#define maxs 525000

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
vector<array<ll, 2>> st[maxs], v;

void build(ll ty, ll p, ll tl, ll tr) {
    ll i;
    st[p].clear();
    if (tl == tr) {
        if (a[tl] == 0) return;
        st[p].pb({(1 - 2 * (ty & 1)) * a[tl],
            abs(a[tl] - b[tl]) + (-1 + 2 * (ty & 1)) * a[tl] + (1 - (ty & 2)) * b[tl]});
        // cout << "init " << p _ st[p][0][0] _ st[p][0][1] << nl;
        return;
    }
    ll tm = (tl + tr) / 2;
    build(ty, 2 * p, tl, tm);
    build(ty, 2 * p + 1, tm + 1, tr);
    merge(st[2 * p].begin(), st[2 * p].end(), st[2 * p + 1].begin(), st[2 * p + 1].end(),
        back_inserter(st[p]));
    ll sz = st[p].size();
    for (i = sz - 2; i >= 0; i--) st[p][i][1] = max(st[p][i][1], st[p][i + 1][1]);

    if (st[p].empty()) return;
    /* cout << "build " << ty _ p _ tl _ tr << nl;
    for (auto u : st[p]) cout << u[0] _ u[1] << " - ";
    cout << nl; */
}

ll rmq(ll ty, ll p, ll tl, ll tr, ll l, ll r, ll x) {
    if (l > r) return -INF;
    if (tl == l && tr == r) {
        array<ll, 2> o = {(1 - 2 * (ty & 1)) * x, -INF};
        auto it = lower_bound(st[p].begin(), st[p].end(), o);

        /* if (it != st[p].end()) {
            cout << "rmq " << ty _ p _ tl _ tr _ l _ r _ x << nl;
            cout << "upd " << (*it)[1] << nl;
        } */

        if (it == st[p].end()) return -INF;
        else return (*it)[1];
    }
    ll tm = (tl + tr) / 2;
    return max(rmq(ty, 2 * p, tl, tm, l, min(r, tm), x),
        rmq(ty, 2 * p + 1, tm + 1, tr, max(l, tm + 1), r, x));
}

void solve(ll ty) {
    ll i, y, k;
    build(ty, 1, 0, ub);
    for (i = 1; i <= n; i++) {
        auto it = lower_bound(b + 1, b + n + 1, a[i]);
        y = it - b;
        if ((ty & 2) == 2) k = rmq(ty, 1, 0, ub, y, n, b[i]);
        else k = rmq(ty, 1, 0, ub, 1, y - 1, b[i]);
        res = max(res, abs(a[i] - b[i]) + (-1 + (ty & 2)) * a[i] + (1 - 2 * (ty & 1)) * b[i] + k);
        // cout << "solve " << ty _ i _ y _ abs(a[i] - b[i]) _ (-1 + (ty & 2)) * a[i] _ (1 - 2 * (ty & 1)) * b[i] _ k << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; v.pb({-INF, -INF});
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> b[i]; v.pb({b[i], a[i]});
    }

    sort(v.begin(), v.end());
    for (i = 1; i <= n; i++) {
        a[i] = v[i][1]; b[i] = v[i][0];
    }

    for (i = 0; i <= 3; i++) solve(i);

    res *= -1;
    for (i = 1; i <= n; i++) res += abs(a[i] - b[i]);

    cout << res << nl;

    return 0;
}