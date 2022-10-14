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
ll i,j,n,x,y,z,m,k,l,r,flag,timer,sz, q,s,t;
ll d[3005], a[1005][1005], ls[3005], bridge[1005][1005], glob, tin[1005], fup[1005], used[1005];
ll new_ls[3005];
vector<ll> b[1005][1005], f, path, new_path;
vector<pii> g[1005];
ll aa[35000], bb[35000], cc[35000];

void dfs (int v, int p = -1) {
	used[v] = 1;
	tin[v] = fup[v] = timer++;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i].X;
		if (to == p || a[v][to] == 0)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v])
				bridge[v][to] = bridge[to][v] = glob;
		}
	}
}

void bull()
{
	ll i, x;
	for (i = 1; i <= n; i++)
		ls[i] = 0;
	ls[s] = -1;
	i = 0;
	f.clear();
	f.push_back(s);
	while (i < f.size())
	{
		ll v = f[i++];
		for (int j = 0; j < g[v].size(); j++)
		{
			ll to = g[v][j].X;
			if (ls[to] == 0 && a[to][v] != 0)
			{
				ls[to] = v;
				f.push_back(to);
			}
		}
	}
	x = t;
	if (ls[t] == 0)
	   return;
	while (x != s)
	{
		new_path.push_back(x);
		x = ls[x];
	}
	new_path.push_back(s);
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	cin >> s >> t;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		aa[i] = x;
		bb[i] = y;
		cc[i] = z;
		if (!a[x][y])
		{
		g[x].push_back(mp(y,z));
		g[y].push_back(mp(x,z));
		}
		if (x > y)
		   swap(x,y);
		b[x][y].push_back(z);
		a[x][y]++;
		a[y][x]++;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (a[i][j])
			   sort(b[i][j].begin(), b[i][j].end());
	for (i = 1; i <= n; i++)
		d[i] = n+50;
	d[s] = 0;
	ls[s] = -1;
	i = 0;
	f.push_back(s);
	while (i < f.size())
	{
		ll v = f[i++];
		for (int j = 0; j < g[v].size(); j++)
		{
			ll to = g[v][j].X;
			if (ls[to] == 0)
			{
				ls[to] = v;
				d[to] = d[v]+1;
				f.push_back(to);
			}
		}
	}
	if (d[t] == n+50)
	{
		cout << 0 << endl << 0 << endl;
		return 0;
	}
	x = t;
	while (x != s)
	{
		path.push_back(x);
		x = ls[x];
	}

	path.push_back(s);
	ll ans = 1000*1000*1000*2 + 1;
	ll cn = 2;
	ll x1,y1,x2,y2,z1,z2;
	ll sz = path.size();
	for (i = 0; i < sz-1; i++)
	{
		glob = i+1;
		ll x = path[i];
		ll y = path[i+1];
		if (x > y)
		   swap(x,y);
		a[x][y]--;
		a[y][x]--;
		new_path.clear();
		bull();

		int new_sz = new_path.size();
		
		for (j = 1; j <= n; j++)
			used[j] = 0;
		timer = 0;
		dfs(s);
		if (!used[t])
		{
			if (ans > b[x][y][0])
			   ans = b[x][y][0], cn = 1, x1 = x, y1 = y, z1 = b[x][y][0];

			a[x][y]++;
			a[y][x]++;
			continue;
		}
		for (j = 0; j < new_sz-1; j++)
		{
			ll curx = new_path[j];
			ll cury = new_path[j+1];

			if (curx > cury)
			   swap(curx, cury);
			if (a[curx][cury] == 1 && bridge[curx][cury] == glob)
			{
				if (x == curx && y == cury && b[x][y][0] + b[x][y][1] < ans)
				{
					ans = b[x][y][0] + b[x][y][1];
					cn = 2;
					x1 = x2 = x;
					y1 = y2 = y;
					z1 = b[x][y][0];
					z2 = b[x][y][1];
				} else
				if ((x != curx || y != cury) && b[x][y][0] + b[curx][cury][0] < ans)
				{
					ans = b[x][y][0] + b[curx][cury][0];
					cn = 2;
					x1 = x;
					x2 = curx;
					y1 = y;
					y2 = cury;
					z1 = b[x][y][0];
					z2 = b[curx][cury][0];
				}

			}
		}

		a[x][y]++;
		a[y][x]++;
	}
	if (ans == 2*1000*1000*1000 + 1)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	cout << cn << endl;
	if (cn == 1)
 	{
 		if (x1 > y1)
		   swap(x1, y1);
 		for (i = 0; i < m; i++)
 		{
 			if (aa[i] > bb[i])
			   swap(aa[i], bb[i]);
			if (aa[i] == x1 && bb[i] == y1 && cc[i] == z1)
			{
				cout << i+1 << endl;
				break;
			}
		}
 	} else
 	if (cn == 2)
 	{
 		if (x1 > y1)
		   swap(x1,y1);
		 if (x2 > y2)
			swap(x2,y2);
		 for (i = 0; i < m; i++)
		 {
		 	if (aa[i] > bb[i])
			   swap(aa[i], bb[i]);
			if (aa[i] == x1 && bb[i] == y1 && cc[i] == z1)
			{
				cout << i+1 << " ";
				break;
			}
		 }
		 for (j = 0; j < m; j++)
		 if (i != j)
		 {
		 	if (aa[j] > bb[j])
			   swap(aa[j], bb[j]);
		 	if (aa[j] == x2 && bb[j] == y2 && cc[j] == z2)
			{
				cout << j+1 << endl;
				break;
			}
		 }
 	}
	return 0;
}