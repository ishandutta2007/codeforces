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
#define maxb 1048586

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
bool vis[maxb];
vector<ll> rs;
deque<array<ll, 2>> dq;
vector<array<ll, 2>> adj[maxb];

void rotate() {
    if (dq.empty()) return;
    array<ll, 2> x = dq.back(); dq.pop_back(); dq.push_front(x);
}

bool solve(ll p) {
    ll i, k, s, st, x, y;
    dq.clear();
    for (i = 0; i < maxb; i++) {
        adj[i].clear(); vis[i] = false;
    }
    for (i = 1; i <= n; i++) {
        x = (a[i] & ((1 << p) - 1)); y = (b[i] & ((1 << p) - 1));
        adj[x].pb({y, i}); adj[y].pb({x, i});
    }

    for (i = 0; i < maxb; i++) {
        if ((ll)adj[i].size() % 2 == 1) return false;
    }

    k = n; st = 0;
    while (st <= 2 * n + 3) {
        if (!dq.empty()) s = dq.back()[0];
        else s = x;
        if (!adj[s].empty()) {
            st = 0;
            while (!adj[s].empty()) {
                auto [u, z] = adj[s].back(); adj[s].pop_back();
                if (vis[z]) continue;
                vis[z] = true; dq.push_back({u, z}); k--; break;
            }
        } else {
            rotate(); st++;
        }
    }

    return (k == 0);
}

void find_res(ll ty) {
    m = dq[0][1]; rs.clear();
    if (ty == 0) {
        k = 2 * m; rs.pb(k - 1); rs.pb(k);
    } else {
        k = 2 * m - 1; rs.pb(k + 1); rs.pb(k);
    }
    for (j = 1; j <= n - 1; j++) {
        m = dq[j][1];
        if (k % 2 == 0 && ((b[(k + 1) / 2] & ((1 << i) - 1)) == (b[m] & ((1 << i) - 1)))) {
            k = 2 * m - 1; rs.pb(k + 1); rs.pb(k);
        } else if (k % 2 == 1 && ((a[(k + 1) / 2] & ((1 << i) - 1)) == (b[m] & ((1 << i) - 1)))) {
            k = 2 * m - 1; rs.pb(k + 1); rs.pb(k);
        } else if (k % 2 == 0 && ((b[(k + 1) / 2] & ((1 << i) - 1)) == (a[m] & ((1 << i) - 1)))) {
            k = 2 * m; rs.pb(k - 1); rs.pb(k);
        } else if (k % 2 == 1 && ((a[(k + 1) / 2] & ((1 << i) - 1)) == (a[m] & ((1 << i) - 1)))) {
            k = 2 * m; rs.pb(k - 1); rs.pb(k);
        } else {
            return;
        }
    }

    cout << i << nl;
    for (auto u : rs) cout << u << ' ';
    cout << nl;
    exit(0);
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
        cin >> a[i] >> b[i];
    }

    for (i = 20; i >= 0; i--) {
        if (solve(i)) {
            find_res(0); find_res(1);
        }
    }

    return 0;
}