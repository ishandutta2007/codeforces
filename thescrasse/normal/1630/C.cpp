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
ll mn[maxn], mx[maxn], pl, pr, fn[maxn];
bool sk[maxn];
vector<array<ll, 2>> w, v;

bool cmp(array<ll, 2> a, array<ll, 2> b) {
    return (a[1] < b[1]);
}

void upd(ll p, ll x) {
    while (p < maxn) {
        fn[p] += x; p += (p & (-p));
    }
}

ll ps(ll p) {
    ll r = 0;
    while (p > 0) {
        r += fn[p]; p -= (p & (-p));
    }
    return r;
}

ll rs(ll l, ll r) {
    return ps(r) - ps(l - 1);
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
        mn[i] = INF; mx[i] = -INF;
    }
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        mn[a[i]] = min(mn[a[i]], i + 1);
        mx[a[i]] = max(mx[a[i]], i - 1);
    }

    for (i = 1; i <= n; i++) {
        if (mx[i] >= mn[i]) w.pb({mn[i], mx[i]});
    }

    sort(w.begin(), w.end());

    k = -INF;
    for (auto [l, r] : w) {
        if (r <= k) continue;
        v.pb({l, r}); k = r;
    }

    sort(v.begin(), v.end(), cmp);

    pl = -INF; pr = -INF;
    for (auto [l, r] : v) {
        // cout << l _ r _ pl _ pr << nl;
        if (l > pr + 1) {
            res += (r - l + 1); pl = l; pr = r;
        } else if (rs(l - 1, r + 1) >= 1) {
            res += (r - pr); pl = l; pr = r;
        } else {
            upd(pr + 1, 1);
            res += (r - pr - 1); pl = l; pr = r;
        }
        // cout << res << nl;
    }

    cout << res << nl;

    return 0;
}