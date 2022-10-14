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
#define COL 10
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot;
ll a[2005][2005], b[2002005];
double ans[5005];
vector<pii> f;
vector<pii> g[5005];
void dfs(ll v, ll p = -1) {
    if (v == tot) {
        double tmp = t;
        ans[u] = min(ans[u], tmp);
        for (int i = 0; i < f.size(); i++) {
            tmp += 1.*f[i].Y/s;
            ans[f[i].X] = min(ans[f[i].X], tmp);
        }
    }
    for (int i = 0; i < g[v].size(); i++) {
        ll to = g[v][i].X;
        ll val = g[v][i].Y;
        if (to != p) {
            f.push_back(mp(to, val));
            dfs(to, v);
            f.pop_back();
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    if (k > (n*n+1)/2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if ((i+j)%2 == 0 && i*n+j < k*2)
                cout << "L";
            else
                cout << "S";
        cout << endl;
    }
    return 0;
}