#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 500010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll ps[maxn], dp[maxn], fs[maxn];
vector<array<ll, 2>> cm;

struct fenwick {
    vector<ll> fn;

    fenwick() {}

    fenwick(ll len) {
        fn.resize(len + 5);
        for (auto &u : fn) u = -INF;
    }

    void upd(ll p, ll x) {
        // cout << "upd" _ p _ x << nf;
        while (p < fn.size()) {
            fn[p] = max(fn[p], x); p += (p & (-p));
        }
    }

    ll pm(ll p) {
        ll r = -INF;
        while (p > 0) {
            r = max(r, fn[p]); p -= (p & (-p));
        }
        // cout << "pm" _ p _ r << nf;
        return r;
    }
};

fenwick fl;

void rst() {
    for (i = 0; i <= n + 5; i++) fs[i] = -INF;
    fl = fenwick(n); cm.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; rst();
        for (i = 1; i <= n; i++) {
            cin >> a[i]; ps[i] = ps[i - 1] + a[i];
        }

        cm.pb({-INF, -INF});
        for (i = 0; i <= n; i++) cm.pb({ps[i], i});

        sort(cm.begin(), cm.end());
        for (i = 1; i <= n + 1; i++) {
            if (cm[i][0] == cm[i - 1][0]) ps[cm[i][1]] = ps[cm[i - 1][1]];
            else ps[cm[i][1]] = i;
        }

        /* for (i = 0; i <= n; i++) cout << ps[i] << ' ';
        cout << nf; */

        dp[0] = 0; fl.upd(ps[0], 0);

        for (i = 1; i <= n; i++) {
            dp[i] = max({dp[i - 1] + (a[i] > 0) - (a[i] < 0),
                        fl.pm(ps[i] - 1) + i,
                        fs[ps[i]]});
            fl.upd(ps[i], dp[i] - i); fs[ps[i]] = max(fs[ps[i]], dp[i]);
        }

        /* for (i = 0; i <= n; i++) cout << dp[i] << ' ';
        cout << nf; */

        cout << dp[n] << nl;
    }

    return 0;
}