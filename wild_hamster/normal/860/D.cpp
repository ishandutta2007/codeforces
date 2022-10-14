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
ll used[200500], p[200500], w[200500], w2[200500];
vector<ll> g[200500];
vector<ll> comp;
set<ll> tree[200500], g2[200500];
vector<pair<pii,ll> > ans;
set<pair<pii,ll>> f;
void dfs(ll v)
{
    //cout << v << " " << p[v] << endl;
    comp.push_back(v);
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (!used[to])
        {
            tree[v].insert(to);
            p[to] = v;
            dfs(to);
        } else
        if (p[v] != to)
        {
            g2[v].insert(to);
        }
    }
}
void dfs_tree(ll v)
{
    //cout << v << " " << p[v] << endl;
    for (auto itr = tree[v].begin(); itr != tree[v].end(); itr++)
    {
        dfs_tree(*itr);
    }
    while (g2[v].size() >= 2)
    {
        auto itr = g2[v].begin();
        int x1 = (*itr);
        g2[x1].erase(v);
        g2[v].erase(itr);
        itr = g2[v].begin();
        int x2 = (*itr);
        g2[x2].erase(v);
        g2[v].erase(itr);
        ans.push_back(mp(mp(x1, v), x2));
        //cout << x1 << " " << v << " " << x2 << endl;
    }
    if (p[v] == -1)
        return;
    if (g2[v].size() == 1)
    {
        auto itr = g2[v].begin();
        int x1 = (*itr);
        g2[x1].erase(v);
        ans.push_back(mp(mp(x1, v), p[v]));
    } else
    {
        g2[p[v]].insert(v);
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (i = 1; i <= n; i++)
    if (!used[i])
    {
        f.clear();
        comp.clear();
        dfs(i);
        p[i] = -1;
        dfs_tree(i);
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
    {
        printf("%d %d %d\n", ans[i].X.X, ans[i].X.Y, ans[i].Y);
    }
    return 0;
}