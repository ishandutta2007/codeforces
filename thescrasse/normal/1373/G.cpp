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
#define sq 850

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll q, x, y, z;
multiset<ll> ms;
multiset<array<ll, 2>> qr;

struct bucket {
    ll mx;
    vector<ll> v;

    bucket(): mx(-INF), v({}) {}

    void upd_mx() {
        ll i;
        mx = -INF;
        for (i = 0; i < v.size(); i++) mx = max(mx, v[i] - i);
    }

    void ins(ll x) {
        // cout << "ins" _ x << nl;
        v.insert(lower_bound(v.begin(), v.end(), x), x); upd_mx();
    }

    void rm(ll x) {
        // cout << "rm" _ x << nl;
        v.erase(lower_bound(v.begin(), v.end(), x)); upd_mx();
    }

    void ins_back(ll x) {
        v.pb(x); mx = max(mx, x - (ll)v.size() + 1);
    }
};

struct sqrt_set {
    ll mx;
    vector<bucket> vb;

    sqrt_set(): mx(-INF), vb({}) {
        bucket b; vb.pb(b);
    }

    void sqrt_ins(ll x) {
        ll i, cr = 0, f = 1;
        mx = -INF;
        for (i = 0; i < vb.size(); i++) {
            if (f == 1 && (i == (ll)vb.size() - 1 || (!vb[i].v.empty() && vb[i].v.back() >= x))) {
                f = 0; vb[i].ins(x);
            }
            mx = max(mx, vb[i].mx - cr);
            cr += vb[i].v.size();
        }
    }

    void sqrt_rm(ll x) {
        ll i, cr = 0, f = 1;
        mx = -INF;
        for (i = 0; i < vb.size(); i++) {
            if (f == 1 && (!vb[i].v.empty() && vb[i].v.back() >= x)) {
                f = 0; vb[i].rm(x);
            }
            mx = max(mx, vb[i].mx - cr);
            cr += vb[i].v.size();
        }
    }

    void build() {
        ll cr = 0;
        vb.clear(); mx = -INF;
        bucket b; vb.pb(b);
        for (auto u : ms) {
            if (vb.back().v.size() == sq) {
                mx = max(mx, vb.back().mx - cr);
                bucket c; vb.pb(c); cr += sq;
            }
            vb.back().ins_back(u);
        }
        mx = max(mx, vb.back().mx - cr);
    }

    void dbg() {
        cout << "sqrt_mx =" _ mx << nl;
        for (auto u : vb) {
            cout << "mx =" _ u.mx << nl;
            for (auto e : u.v) cout << e << ' ';
            cout << nl;
        }
    }
};

sqrt_set ss;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> z >> q;
    for (i = 1; i <= q; i++) {
        cin >> x >> y; k = abs(x - z) + y;
        if (qr.find({x, y}) != qr.end()) {
            qr.erase({x, y}); ms.erase(ms.find(k)); ss.sqrt_rm(k);
        } else {
            qr.insert({x, y}); ms.insert(k); ss.sqrt_ins(k);
        }

        // ss.dbg();

        cout << max((ll)0, ss.mx + (ll)qr.size() - n - 1) << nl;

        if (i % 1500 == 0) ss.build();
    }

    return 0;
}