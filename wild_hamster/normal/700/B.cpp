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
#define N 500000
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 12
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag,timer,sz, q;
ll a[300005], b[300005], w[300005];
vector<pii> f;
vector<ll> g[300005];
void dfs_for_cnt(ll v, ll p = -1)
{
	w[v] = a[v];
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to != p)
		{
			dfs_for_cnt(to, v);
			w[v] += w[to];
		}
	}
}



ll count_dfs(ll v, ll val, ll p)
{
	ll ans = a[v]*val;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to != p)
		   ans += count_dfs(to, val+1, v);
	}
	return ans;
}

ll dfs(ll v, ll to_del, ll p = -1)
{
	f.clear();
	ll sum = 0;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to != p)
		{
			f.push_back(mp(w[to], to));
			sum += w[to];
		}
	}
	sort(f.begin(), f.end());
	int sz = f.size();
	sum -= f[sz-1].X;
	ll ans = 0;
	if (sum + a[v] + to_del >= w[f[sz-1].Y])
	{
		for (int i = 0; i < sz; i++)
			ans += count_dfs(f[i].Y, 1, v);
	} else
	{
		for (int i = 0; i < sz-1; i++)
			ans += count_dfs(f[i].Y, 1, v);
		ans += to_del + sum + a[v];
		ans += dfs(f[sz-1].Y, to_del + sum + a[v], v);
	}
	return ans;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> k;
	for (i = 0; i < k*2; i++)
	{
		scanf("%I64d",&x);
		a[x] = 1;
	}
	for (i = 0; i < n-1; i++)
	{
		scanf("%I64d %I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs_for_cnt(1);
	cout << dfs(1, 0) << endl;
	return 0;
}