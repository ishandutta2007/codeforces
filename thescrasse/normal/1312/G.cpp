#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define tm grewiogneiwgn

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b[maxn];
ll w, dp[maxn], tm[maxn], pr[maxn], cr;
char c;
bool gd[maxn];
vector<array<ll, 2>> adj[maxn];
multiset<ll> ms;

bool cmp(array<ll, 2> a, array<ll, 2> b) {
    return (a[1] < b[1]);
}

ll msm() {
    return (*ms.begin());
}

void dfs(ll s) {
    if (s != 0) dp[s] = dp[pr[s]] + 1;
    tm[s] = cr;
    if (gd[s]) {
        cr++;
        if (s != 0) dp[s] = min(dp[s], msm() + tm[s] + 1);
    }
    ms.insert(dp[s] - tm[s]);
    // cout << "dfs" _ s _ dp[s] << nl;

    sort(adj[s].begin(), adj[s].end(), cmp);
    for (auto [u, w] : adj[s]) dfs(u);
    ms.erase(ms.find(dp[s] - tm[s]));
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
        cin >> a >> c; w = (ll)c - 'a';
        adj[a].pb({i, w}); pr[i] = a;
    }
    cin >> m;
    for (i = 1; i <= m; i++) {
        cin >> b[i]; gd[b[i]] = true;
    }

    dfs(0);

    for (i = 1; i <= m; i++) cout << dp[b[i]] << ' ';
    cout << nl;

    return 0;
}