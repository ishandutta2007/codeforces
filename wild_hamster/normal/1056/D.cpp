#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,x, rt[35], y, z, l, i, j, p;
ll a[100500], b[100500];
ll dp[100500];
vector<ll> g[100500];
void dfs(ll v, ll p = -1) {
    ll cnt = 0;
    for (auto to : g[v]) {
        if (to == p)
            continue;
        dfs(to, v);
        cnt += dp[to];
    }
    if (cnt == 0)
        cnt = 1;
    dp[v] = cnt;
}
int main() {
     //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        g[x].push_back(i+2);
        g[i+2].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        a[dp[i]]++;
    ll ans = 0;
    for (int i = 1; i <= 100200; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << i << " ";
        }
    }
    return 0;
}