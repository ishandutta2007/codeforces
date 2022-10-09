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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll q, st, d, p, w, rp, fn[maxn], pr[maxn], sz[maxn];
ll sl, sr, l, r, ty, rs[maxn];
array<ll, 3> mx;
vector<ll> cm[maxn];
vector<array<ll, 2>> nn;
vector<array<ll, 3>> v, el;

bool cmp(array<ll, 3> a, array<ll, 3> b) {
    return (a[2] < b[2]);
}

void upd(ll p, ll x) {
    while (p < maxn) {
        fn[p] += x; p += (p & (-p));
    }
}

ll ps(ll p) {
    // cout << "ps" _ p << nf;
    ll r = 0;
    p = max(p, (ll)0); p = min(p, (ll)maxn - 1);
    while (p > 0) {
        r += fn[p]; p -= (p & (-p));
    }
    // cout << "r =" _ r << nf;
    return r;
}

ll bs(ll x) { // first >=
    ll i, p = 0, r = 0;
    for (i = 524288; i >= 1; i /= 2) {
        if (p + i < maxn && r + fn[p + i] < x) {
            r += fn[p + i]; p += i;
        }
    }
    if (p == 0 || p == maxn - 1) return INF;
    return (p + 1);
}

ll find(ll x) {
    if (x == pr[x]) return x;
    return pr[x] = find(pr[x]);
}

bool same(ll a, ll b) {
    return (find(a) == find(b));
}

void onion(ll a, ll b) {
    ll x = a, y = b;
    a = find(a); b = find(b);
    if (a == b) return;
    if (ty == 1) el.pb({x, y, abs(abs(x - y) - d)});
    if (sz[a] < sz[b]) swap(a, b);
    pr[b] = a; sz[a] += sz[b];
    for (auto u : cm[b]) cm[a].pb(u);
    cm[b].clear();
}

void rst() {
    ll i, j;
    for (j = 1; j <= n; j++) {
        i = a[j];
        pr[i] = i; sz[i] = 1; upd(i, 1);
        cm[i].clear(); cm[i].pb(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q >> st >> d;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    st = a[st];
    for (i = 1; i <= q; i++) {
        cin >> p >> w; v.pb({i, a[p], w});
    }
    sort(v.begin(), v.end(), cmp);

    rst();

    ty = 1;
    for (rp = 1; rp <= 20; rp++) {
        // cout << "rp =" _ rp << nf;
        nn.clear();
        for (j = 1; j <= n; j++) {
            i = a[j];
            // cout << "i =" _ i << nf;
            if (pr[i] != i || sz[i] == n) continue;
            for (auto u : cm[i]) upd(u, -1);

            mx = {INF, INF, INF};
            for (auto u : cm[i]) {
                // cout << "u =" _ u << nf;
                sl = ps(u - d); sr = ps(u + d);
                // cout << "sl, sr =" _ sl _ sr << nl;
                k = bs(sl); mx = min(mx, {abs(k - (u - d)), k, u});
                // cout << "cand" _ abs(k - (u - d)) _ k << nl;
                k = bs(sl + 1); mx = min(mx, {abs(k - (u - d)), k, u});
                // cout << "cand" _ abs(k - (u - d)) _ k << nl;
                k = bs(sr); mx = min(mx, {abs(k - (u + d)), k, u});
                // cout << "cand" _ abs(k - (u + d)) _ k << nl;
                k = bs(sr + 1); mx = min(mx, {abs(k - (u + d)), k, u});
                // cout << "cand" _ abs(k - (u + d)) _ k << nl;
            }
            nn.pb({mx[2], mx[1]});
            // cout << "ins" _ mx[2] _ mx[1] << nl;

            for (auto u : cm[i]) upd(u, 1);
        }

        for (auto [x, y] : nn) onion(x, y);
    }

    ty = 2;
    el.pb({1, 1, INF}); sort(el.begin(), el.end(), cmp);
    rst(); i = 0;
    for (auto [x, y, w] : el) {
        // cout << "x, y, w =" _ x _ y _ w << nl;
        while (i < v.size() && v[i][2] < w) {
            rs[v[i][0]] = same(st, v[i][1]); i++;
        }
        onion(x, y);
    }

    for (i = 1; i <= q; i++) {
        if (rs[i] == 1) cout << "Yes" << nl;
        else cout << "No" << nl;
    }

    return 0;
}