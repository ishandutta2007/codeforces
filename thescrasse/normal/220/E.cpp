// 220E
// Little Elephant and Inversions

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, fn[maxn][2], nv, l, r;
vector<array<ll, 2>> cm;

void upd(ll o, ll p, ll x) {
    // cout << "upd " << p << ' ' << x << nf;
    while (p <= n) {
        fn[p][o] += x;
        p += p & (-p);
    }
}

ll ps(ll o, ll p) {
    // cout << "ps " << p << nf;
    ll r = 0;
    while (p > 0) {
        r += fn[p][o];
        p -= p & (-p);
    }

    return r;
}

ll rs(ll o, ll l, ll r) {
    if (l == 1) return ps(o, r);
    if (l > n || r <= 0) return 0;
    return ps(o, r) - ps(o, l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> a[i]; cm.pb({a[i], i});
    }

    for (i = 1; i <= n; i++) {
        fn[i][0] = 0; fn[i][1] = 0;
    }

    sort(cm.begin(), cm.end());
    for (i = 0; i < n; i++) {
        a[cm[i][1]] = i + 1;
    }

    nv = 0;
    for (i = 0; i < n; i++) {
        nv += rs(0, a[i] + 1, n);
        upd(0, a[i], 1);
    }

    for (i = 1; i <= n; i++) {
        fn[i][0] = 0; fn[i][1] = 0;
    }

    upd(0, a[0], 1);
    for (i = 1; i < n; i++) upd(1, a[i], 1);

    l = 0; r = 1; res = 0;
    while (r < n) {
        // cout << l << ' ' << r << nf;
        if (nv > k || l == r - 1) {
            if (nv <= k && l == r - 1) res++;
            // cout << "r" << nl;
            nv -= rs(0, a[r] + 1, n);
            nv -= rs(1, 1, a[r] - 1);
            upd(1, a[r], -1);
            r++;
        } else {
            // cout << "l" << nl;
            l++; res += (n - r);
            nv += rs(0, a[l] + 1, n);
            nv += rs(1, 1, a[l] - 1);
            upd(0, a[l], 1);
        }
        // cout << nv << nl;
    }

    cout << res;

    return 0;
}