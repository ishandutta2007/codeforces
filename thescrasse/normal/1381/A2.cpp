#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, tc, n, m, res, flag[10], a, b, fn[maxn], rq[maxn], x, rl[maxn], rr[maxn];
string s, t;
vector<ll> vr;

void upd(ll p, ll x) {
    while (p <= n + 1) {
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

void upt(ll l, ll r, ll x) {
    upd(l, x); upd(r + 1, -x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> tc;
    while (tc--) {
        vr.clear();
        cin >> n >> s >> t; k = 0;

        for (i = 0; i <= n + 1; i++) fn[i] = 0;
        for (i = 0; i < n; i++) {
            // cout << i << ' ' << (ll)s[i] - 48 << nl;
            upt(i + 1, i + 1, (ll)s[i] - 48);
        }

        // for (j = 1; j <= n + 1; j++) cout << ps(j) << ' ';
        // cout << nl;

        // cout << "ok" << nf;

        for (i = 1; i <= n; i++) {
            if (i % 2 == 1) rq[i] = (i + 1) / 2;
            else rq[i] = n + 1 - rq[i - 1];
            rl[i] = (i + 2) / 2;
            rr[i] = n + 1 - rl[i] + (i % 2 == 0);

            // cout << rq[i] << ' ' << rl[i] << ' ' << rr[i] << nl;
        }

        // cout << "ok" << nf;

        for (i = 1; i <= n; i++) {
            // cout << "i = " << i << nl;
            x = ps(rq[i]);

            // cout << "ps = " << x << nl;

            x += (t[n - i] == '1'); x++;
            x %= 2;

            if (x == 1) {
                vr.pb(1); upt(rq[i], rq[i], 1);
            }

            vr.pb(n + 1 - i); upt(rl[i], rr[i], 1);

            // for (j = 1; j <= n + 1; j++) cout << ps(j) << ' ';
            // cout << nl;
        }

        // cout << "ok" << nf;

        cout << vr.size() << ' ';
        for (auto u : vr) cout << u << ' ';
        cout << nl;
    }

    return 0;
}