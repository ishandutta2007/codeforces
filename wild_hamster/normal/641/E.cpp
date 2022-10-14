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
#define INF (1LL+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-9
typedef int ll;
typedef long double ld;
using namespace std;
ll n, k,j,i,m,q,ii,timer,x1,y;
ll min1, max1;
ll a[1005000], t[5005000], tim[1005000], x[1005000], ans[1005000];
vector<pair<pii,ll> > g[1005000];
map<ll,ll> compress;
map<ll,ll>::iterator itr;
string s;

void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = 0;
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] += new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		ans[i] = -1;
		scanf("%d %d %d",&a[i], &tim[i], &x[i]);
		compress[x[i]] = 0;
	}
	i = 0;
	for (itr = compress.begin(); itr != compress.end(); itr++)
	{
		compress[(*itr).X] = i++;
	}
	m = i;
	for (i = 0; i < n; i++)
		x[i] = compress[x[i]];
	for (i = 0; i < n; i++)
		g[x[i]].push_back(mp(mp(a[i], tim[i]), i));
	for (i = 0; i < m; i++)
	{
	 compress.clear();
	 ll sz = 0;
	 for (j = 0; j < g[i].size(); j++)
		 compress[g[i][j].X.Y] = 0;
	 for (itr = compress.begin(); itr != compress.end(); itr++)
		compress[(*itr).X] = sz++;
	 for (j = 0; j < g[i].size(); j++)
		 g[i][j].X.Y = compress[g[i][j].X.Y];
	 build(1, 0, sz);
	 for (j = 0; j < g[i].size(); j++)
		 if (g[i][j].X.X == 1)
			update(1, 0, sz, g[i][j].X.Y, 1);
		 else
		 if (g[i][j].X.X == 2)
			update(1, 0, sz, g[i][j].X.Y, -1);
		 else
			 ans[g[i][j].Y] = sum(1,0,sz,0,g[i][j].X.Y);
	}
	for (i = 0; i < n; i++)
		if (ans[i] != -1)
		   printf("%d\n", ans[i]);
	return 0;
}