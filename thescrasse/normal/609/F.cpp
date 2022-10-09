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
#define ub 200020
#define maxs 525000

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, s, z;
ll l[maxn], r[maxn], x[maxn], sz[maxn], st[maxs], rs[maxn];
vector<array<ll, 2>> v;
map<ll, ll> mp;
multiset<array<ll, 2>> ms;

void upd(ll p, ll tl, ll tr, ll l, ll r, ll x) {
    /* if (p >= 2 && p <= 10000000) {
        cout << "upd " << p _ tl _ tr _ l _ r _ x << nf;
    } */
    if (l > r) return;
    if (tl == l && tr == r) {
        st[p] += x; return;
    }
    ll tm = (tl + tr) / 2;
    upd(2 * p, tl, tm, l, min(r, tm), x);
    upd(2 * p + 1, tm + 1, tr, max(l, tm + 1), r, x);
    st[p] = max(st[2 * p], st[2 * p + 1]);
}

ll rmq(ll p, ll tl, ll tr, ll l, ll r) {
    /* if (p >= 2 && p <= 10000000) {
        cout << "rmq " << p _ tl _ tr _ l _ r << nf;
    } */
    if (l > r) return -INF;
    if (tl == l && tr == r) {
        return st[p];
    }
    ll tm = (tl + tr) / 2;
    return max(rmq(2 * p, tl, tm, l, min(r, tm)),
    rmq(2 * p + 1, tm + 1, tr, max(l, tm + 1), r));
}

ll bs(ll p, ll tl, ll tr, ll x) {
    // cout << "bs " << p _ tl _ tr _ x << nl;
    if (tl == tr) {
        if (st[p] >= x) return tl;
        else return -1;
    }
    ll tm = (tl + tr) / 2;
    if (st[2 * p] >= x) return bs(2 * p, tl, tm, x);
    else return bs(2 * p + 1, tm + 1, tr, x);
}

void dbg() {
    for (ll i = 1; i <= n; i++) {
        cout << rmq(1, 0, ub, i, i) << ' ';
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m; v.pb({-1, -1});
    for (i = 1; i <= n; i++) {
        cin >> l[i] >> r[i]; r[i] += l[i]; v.pb({l[i], r[i]});
    }
    for (i = 1; i <= m; i++) {
        cin >> x[i] >> sz[i];
    }

    upd(1, 0, ub, 0, 0, -INF);
    sort(v.begin(), v.end());
    for (i = 1; i <= n; i++) {
        mp[v[i][0]] = i;
        upd(1, 0, ub, i, i, v[i][1]);
    }

    for (i = 1; i <= m; i++) {
        s = bs(1, 0, ub, x[i]);
        if (s <= 0 || s > n || v[s][0] > x[i]) {
            ms.insert({x[i], sz[i]});
        } else {
            k = rmq(1, 0, ub, s, s); z = k; k += sz[i]; rs[s]++;
            while (true) {
                if (ms.empty()) break;
                array<ll, 2> o = {v[s][0], -INF};
                auto it = ms.lower_bound(o);
                if (it == ms.end()) break;
                if ((*it)[0] > k) break;
                k += (*it)[1]; ms.erase(it); rs[s]++;
            }
            upd(1, 0, ub, s, s, k - z);
        }
        // dbg();
    }

    for (i = 1; i <= n; i++) {
        s = mp[l[i]];
        cout << rs[s] << ' ' << rmq(1, 0, ub, s, s) - v[s][0] << nl;
    }

    return 0;
}