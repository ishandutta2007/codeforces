// 1511G
// Chips on a Board

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010
#define maxf 525000

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, f[maxn];
ll q, l[maxn], r[maxn], fn[19][maxf], px[maxn], rss[maxn];
vector<ll> rb[maxn];

void upd(ll ty, ll p, ll x) {
    // cout << "upd " << ty _ p _ x << nl;
    p++;
    while (p < maxf) {
        fn[ty][p] += x;
        p += (p & (-p));
    }
}

ll ps(ll ty, ll p) {
    // cout << "ps " << ty _ p << nl;
    ll r = 0; p++;
    while (p > 0) {
        r += fn[ty][p];
        p -= (p & (-p));
    }
    return r;
}

ll rs(ll ty, ll l, ll r) {
    return ps(ty, r) - ps(ty, l - 1);
}

ll cs(ll ty, ll sh) {
    ll k = (1 << ty);
    if (sh > k) return rs(ty, -k + sh, sh - 1);
    else return rs(ty, 0, sh - 1) + rs(ty, k + sh, 2 * k - 1);
}

void dbg(ll ty) {
    cout << "dbg " << ty << nl;
    for (ll i = 0; i <= (1 << (ty + 1)) - 1; i++) {
        cout << rs(ty, i, i) << ' ';
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

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; f[a[i]]++;
    }

    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> l[i] >> r[i]; rb[r[i]].pb(i);
    }

    for (i = m; i >= 1; i--) {
        for (b = 0; b < 19; b++) {
            k = i % (1 << (b + 1));
            upd(b, k, f[i]);
            px[i] ^= (1 << b) * (cs(b, k) % 2);
            for (auto u : rb[i - 1]) {
                rss[u] ^= (1 << b) * (cs(b, l[u] % (1 << (b + 1))) % 2);
            }
        }
        // dbg(0); dbg(1); dbg(2); dbg(3);
        // for (auto u : rb[i]) cout << u _ rss[u] << nl;
    }

    /* for (i = 1; i <= m; i++) {
        cout << i _ px[i] << nl;
    } */

    for (i = 1; i <= q; i++) {
        res = px[l[i]] ^ rss[i];
        if (res == 0) cout << "B";
        else cout << "A";
    }
    cout << nl;

    return 0;
}