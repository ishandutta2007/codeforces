#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010
#define maxs 2097162

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
vector<array<ll, 2>> v;
vector<array<ll, 3>> cm;

bool cmp(array<ll, 2> a, array<ll, 2> b) {
    return (a[0] + a[1] < b[0] + b[1]);
}

struct segtree {
    array<ll, 2> st[maxs];
    ll lz[maxs];

    void push(ll p) {
        if (2 * p + 1 >= maxs) return;
        ll k = lz[p];
        lz[2 * p] += k; lz[2 * p + 1] += k; lz[p] = 0;
        st[2 * p][0] += k; st[2 * p + 1][0] += k;
    }

    void build(ll p = 1, ll tl = 0, ll tr = maxn) {
        if (tl > tr) return;

        if (tl == tr) {
            st[p] = {0, -tl}; return;
        }

        ll tm = (tl + tr) / 2;
        build(2 * p, tl, tm); build(2 * p + 1, tm + 1, tr);
        st[p] = max(st[2 * p], st[2 * p + 1]);
    }

    void upd(ll l, ll r, ll x, ll p = 1, ll tl = 0, ll tr = maxn) {
        if (l > r) return;
        // cout << "upd" _ l _ r _ x _ p _ tl _ tr << nf;

        push(p);
        if (tl == l && tr == r) {
            st[p][0] += x; lz[p] += x; return;
        }

        ll tm = (tl + tr) / 2;
        upd(l, min(tm, r), x, 2 * p, tl, tm);
        upd(max(tm + 1, l), r, x, 2 * p + 1, tm + 1, tr);
        st[p] = max(st[2 * p], st[2 * p + 1]);
    }

    array<ll, 2> rmq(ll l, ll r, ll p = 1, ll tl = 0, ll tr = maxn) {
        if (l > r) return {0, 0};
        // cout << "rmq" _ l _ r _ p _ tl _ tr << nf;

        push(p);
        if (tl == l && tr == r) return st[p];

        ll tm = (tl + tr) / 2;
        return max(rmq(l, min(tm, r), 2 * p, tl, tm),
            rmq(max(tm + 1, l), r, 2 * p + 1, tm + 1, tr));
    }

    void dbg(ll p = 1, ll tl = 0, ll tr = maxn) {
        // cout << "dbgdbg" _ p _ tl _ tr _ nf;
        if (tl > tr) return;

        push(p);
        if (tl == tr) {
            if (tl <= 10) cout << "dbg" _ tl _ st[p][0] _ st[p][1] << nl;
            return;
        }

        ll tm = (tl + tr) / 2;
        dbg(2 * p, tl, tm); dbg(2 * p + 1, tm + 1, tr);
    }
};

segtree st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m; v.pb({0, 0});
    for (i = 1; i <= n; i++) {
        cin >> a >> b;
        if (a >= m) v.pb({a, b});
    }
    n = (ll)v.size() - 1;

    sort(v.begin() + 1, v.end(), cmp);

    cm.pb({0, 0, 0});
    for (i = 1; i <= n; i++) {
        cm.pb({v[i][0], i, 0}); cm.pb({v[i][1], i, 1});
    }

    sort(cm.begin() + 1, cm.end());
    for (i = 1; i <= 2 * n; i++) {
        v[cm[i][1]][cm[i][2]] = i;
    }

    for (i = 1; i <= n; i++) {
        k = st.rmq(1, min(v[i][0], v[i][1]))[0] + 1;
        m = st.rmq(v[i][1], v[i][1])[0];
        st.upd(v[i][1], v[i][1], k - m);
        if (v[i][0] > v[i][1]) {
            st.upd(v[i][1] + 1, v[i][0], 1);
        }
    }

    res = st.rmq(1, 2 * n)[0];
    cout << res << nl;

    return 0;
}