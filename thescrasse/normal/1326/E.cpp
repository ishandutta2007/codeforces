// 1326E
// Bombs

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, p[maxn], q[maxn], w[maxn];
ll st[1048586], lazy[1048586];
ll p2 = 524288;

void push(ll p) {
    if (p >= p2) return;
    ll k = lazy[p]; lazy[p] = 0;
    st[2 * p] += k; lazy[2 * p] += k;
    st[2 * p + 1] += k; lazy[2 * p + 1] += k;
    st[p] = max(st[2 * p], st[2 * p + 1]);
}

void upd(ll p, ll tl, ll tr, ll l, ll r, ll x) {
    if (l > r) return;
    push(p);
    if (l <= tl && tr <= r) {
        st[p] += x; lazy[p] += x; return;
    }
    ll tm = (tl + tr) / 2;
    upd(2 * p, tl, tm, l, min(r, tm), x);
    upd(2 * p + 1, tm + 1, tr, max(l, tm + 1), r, x);
    st[p] = max(st[2 * p], st[2 * p + 1]);
}

ll rmq(ll p, ll tl, ll tr, ll l, ll r) {
    if (l > r) return -INF;
    push(p);
    if (l <= tl && tr <= r) {
        return st[p];
    }
    ll tm = (tl + tr) / 2;
    return max(rmq(2 * p, tl, tm, l, min(r, tm)),
    rmq(2 * p + 1, tm + 1, tr, max(l, tm + 1), r));
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
        cin >> p[i]; w[p[i]] = i;
    }
    for (i = 1; i <= n; i++) {
        cin >> q[i];
    }

    for (i = 0; i < 2 * p2; i++) {
        if (i >= p2 && i < p2 + n) st[i] = 0;
        else st[i] = -INF;
    }

    for (i = p2 - 1; i > 0; i--) st[i] = max(st[2 * i], st[2 * i + 1]);

    res = n + 1;
    for (i = 1; i <= n; i++) {
        k = rmq(1, 1, p2, 1, n);
        while (rmq(1, 1, p2, 1, n) <= 0) {
            res--; upd(1, 1, p2, 1, w[res], 1);
            /* for (j = 1; j < 2 * p2; j++) {
                if (st[j] != 0 && st[j] != -INF) cout << j << " st = " << st[j] << nl;
                if (lazy[j] != 0 && lazy[j] != -INF) cout << j << " lazy = " << lazy[j] << nl;
            }
            cout << "---" << nl; */
        }
        cout << res << nl;
        upd(1, 1, p2, 1, q[i], -1);
    }

    return 0;
}