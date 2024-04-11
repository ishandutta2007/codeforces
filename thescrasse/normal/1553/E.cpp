#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll cn[maxn];
bool vis[maxn];
vector<ll> rs;

void dfs(ll s) {
    if (vis[s]) return;
    vis[s] = true; dfs(b[s]);
}

bool solve() {
    ll i, rs = 0;
    for (i = 0; i <= n - 1; i++) vis[i] = false;
    for (i = 0; i <= n - 1; i++) {
        if (vis[i]) continue;
        rs++; dfs(i);
    }

    /* for (i = 0; i <= n - 1; i++) cout << b[i] << ' ';
    cout << nl;
    cout << "rs = " << rs << nl; */
    if (rs >= n - m) return true;
    return false;
}

void reset() {
    ll i;
    res = 0; rs.clear();
    for (i = 0; i <= n; i++) {
        vis[i] = false; cn[i] = 0;
    }
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
        cin >> n >> m; reset();
        for (i = 0; i <= n - 1; i++) {
            cin >> a[i]; a[i]--;
            cn[(a[i] - i + n) % n]++;
        }

        /* cout << "cn: ";
        for (i = 0; i <= n - 1; i++) cout << cn[i] << ' ';
        cout << nl; */

        for (i = 0; i <= n - 1; i++) {
            if (cn[i] < n / 3) continue;

            for (j = 0; j <= n - 1; j++) b[(i + j) % n] = a[j];
            if (solve()) {
                res++;
                if (i == 0) rs.pb(0);
                else rs.pb(n - i);
            }
        }

        sort(rs.begin(), rs.end());
        cout << res << ' ';
        for (auto u : rs) cout << u << ' ';
        cout << nl;
    }

    return 0;
}