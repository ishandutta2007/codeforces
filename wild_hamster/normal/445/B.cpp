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
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y;
ll a[200005];
vector<ll> g[100500];
void dfs(ll v) {
    if (a[v])
        return;
    a[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        dfs(g[v][i]);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cnt = n;
    for (int i = 1; i <= n; i++)
        if (!a[i]) {
            dfs(i);
            cnt--;
        }
    cout << (1LL<<cnt) << endl;
    return 0;
}