// 1404C
// Fixed Point Removal

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res[maxn], flag[10], a[maxn], b, fn[maxn], p, x, y, c, q;
vector<array<ll, 3>> qr;
array<ll, 3> o;

void upd(ll x, ll p) {
    while (p <= n) {
        fn[p] += x;
        p += (p & (-p));
    }
}

ll ps(ll p) {
    ll r = 0;
    while (p > 0) {
        r += fn[p];
        p -= (p & (-p));
    }
    return r;
}

ll rs(ll l, ll r) {
    return ps(r) - ps(l - 1);
}

void rupd(ll x, ll l, ll r) {
    upd(x, l); upd(-x, r + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > i) a[i] = INF;
        else a[i] = i - a[i];
    }

    for (i = 0; i < q; i++) {
        cin >> x >> y;
        qr.pb({n - y, x + 1, i});
    }

    sort(qr.begin(), qr.end()); reverse(qr.begin(), qr.end());

    for (auto &u : qr) swap(u[0], u[1]);

    for (i = 1; i <= n; i++) {
        p = 0; k = a[i]; c = 0;
        for (b = (1 << 30); b > 0; b >>= 1) {
            if (p + b > i) continue;
            x = fn[p + b];
            if (c + x >= k) {
                p += b; c += x;
            }
        }

        // cout << "p = " << p << nl;

        rupd(1, 1, p);

        /* for (j = 1; j <= n; j++) {
            cout << ps(j) << ' ';
        }
        cout << nl; */

        while (true) {
            if (qr.empty()) break;
            o = qr.back();
            if (o[1] != i) break;
            qr.pop_back();
            res[o[2]] = ps(o[0]);
        }
    }

    for (i = 0; i < q; i++) {
        cout << res[i] << nl;
    }

    return 0;
}