// 1147D
// Palindrome XOR

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x, ls;
string s;
bool vis[maxn];
vector<ll> adj[maxn];

void dfs(ll s) {
    if (vis[s]) return;
    vis[s] = true; ls = s;
    if (a[s] == 0 || a[s] == 1) x ^= a[s];
    else k++;
    for (auto u : adj[s]) dfs(u);
}

void init(ll m) {
    ll i, tt;

    for (i = 1; i <= n; i++) vis[i] = false;
    for (i = 1; i <= n; i++) adj[i].clear();
    for (i = 1; i <= n; i++) adj[i].pb(n - i + 1);
    for (i = m + 1; i <= n; i++) adj[i].pb(n - i + m + 1);

    tt = 1;
    for (i = 1; i <= n; i++) {
        if (vis[i]) continue;
        k = 0; x = 0; dfs(i);
        if (k == 0 && x == 1 && ls != i && ls <= m) tt = 0;
        if (ls != i && ls <= m) k--;
        for (j = 1; j <= k; j++) tt = (2 * tt) % mod;

        // cout << m _ i _ tt << nl;
    }
    res += tt; res %= mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> s; n = s.size(); s = '#' + s;

    for (i = 1; i <= n; i++) a[i] = (ll)s[i] - '0';
    if (a[n] == 1) {
        cout << 0 << nl; return 0;
    } else {
        a[n] = 0;
    }

    for (i = 1; i <= n - 1; i++) init(i);

    cout << res << nl;

    return 0;
}