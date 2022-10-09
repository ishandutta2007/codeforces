#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 10010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll f[maxn], cn;
array<ll, 2> rs[maxn];
bool vis[maxn];

void rf() {
    ll i;
    for (i = 1; i <= m; i++) f[i] = -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> m >> k; n = m * k;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (true) {
        rf();
        for (i = 1; i <= n; i++) {
            if (rs[a[i]][0] != 0) continue;
            if (f[a[i]] != -1) {
                rs[a[i]] = {f[a[i]], i};
                vis[f[a[i]]] = true; vis[i] = true;
                rf(); cn++;
            } else {
                f[a[i]] = i;
            }
            if (cn == m) break;
        }
        if (cn == m) break;
    }

    for (i = 1; i <= m; i++) cout << rs[i][0] _ rs[i][1] << nl;

    return 0;
}