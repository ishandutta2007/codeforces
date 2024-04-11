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
#define MOD2 1000000009
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 300000
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 1000
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag,timer,tin[N+500], tout[N+500], w[N+500];
pii a[N+500];
string s;
vector<pii> t[4*N+500];
vector<int> g[N+500];
void build (pii a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = vector<pii> (1, a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		merge (t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
			back_inserter (t[v]));
	}
}

pii query (int v, int tl, int tr, int l, int r, int x) {
	if (l > r)
		return mp(INF, INF);
	if (l == tl && tr == r) {
		vector<pii>::iterator pos = lower_bound (t[v].begin(), t[v].end(), mp(x,-1));
		if (pos != t[v].end())
			return *pos;
		return mp(INF, INF);
	}
	int tm = (tl + tr) / 2;
	return min (
		query (v*2, tl, tm, l, min(r,tm), x),
		query (v*2+1, tm+1, tr, max(l,tm+1), r, x)
	);
}

void dfs(int v, int p = -1)
{
	tin[v] = timer++;
	w[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to != p)
		{
			dfs(to, v);
			w[v] += w[to];
		}
	}
	tout[v] = timer;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll q;
	cin >> n >> q;
	for (i = 0; i < n-1; i++)
	{
		scanf("%d",&x);
		g[x].push_back(i+2);
		g[i+2].push_back(x);
	}
	timer = 0;
	dfs(1);
	//for (i = 1; i <= n; i++)
	//	cout << tin[i] << " " << tout[i] << endl;
	for (i = 1; i <= n; i++)
		a[tin[i]] = mp(w[i],i);
	build(a,1,0,n-1);

	for (i = 0; i < q; i++)
	{
		ll v;
		scanf("%d",&v);
		pii ans = query(1,0,n-1,tin[v],tout[v]-1,(w[v]+1)/2);
		//cout << ans.X << " " << ans.Y << endl;
		printf("%d\n",ans.Y);
	}
	return 0;
}