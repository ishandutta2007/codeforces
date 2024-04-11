// 1508D
// Swap Pass

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll x[maxn], y[maxn], c, cc[maxn], sz;
bool vis[maxn];
vector<array<ll, 3>> v;
vector<array<ll, 2>> rs;
array<ll, 2> o;

bool cmp(array<ll, 3> a, array<ll, 3> b) {
    return (a[1] * b[2] < a[2] * b[1]);
}

void dfs(ll s, ll k) {
    if (vis[s]) return;
    vis[s] = true; cc[s] = k;
    dfs(a[s], k);
}

void swp(ll x, ll y) {
    swap(a[x], a[y]); rs.pb({x, y});
}

void find_cc() {
    // too lazy to write nlog(n)
    ll i;
    for (i = 1; i <= n; i++) vis[i] = false;
    for (i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; o = {INF, INF};
    for (i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> a[i];
        if (a[i] == i) continue;
        o = min(o, {x[i], i});
    }

    if (o[0] == INF) {
        cout << 0 << nl; return 0;
    }

    c = o[1];
    for (i = 1; i <= n; i++) {
        if (a[i] == i || i == c) continue;
        v.pb({i, x[i] - x[c], y[i] - y[c]});
    }

    sort(v.begin(), v.end(), cmp);

    // for (auto u : v) cout << u[0] _ u[1] _ u[2] << nl;

    sz = v.size();
    for (i = 0; i < sz - 1; i++) {
        find_cc();
        if (cc[v[i][0]] != cc[v[i + 1][0]]) swp(v[i][0], v[i + 1][0]);
    }

    while (a[c] != c) swp(c, a[c]);

    cout << rs.size() << nl;
    for (auto u : rs) cout << u[0] _ u[1] << nl;

    return 0;
}