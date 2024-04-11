#include <iostream>
//#include <cmath>
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
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 500000
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,m,x,y;
ll w[400500], mc[400500], a[400500];
vector<ll> g[400500];
multiset<ll> f;
multiset<ll>::iterator itr;
void dfs(ll v, ll p = -1)
{
	w[v] = 1;
	mc[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		ll to = g[v][i];
		if (to != p)
		{
			dfs(to, v);
			w[v] += w[to];
			mc[v] = max(mc[v], mc[to]);
		}
	}
	if (w[v] <= n/2)
	   mc[v] = max(mc[v], w[v]);
}
void dfs_gg(ll v, ll p = -1)
{
	if (w[v] > n/2 + 1)
	{
		if (w[v] - mc[v] - 1 <= n/2)
		   a[v] = 1;
		ll tmp = 0;
		for (int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if (to != p)
			   tmp = max(tmp, w[to]);
			if (w[to] > n/2 && w[to] - mc[to] <= n/2)
			   a[v] = 1;
		}
		if (tmp <= n/2)
		   a[v] = 1;
	} else
	{
		if (n - w[v] <= n/2)
		   a[v] = 1;
		itr = f.end();
		itr--;
		if (n - w[v] - (*itr) <= n/2)
		   a[v] = 1;
	}
	multiset <ll> tmp_set;
	multiset<ll>::iterator tmp_itr;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to != p)
		{
			tmp_set.insert(mc[to]);
		}
	}
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to != p)
		{
			tmp_itr = tmp_set.find(mc[to]);
			tmp_set.erase(tmp_itr);
			if (!tmp_set.empty())
			{
			tmp_itr = tmp_set.end();
			tmp_itr--;
		}
			ll val;
			if (!tmp_set.empty())
			   val = (*tmp_itr);
			else
				val = 0;
			if (n - w[to] <= n/2 && n - w[to] >= val)
			   f.insert(n - w[to]);
			else
				f.insert(val);
			dfs_gg(to, v);
			if (n - w[to] <= n/2 && n - w[to] >= val)
			{
			   itr = f.find(n - w[to]);
			   f.erase(itr);
			}
			else
			{
				itr = f.find(val);
				f.erase(itr);
			}
			tmp_set.insert(mc[to]);
		}
	}
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	if (n == 2)
	{
	    cout << 1 << " " << 1 << endl;
	    return 0;
	}
	for (i = 0; i < n-1; i++)
	{
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	dfs_gg(1);
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	cout << endl;
	return 0;
}