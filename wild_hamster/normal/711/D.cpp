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
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 500000
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko;
ll a[200505], used[205000], used_tot[200500];
vector<ll> g[200500], comp;
void dfs_to(ll v)
{
	if (used_tot[v])
	   return;
	used_tot[v] = 1;
	comp.push_back(v);
	for (int i = 0; i < g[v].size(); i++)
	{
		ll to = g[v][i];
		dfs_to(to);
	}
}
void dfs(ll v, ll timer, ll p = -1)
{
	used[v] = timer;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (koko != -1)
		   break;
		if (to != p)
		{
			if (used[to] > 0)
			{
			   koko = timer - used[to] + 1;
			   return;
   			}
			else
				dfs(to, timer+1, v);
		}
	}
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		g[i].push_back(a[i]);
		g[a[i]].push_back(i);
	}
	ll total_ans = 1;
	for (int i = 1; i <= n; i++)
	if (!used_tot[i])
	{
		ll v = i;
		comp.clear();
		dfs_to(v);
		ans = 1;
		for (j = 0; j+1 < comp.size(); j++)
			ans = (ans*2)%MOD;
		ll flag = 0;
		for (j = 0; j < comp.size(); j++)
		{
			ll bb = comp[j];
			if (a[a[bb]] == bb)
			{
				total_ans = (total_ans*ans)%MOD;
				flag = 1;
				break;
			}
		}
		if (flag)
		   continue;
		koko = -1;
		dfs(v, 1);
		x = 1;
		for (j = 0; j < (int)comp.size()+1-koko; j++)
			x = (x*2)%MOD;
		total_ans = (total_ans*((ans*2-x+MOD)%MOD))%MOD;
	}
	cout << total_ans << endl;
	return 0;
}