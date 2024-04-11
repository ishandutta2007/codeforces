// 1469F
// Power Sockets

// I wanted to write 10 segtrees before tst
// I ended up writing only 1 (inefficient) segtree
// (yes, I know there is a O(n) solution but I'm too lazy to find a problem that actually requires segtree)

// I did it (in 90 minutes) but without cp-algorithms :D
// now I will get runtime error on test 6

// it's range sum, not range min :/

// let's try bs in log(n)

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
#define ub 200110
#define maxs 1050000

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll st[maxs], lz[maxs];

void push(ll p, ll tl, ll tr) {
    ll k = lz[p];
    lz[p] = 0;
    if (2 * p + 1 >= maxs) return;
    ll tm = (tl + tr) / 2;
    st[2 * p] += k * (tm - tl + 1); st[2 * p + 1] += k * (tr - tm);
    lz[2 * p] += k; lz[2 * p + 1] += k;
}

/*
p = current node in st
[tl, tr] = interval of p
[l, r] = interval of query inside p
x = value to add
*/

void upd(ll p, ll tl, ll tr, ll l, ll r, ll x) {
    // cout << "upd " << p _ tl _ tr _ l _ r _ x << nl;
    if (l > r) return;
    push(p, tl, tr);
    if (tl == l && tr == r) {
        st[p] += x * (tr - tl + 1); lz[p] += x; return;
    }
    ll tm = (tl + tr) / 2;
    upd(2 * p, tl, tm, l, min(tm, r), x);
    upd(2 * p + 1, tm + 1, tr, max(tm + 1, l), r, x);
    st[p] = st[2 * p] + st[2 * p + 1];
}

ll rsq(ll p, ll tl, ll tr, ll l, ll r) {
    // cout << "rsq " << p _ tl _ tr _ l _ r << nl;
    if (l > r) return 0;
    push(p, tl, tr);
    // cout << st[p] << nl;
    if (tl == l && tr == r) return st[p];
    ll tm = (tl + tr) / 2;
    return rsq(2 * p, tl, tm, l, min(tm, r)) +
    rsq(2 * p + 1, tm + 1, tr, max(tm + 1, l), r);
}

ll bs(ll p, ll tl, ll tr, ll x) {
    push(p, tl, tr);
    if (st[p] < x) return INF;
    if (tl == tr) return tl;
    ll tm = (tl + tr) / 2;
    if (st[2 * p] >= x) return bs(2 * p, tl, tm, x);
    else return bs(2 * p + 1, tm + 1, tr, x - st[2 * p]);
}

void cln() {
    ll i;
    for (i = 0; i <= ub; i++) upd(1, 0, ub, i, i, 0);
}

void dbg() {
    cln();
    for (ll i = 0; i <= 10; i++) {
        cout << rsq(1, 0, ub, i, i) << ' ';
    }
    cout << nl;
    /* for (ll i = 0; i <= 150; i++) cout << st[i] << ' ';
    cout << nl; */
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k; res = INF;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);

    upd(1, 0, ub, 0, 0, 1);
    for (i = 1; i <= n; i++) {
        while (rsq(1, 0, ub, m, m) == 0) m++;
        upd(1, 0, ub, m, m, -1);
        upd(1, 0, ub, m + 2, m + ((a[i] + 1) / 2), 2);
        if (a[i] % 2 == 0) {
            upd(1, 0, ub, m + ((a[i] + 2) / 2), m + ((a[i] + 2) / 2), 1);
        }
        // dbg();
        res = min(res, bs(1, 0, ub, k));
    }

    if (res == INF) cout << -1 << nl;
    else cout << res << nl;

    return 0;
}