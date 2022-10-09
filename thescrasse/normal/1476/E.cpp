#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn], visited[maxn];
string s[maxn], f[maxn], o;
map<string, ll> mp;
vector<ll> adj[maxn], ts;

void dfs(ll s) {
    // cout << "dfs " << s << nl;
    if (visited[s] == 1) flag[0] = 0;
    if (visited[s] > 0) return;
    visited[s] = 1;
    for (auto u : adj[s]) dfs(u);
    visited[s] = 2; ts.pb(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> k; flag[0] = 1;
    for (i = 1; i <= n; i++) {
        cin >> s[i]; mp[s[i]] = i;
    }
    for (i = 1; i <= m; i++) {
        cin >> f[i] >> mt[i];
    }

    for (i = 1; i <= m; i++) {
        flag[1] = 0;
        for (j = 0; j < 16; j++) {
            o = f[i];
            for (k = 0; k < 4; k++) {
                if ((j >> k) & 1) o[k] = '_';
            }

            k = mp[o];
            if (k == mt[i]) flag[1] = 1;
            if (k == 0 || k == mt[i]) continue;
            adj[mt[i]].pb(k);
            // cout << i _ j _ mp[o] << nl;
        }

        if (flag[1] == 0) {
            cout << "NO" << nl; return 0;
        }
    }

    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) dfs(i);
    }

    reverse(ts.begin(), ts.end());
    if (flag[0] == 0) {
        cout << "NO" << nl; return 0;
    }

    cout << "YES" << nl;
    for (auto u : ts) cout << u << ' ';
    cout << nl;

    return 0;
}