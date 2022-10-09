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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x, y, e, f;
vector<ll> adj[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == a[i - 1]) continue;
        adj[a[i]].pb(i);
    }
    for (i = 0; i <= n; i++) adj[i].pb(INF);

    for (i = 1; i <= n; i++) reverse(adj[i].begin(), adj[i].end());

    for (i = 1; i <= n; i++) {
        k = a[i];
        if (k == a[i - 1]) continue;
        adj[a[i]].pop_back();

        if (k == x || k == y) continue;

        res++;
        if (adj[x].back() < adj[y].back()) y = k;
        else x = k;

        /* cout << i _ k _ x _ y << nl;
        for (j = 1; j <= n; j++) {
            for (auto u : adj[j]) cout << u << ' ';
            cout << nl;
        } */
    }

    cout << res << nl;

    return 0;
}