#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 400010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll f[maxn];
bool vis[maxn];

void dfs(ll s) {
    if (vis[s]) return;
    vis[s] = true; dfs(f[s]);
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
        cin >> n; res = 1;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> b[i]; f[a[i]] = b[i];
        }

        for (i = 1; i <= n; i++) vis[i] = false;
        for (i = 1; i <= n; i++) {
            if (vis[i]) continue;
            dfs(i); res = (2 * res) % mod;
        }

        cout << res << nl;
    }

    return 0;
}