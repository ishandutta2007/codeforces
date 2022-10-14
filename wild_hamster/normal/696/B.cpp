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
ll i,j,n,x,y,z,m,k,l,r,flag,timer,glob,sz, w[100500];
ld ans[100500];
vector<ll> g[100500];
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
}
void dfs2(ll v, ll p = -1)
{
	if (v == 1)
	   ans[v] = 1;
	ll sz = g[v].size();
	for (int i = 0; i < sz; i++)
	{
		ll to = g[v][i];
		if (to != p)
		{
			if (sz == 1)
			   ans[to] = ans[v] + 1;
			else
				ans[to] = ans[v] + 1 + (double)(w[v]-w[to]-1)/2;
			dfs2(to, v);
		}
	}
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 0; i < n-1; i++)
	{
		cin >> x;
		g[x].push_back(i+2);
		g[i+2].push_back(x);
	}
	dfs(1);
	dfs2(1);
	for (i = 1; i <= n; i++)
		printf("%.8f ", (double)ans[i]);
	cout << endl;
	return 0;
}