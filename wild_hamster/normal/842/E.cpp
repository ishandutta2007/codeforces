#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 998244353
#define y1 dskgj
#define y2 dskfj
#define N 300500
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,w,h,timer;
ll a[N], b[N], tin[N], tout[N], up[N][20], lv[N], pre[N];
ll curl1[N], curl2[N], ans[N], dst[N];
vector<ll> g[N];
void dfs(ll v, ll lvl, ll p = -1)
{
    tin[v] = timer;
    lv[v] = lvl;
    if (p == -1)
        up[v][0] = 1;
    else
        up[v][0] = p;
    for (int i = 1; i <= 19; i++)
    {
        up[v][i] = up[up[v][i-1]][i-1];
        if (up[v][i] != 1)
            pre[v] = i+1;
    }
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            dfs(to, lvl+1, v);
        }
    }
    tout[v] = timer++;
}
bool upper(ll x, ll y)
{
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}
ll lca(ll x, ll y)
{
    if (upper(x, y))
        return x;
    if (upper(y, x))
        return y;
    if (pre[x] > pre[y])
        swap(x,y);
    for (int i = pre[x]; i >= 0; i--)
    {
        if (!upper(up[x][i], y))
            x = up[x][i];
    }
    return up[x][0];
}
ll dist(ll x, ll y)
{
    int lc = lca(x,y);
    return lv[x]+lv[y]-2*lv[lc];
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    n++;
    for (i = 0; i < n-1; i++)
    {
        scanf("%d",&x);
        y = i+2;
        a[i] = x, b[i] = i+2;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int curc1 = 1, curc2 = 1, curleaf1 = 1, curleaf2 = 1;
    for (i = 2; i <= n; i++)
    {
        ll curdist = dist(curleaf1, curleaf2);
        if (dist(i, curleaf2) > curdist)
        {
            curleaf1 = i;
            curdist++;
        } else
        if (dist(i, curleaf1) > curdist)
        {
            curleaf2 = i;
            curdist++;
        }
        curl1[i] = curleaf1;
        curl2[i] = curleaf2;
        dst[i] = curdist;
        //cout << dst[i] << " " << curleaf1 << " " << curleaf2 << endl;
    }
    for (i = 1; i <= n; i++)
    {
        ll l = max(2,i), r = n;
        if (max(dist(i, curl1[l]), dist(i,curl2[l])) != dst[l])
            continue;
        while (l < r)
        {
            ll mid = (l+r+1)/2;
            int mm1 = dist(curl1[mid], i);
            int mm2 = dist(curl2[mid], i);
            if (max(mm1, mm2) == dst[mid])
                l = mid;
            else
                r = mid-1;
        }
        //cout << i << " " << l << endl;
        ans[max(i,2)]++;
        ans[l+1]--;
    }
    for (i = 2; i <= n; i++)
    {
        ans[i] += ans[i-1];
        printf("%d\n",ans[i]);
    }
    return 0;
}