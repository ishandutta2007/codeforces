#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[200500],  b[200500], w[200050];
vector<ll> g[100500];
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
void dfs(ll v, ll p = -1) {
    w[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        ll to = g[v][i];
        if (to != p) {
            dfs(to, v);
            w[v] += w[to];
        }
    }
    if (v != 1 && w[v]%2 == 0)
        sum++;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    if (n%2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n-1; i++) {
        ll x,y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    cout << sum << endl;
    return 0;
}