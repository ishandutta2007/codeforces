#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x[maxn], y[maxn], parent[maxn], sz[maxn];
vector<ll> adj[maxn];
bool visited[maxn];

ll find(ll x) {
    // cout << "find " << x << nl;
    while (x != parent[x]) x = parent[x];
    // cout << x << nl;
    return x;
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

void merge(ll a, ll b) {
    a = find(a); b = find(b);
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a; sz[a] += sz[b];
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
        cin >> n >> m;
        for (i = 1; i <= m; i++) {
            cin >> x[i] >> y[i];
        }

        for (i = 1; i <= n + m; i++) {
            parent[i] = i; sz[i] = 1;
        }

        res = m;

        for (i = 1; i <= m; i++) {
            if (x[i] == y[i]) {
                res--; continue;
            }
            // cout << i _ x[i] + m _ y[i] + m << nl;
            merge(i, x[i] + m);
            if (same(i, y[i] + m)) res++;
            else merge(i, y[i] + m);
            for (j = 1; j <= n + m; j++) {
                // cout << j _ find(j) _ sz[j] << nl;
            }
        }

        cout << res << nl;
    }

    return 0;
}