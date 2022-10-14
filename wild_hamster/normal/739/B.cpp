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
#define N 500500
#define SUM 23423
#define MAG 1048576
#define OPEN 0
#define CLOSE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,h,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,timer;
ll a[200500], w[200500], b[200500], rev[200500], tin[200500], tout[200500], dst[200500];
vector<ll> t[1005000];
vector<pii> g[200500];
void build (ll a[], ll v, ll tl, ll tr) {
	if (tl == tr)
		t[v] = vector<ll> (1, a[tl]);
	else {
		ll tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		merge (t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
			back_inserter (t[v]));
	}
}
int query (ll v, ll tl, ll tr, ll l, ll r, ll x) {
	if (l > r)
		return 0;
	if (l == tl && tr == r) {
		int pos = t[v].end() - lower_bound (t[v].begin(), t[v].end(), x);
		return pos;
	}
	ll tm = (tl + tr) / 2;
	return
		query (v*2, tl, tm, l, min(r,tm), x) +
		query (v*2+1, tm+1, tr, max(l,tm+1), r, x);
}
void dfs(ll v, ll sum, ll p = -1)
{
	w[v] = b[v] - sum;
	dst[v] = -sum;
	tin[v] = timer;
	for (int i = 0; i < g[v].size(); i++)
	{
		ll to = g[v][i].X;
		if (to != p)
		   dfs(to, sum+g[v][i].Y, v);
	}
	tout[v] = timer++;
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
		scanf("%I64d",&b[i]);
	for (i = 2; i <= n; i++)
	{
		scanf("%I64d %I64d",&x,&y);
		g[i].push_back(mp(x,y));
		g[x].push_back(mp(i,y));
	}
	dfs(1, 0);
	for (i = 1; i <= n; i++)
		rev[tout[i]] = i;
	for (i = 0; i < timer; i++)
		a[i] = w[rev[i]];
	build(a, 1, 0, timer-1);
	//for (i = 0; i < timer; i++)
	//	cout << rev[i] << " " << a[i] << endl;
	for (i = 1; i <= n; i++)
		printf("%d ",query(1, 0, timer-1, tin[i], tout[i]-1, dst[i]));
    return 0;
}