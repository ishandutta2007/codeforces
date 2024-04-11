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
void dfs(ll v, ll lvl, ll p = -1) {
    if (a[v] > 0) {
        if (lvl > a[v])
            r = lvl - a[v];
        return;
    }
    a[v] = lvl;
    for (int i = 0; i < g[v].size(); i++) {
        ll to = g[v][i];
        if (to != p) {
            dfs(to, lvl+1, v);
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    ll max1 = -500, min1 = 500, minpos = 0, maxpos = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max1) {
            max1 = a[i];
            maxpos = i;
        }
        if (a[i] <= min1) {
            min1 = a[i];
            minpos = i;
        }
    }
    if (minpos > maxpos) {
        cout << n-1-minpos+maxpos << endl;
    } else {
        cout << n-2-minpos+maxpos << endl;
    }
    return 0;
}