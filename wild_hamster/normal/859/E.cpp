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
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll wasted[200500], used[200500], w[200500], w1[200500], dp[200500];
vector<ll> g[200500], gr[200500], comp;
void dfs_fck(ll v)
{
    if (used[v])
        return;
    used[v] = 1;
    for (int i = 0; i < gr[v].size(); i++)
        dfs_fck(gr[v][i]);
}
void dfs1(ll v)
{
    if (used[v])
        return;
    used[v] = 1;
    comp.push_back(v);
    k += w[v];
    for (int i = 0; i < gr[v].size(); i++)
    {
        dfs1(gr[v][i]);
    }
}
void dfs(ll v)
{
    if (g[v].size() == 0)
    {
        dp[v] = 1;
        return;
    }
    ll tmp = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        dfs(to);
        tmp = (1LL*tmp*dp[to])%MOD;
    }
    dp[v] = 1LL*((int)g[v].size())*tmp%MOD;
    k = (k+dp[v])%MOD;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        //x = i+1, y = i+2;
        if (x == y)
            wasted[x] = 1;
        g[y].push_back(x);
        gr[y].push_back(x);
        gr[x].push_back(y);
        w[y]++;
        w1[x]++;
    }
    for (i = 1; i <= 2*n; i++)
        if (wasted[i])
            dfs_fck(i);
    ll ans = 1;
    for (i = 1; i <= 2*n; i++)
    if (!used[i] && !gr[i].empty())
    {
        comp.clear();
        k = 0;
        dfs1(i);
        if (k == comp.size())
            ans = (ans*2)%MOD;
        else
        {
            ll root;
            for (j = 0; j < comp.size(); j++)
                if (w1[comp[j]] == 0)
                    root = comp[j];
            k = 1;
            dfs(root);
            ans = (1LL*ans*((int)comp.size()))%MOD;
        }
    }
    cout << ans << endl;
    return 0;
}