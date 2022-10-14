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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,Q, mx,used[200500], w[200500], W[200500], start;
vector<ll> g[200500], verts, leafs, ned;
set<ll> f[200500];
vector<pair<pii,ll> > ans;
void dfs(ll v, ll p = -1)
{
    w[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            dfs(to, v);
            w[v] += w[to];
        }
    }
    if (w[v] == n/2 && n%2 == 0)
    {
        x = v, y = p;
    }
    if (w[v] > mx && w[v] <= n/2)
    {
        mx = w[v];
        z = p;
    }
    if (n - w[v] > mx && n - w[v] <= n/2)
    {
        mx = n-w[v];
        z = v;
    }
}
void dfs_prepare(ll v, ll p)
{
    verts.push_back(v);
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            f[v].insert(to);
            f[to].insert(v);
            dfs_prepare(to, v);
        }
    }
}
void dfs_mag(ll v, ll p = -1)
{
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            f[v].insert(to);
            f[to].insert(v);
            verts.push_back(v);
            dfs_prepare(to, v);
            for (int j = 0; j < verts.size(); j++)
            {
                if (f[verts[j]].size() == 1)
                    leafs.push_back(verts[j]);
            }
            ll cur = v, prev = -1;
            while (leafs.size() != 2)
            {
                for (auto itr = f[cur].begin(); itr != f[cur].end(); itr++)
                {
                    ll To = *itr;
                    if (To != prev)
                    {
                        if (f[To].size() > 2)
                        {
                            int t = leafs.back();
                            leafs.pop_back();
                            f[cur].erase(To);
                            f[To].erase(cur);
                            f[cur].insert(t);
                            f[t].insert(cur);
                            ans.push_back(mp(mp(cur, To), t));
                            prev = cur;
                            cur = t;
                            break;
                        } else
                        {
                            prev = cur;
                            cur = To;
                            break;
                        }
                    }
                }
            }
            cur = v;
            ned.push_back(v);
            cur = (*(f[cur].begin()));
            ned.push_back(cur);
            prev = v;
            while (f[cur].size() != 1)
            {
                for (auto itr = f[cur].begin(); itr != f[cur].end(); itr++)
                {
                    if ((*itr) != prev)
                    {
                        ned.push_back(*itr);
                        prev = cur;
                        cur = *itr;
                        break;
                    }
                }
            }
            int siz = ned.size();
            for (int j = siz-3; j >= 0; j--)
            {
                ans.push_back(mp(mp(ned[j], ned[j+1]), ned.back()));
            }
            for (int j = 0; j < verts.size(); j++)
            {
                f[verts[j]].clear();
            }
            ned.clear();
            leafs.clear();
            verts.clear();
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n-1; i++)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    mx = 0;
    x = -1, y = -1;
    dfs(1);
    if (x != -1)
    {
        dfs_mag(y,x);
        dfs_mag(x,y);
    } else
        dfs_mag(z,-1);
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
    {
        printf("%d %d %d\n",ans[i].X.X,ans[i].X.Y,ans[i].Y);
    }
    return 0;
}