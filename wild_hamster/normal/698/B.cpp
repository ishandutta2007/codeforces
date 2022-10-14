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
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag,timer,glob,sz, q, w[200500], w2[200500];
ll a[200500], used[200005], sel[200500], chosen[200500];
vector<ll> components[200500], g[200500];
set<pii> f;
set<pii>::iterator itr;
void dfs(ll v)
{
	if (used[v])
	   return;
	used[v] = 1;
	components[q].push_back(v);
	for (int i = 0; i < g[v].size(); i++)
	{
		ll to = g[v][i];
		dfs(to);
	}
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		if (i == a[i])
		   sel[i] = 1, k++;
		g[i].push_back(a[i]);
		g[a[i]].push_back(i);
	}
	for (i = 1; i <= n; i++)
		w[i] = w2[i] = g[i].size();
	q = 0;
	for (i = 1; i <= n; i++)
	if (!used[i])
	{
		dfs(i);
		f.clear();
		for (j = 0; j < components[q].size(); j++)
		{
			ll v = components[q][j];
			w2[v] = w[v];
			f.insert(mp(w[v], v));
		}
		while (1)
		{
			itr = f.begin();
			if ((*itr).X == 2)
			{
				ll v = (*itr).Y;
				for (j = 0; j < g[v].size(); j++)
				{
					ll to = g[v][j];
					if (w2[to] == 2)
					{
						if (a[to] == v)
						   chosen[q] = to;
						else
							chosen[q] = v;
						break;
					}
				}
				break;
			}
			ll v = (*itr).Y;
			//cout << (*itr).X << " " << (*itr).Y << endl;
			f.erase(mp(1,v));
			w2[v]--;
			for (j = 0; j < g[v].size(); j++)
			{
				ll to = g[v][j];
				if (w2[to] != 0)
				{
					f.erase(mp(w2[to],to));
					w2[to]--;
					f.insert(mp(w2[to],to));
				}
			}
		}
		q++;
	}
	if (k == 0)
	   cout << q << endl;
	else
		cout << q-1 << endl;
	for (i = 0; i+1 < q; i++)
	{
		if (k == 1)
		{
			if (sel[chosen[i]])
			   a[chosen[i+1]] = chosen[i];
			else
				a[chosen[i]] = chosen[i+1];
		} else
		{
		  a[chosen[i]] = a[chosen[i+1]];
		  if (sel[chosen[i]])
			 k--;
		}
	}
	if (k == 0)
	{
		for (i = 1; i <= n; i++)
			g[i].clear();
		for (i = 1; i <= n; i++)
		{
			g[i].push_back(a[i]);
			g[a[i]].push_back(i);
		}
		for (i = 1; i <= n; i++)
			w[i] = g[i].size();
		f.clear();
		for (i = 1; i <= n; i++)
			f.insert(mp(w[i],i));
		while (1)
		{
			itr = f.begin();
			if ((*itr).X == 2)
			{
				ll v = (*itr).Y;
				for (j = 0; j < g[v].size(); j++)
				{
					ll to = g[v][j];
					if (w[to] == 2)
					{
						if (a[to] == v)
						   a[to] = to;
						else
							a[v] = v;
						break;
					}
				}
				break;
			}
			ll v = (*itr).Y;
			//cout << (*itr).X << " " << (*itr).Y << endl;
			f.erase(mp(1,v));
			w[v]--;
			for (j = 0; j < g[v].size(); j++)
			{
				ll to = g[v][j];
				if (w[to] != 0)
				{
					f.erase(mp(w[to],to));
					w[to]--;
					f.insert(mp(w[to],to));
				}
			}
		}
	}
	
	for (i = 1; i <= n; i++)
		printf("%d ",a[i]);
	return 0;
}