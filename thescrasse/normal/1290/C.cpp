// 1290C
// Prefix Enlightenment

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll parent[maxn], sz[maxn], dc[maxn], r[maxn], s1[maxn];
string s;
vector<ll> adj[maxn];

array<ll, 2> find(ll a) {
    ll x = 0;
    while (a != parent[a]) {
        x ^= dc[a]; a = parent[a];
    }
    return {a, x};
}

bool same(ll a, ll b) {
    return find(a)[0] == find(b)[0];
}

ll pts(ll a, ll k) {
    // cout << "pts " << a << nl;
    a = find(a)[0];
    if (r[a] == -1) return min(s1[a], sz[a] - s1[a]);
    else if (r[a] ^ k == 0) return s1[a];
    else return sz[a] - s1[a];
}

void merge(ll a, ll b, ll x) {
    // cout << "merge " << a << ' ' << b << ' ' << x << nl;
    array<ll, 2> c, d;
    c = find(a); d = find(b);
    if (sz[c[0]] < sz[d[0]]) swap(c, d);
    res -= pts(c[0], 0); res -= pts(d[0], 0);

    ll y = x ^ c[1] ^ d[1];

    parent[d[0]] = c[0]; dc[d[0]] = y;
    sz[c[0]] += sz[d[0]];

    if (y == 0) s1[c[0]] += s1[d[0]];
    else s1[c[0]] += sz[d[0]] - s1[d[0]];

    if (r[c[0]] == -1 && r[d[0]] != -1) {
        r[c[0]] = y ^ r[d[0]];
    }

    res += pts(c[0], 0);
}

void upd(ll a, ll x) {
    // cout << "upd " << a << ' ' << x << nl;
    array<ll, 2> c = find(a);
    res -= pts(c[0], 0);
    // if (x == 1 && r[a] != 1) s1[a] = sz[a] - s1[a];
    r[c[0]] = x ^ c[1]; res += pts(c[0], 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k >> s;
    for (i = 0; i < k; i++) {
        cin >> m;
        for (j = 0; j < m; j++) {
            cin >> a; adj[a].pb(i + 1);
        }
    }

    for (i = 1; i <= k; i++) {
        parent[i] = i; sz[i] = 1; dc[i] = 0; r[i] = -1; s1[i] = 0;
    }

    res = 0;
    for (i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            a = adj[i][0];
            upd(a, ((ll)s[i - 1] + 1) % 2);
        }
        if (adj[i].size() == 2) {
            a = adj[i][0]; b = adj[i][1];
            if (!same(a, b)) merge(a, b, ((ll)s[i - 1] + 1) % 2);
        }
        cout << res << nl;

        /* cout << nl;
        for (j = 1; j <= k; j++) {
            cout << j << nl;
            cout << parent[j] << ' ' << sz[j] << ' ' << dc[j] << ' ' << r[j] << ' ' << s1[j] << ' ' << pts(j, 0) << nl << nl;
        }
        cout << "-------" << nl; */
    }

    return 0;
}