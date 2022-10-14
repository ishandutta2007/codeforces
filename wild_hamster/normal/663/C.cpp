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
#define eps 1e-9
typedef long long ll;
typedef long double ld;
using namespace std;
ll n, k,j,i,l,x,y,z,m,R,W,Rx,Ry,Wx,Wy,flag;
ll a[100500], p10[15], used[100500], to_change[100500];
char c, col;
vector<pair<ll, char> > g[100500];
vector<ll> comp, Rvec, Wvec;
string s;
void dfs(ll v)
{
	if (used[v])
	   return;
	comp.push_back(v);
	used[v] = 1;
	for (int j = 0; j < g[v].size(); j++)
	{
		int to = g[v][j].X;
		char c = g[v][j].Y;
		if (c == 'R')
		{
		   R++;
		   Rx = v;
		   Ry = to;
        }
		else
		{
			W++;
			Wx = v;
			Wy = to;
		}
		dfs(to);
	}
}
void try_dfs(ll v, ll change)
{
	if (used[v])
	{
		if (to_change[v] != change)
		   flag = 0;
		return;
	}

	used[v] = 1;
	to_change[v] = change;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].X;
		char c = g[v][i].Y;
		if ((c == col && change == 1)||(c != col && change == 0))
		{
			try_dfs(to,0);
		} else
		  try_dfs(to,1);
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y >> c;
		g[x].push_back(mp(y,c));
		g[y].push_back(mp(x,c));
	}
	ll totalR = 0, totalW = 0;
	for (i = 1; i <= n; i++)
		if (!used[i])
		{
			comp.clear();
			R = 0;
			W = 0;
			dfs(i);
			ll tmp = INF;
			if (R != 0)
			{
				vector <ll> bull;
				flag = 1;
				for (j = 0; j < comp.size(); j++)
					used[comp[j]] = 0;
				col = 'R';
				try_dfs(Rx,1);
				ll cnt = 0;
				if (flag)
				for (j = 0; j < comp.size(); j++)
					cnt += to_change[comp[j]];
				
				if (cnt < tmp && flag)
				{
					for (j = 0; j < comp.size(); j++)
						if (to_change[comp[j]])
						   bull.push_back(comp[j]);
					tmp = cnt;
				}
				
				flag = 1;
				for (j = 0; j < comp.size(); j++)
					used[comp[j]] = 0;
				col = 'R';
				try_dfs(Ry,1);
				cnt = 0;
				if (flag)
				for (j = 0; j < comp.size(); j++)
					cnt += to_change[comp[j]];
				if (cnt < tmp && flag)
				{
					bull.clear();
					for (j = 0; j < comp.size(); j++)
						if (to_change[comp[j]])
						   bull.push_back(comp[j]);
					tmp = cnt;
				}
				if (cnt > 0)
				{

					for (j = 0; j < bull.size(); j++)
					{
						//cout << bull[j] << endl;
						Wvec.push_back(bull[j]);
					}
				}
				totalW += tmp;
			}
			tmp = INF;
			if (W != 0)
			{
				vector <ll> bull;
				flag = 1;
				for (j = 0; j < comp.size(); j++)
					used[comp[j]] = 0;
				col = 'B';
				try_dfs(Wx,1);
				ll cnt = 0;
				if (flag)
				for (j = 0; j < comp.size(); j++)
				{
					cnt += to_change[comp[j]];
				}
				if (cnt < tmp && flag)
				{
					for (j = 0; j < comp.size(); j++)
						if (to_change[comp[j]])
						   bull.push_back(comp[j]);
					tmp = cnt;
				}
				flag = 1;
				for (j = 0; j < comp.size(); j++)
					used[comp[j]] = 0;
				col = 'B';
				try_dfs(Wy,1);
				cnt = 0;
				if (flag)
				for (j = 0; j < comp.size(); j++)
					cnt += to_change[comp[j]];
				if (cnt < tmp && flag)
				{
					bull.clear();
					for (j = 0; j < comp.size(); j++)
						if (to_change[comp[j]])
						   bull.push_back(comp[j]);
					tmp = cnt;
				}
				if (cnt > 0)
				{
					for (j = 0; j < bull.size(); j++)
						Rvec.push_back(bull[j]);
				}
				totalR += tmp;
			}
		}
		ll ans = min(totalW, totalR);
		if (ans >= INF)
		{
		   cout << -1 << endl;

			return 0;
	}
	if (totalW < totalR || totalR >= INF)
	{
		cout << totalW << endl;
		for (i = 0; i < Wvec.size(); i++)
			cout << Wvec[i] << " ";
		cout << endl;
	} else
	{
		cout << totalR << endl;
		for (i = 0; i < Rvec.size(); i++)
			cout << Rvec[i] << " ";
		cout << endl;
	}
	return 0;
}