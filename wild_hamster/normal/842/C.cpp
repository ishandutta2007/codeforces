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
ll n,i,j,k,x,y,z,m,Q, mx,a[200500];
vector<ll> g[200500];
ll cur[200500], ans[200500];
set<ll> tmp;
ll gcd(ll a, ll b)
{
    return (b==0?a:gcd(b,a%b));
}
void dfs(ll v, ll cr, ll p = -1)
{
    ans[v] = cr;
    set<ll> tmp2 = tmp;
    tmp.clear();
    tmp.insert(cr);
    for (auto itr = tmp2.begin(); itr != tmp2.end(); itr++)
    {
        ll val = (*itr);
        ll r = gcd(val, a[v]);
        ans[v] = max(ans[v], r);
        tmp.insert(r);
    }
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            dfs(to, gcd(cr, a[v]), v);
        }
    }
    tmp = tmp2;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for (i = 0; i < n-1; i++)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cur[1] = ans[1];
    tmp.insert(0);
    dfs(1, 0);
    ans[1] = a[1];
    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}