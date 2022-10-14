#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF (1LL+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-12
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,k,n1,n2,i,j,l, x,coord,p,q,y,timer;
ll a[1000500], b[1000500], t[8000500], tin[400500], tout[400500], to_push[4000500];
set <ll> f;
vector <ll> g[500500];
ll Abs(ll x)
{
	return x>0?x:-x;
}
void dfs(ll v, ll to = -1)
{
	tin[v] = timer++;
	a[tin[v]] = (1LL<<b[v]);
	for (int i = 0; i < g[v].size(); i++)
	if (g[v][i] != to)
		dfs(g[v][i], v);
	tout[v] = timer;
}

void build(ll v, ll tl, ll tr)
{
	if (tl == tr)
	{
		t[v] = a[tl];
		return;
	}
	ll tm = (tl+tr)/2;
	build(v*2, tl, tm);
	build(v*2+1, tm+1, tr);
	t[v] = (t[v*2] | t[v*2+1]);
}
void psh(ll v)
{
	if (to_push[v])
		t[v*2] = t[v*2+1] = to_push[v], 
		to_push[v*2] = to_push[v*2+1] = to_push[v],
		to_push[v] = 0;
	return;
}
ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
	if (l > r)
		return 0;
	if (tl == l && tr == r)
		return t[v];
	ll tm = (tl+tr)/2;
	psh(v);
	return ((sum(v*2, tl, tm, l, min(r, tm)) | sum(v*2+1, tm+1, tr, max(l, tm+1), r)));
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
	if (l > r)
		return;
	if (tl == l && tr == r)
	{
		t[v] = (1LL<<val);
		to_push[v] = (1LL<<val);
		return;
	}
	ll tm = (tl+tr)/2;
	psh(v);
	update(v*2, tl, tm, l, min(r, tm), val);
	update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
	t[v] = (t[v*2]|t[v*2+1]);
}
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    	scanf("%I64d", &b[i]);
    for (i = 0; i < n-1; i++)
    {
    	scanf("%I64d %I64d",&x, &y);
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    dfs(1);
    build(1, 0, n);
    for (i = 0; i < m; i++)
    {
    	cin >> x;
    	if (x == 2)
    	{
    		scanf("%I64d",&y);
    		ll ans = 0;
    		ll tt = sum(1,0,n,tin[y],tout[y]-1);
    		for (j = 0; j < 62; j++)
    			if ((tt&(1LL<<j)) != 0)
    				ans++;
    		printf("%I64d\n",ans);
    		
    	} else
    	if (x == 1)
    	{
    		ll y, z;
    		scanf("%I64d %I64d",&y,&z);
    		update(1, 0, n, tin[y], tout[y] - 1, z);
    	}
    }
    return 0;
}