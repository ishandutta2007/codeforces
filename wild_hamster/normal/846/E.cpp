#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 2000
#define N 2000000
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll a[100500], b[100500], w[100500];
vector<pii> g[100500];
void dfs(ll v, ll p = -1)
{
    w[v] = a[v] - b[v];
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i].X;
        if (to != p)
        {
            dfs(to, v);
            ll val = g[v][i].Y;
            if (w[to] > 0)
                w[v] += w[to];
            else
            if (w[to] < 0)
            {
                ll cur = -w[to];
                if (cur > ((ll)1e+18)/val+1 || w[v] < -(ll)1e+18)
                {
                    cout << "NO" << endl;
                    exit(0);
                }
                w[v] -= cur*val;
            }
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (i = 2; i <= n; i++)
    {
        cin >> x >> y;
        g[x].push_back(mp(i,y));
        g[i].push_back(mp(x,y));
    }
    dfs(1);
    if (w[1] < 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}