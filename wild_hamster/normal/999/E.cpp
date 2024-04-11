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
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y,INF, ans;
ll a[1200005], used[1205000], w[1205000];
vector<ll> g[5005], gr[5005];
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
void dfs(ll v) {
    if (used[v] != tot && a[v] > 0) {
        a[v] = 0;
    }
    used[v] = tot;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] != tot) {
            dfs(g[v][i]);
        }
    }
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    tot = k;
    dfs(k);
    for (int i = 1; i <= n; i++)
        if (i != k) {
        tot = i;
        if (!used[i]) {
            dfs(i);
            a[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans << endl;
    return 0;
}