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
#include <assert.h>
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
#define N 100500
#define SUM 23423
#define MAG 166
#define OPEN 0
#define CLOSE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer;
ll a[1000500], fac[1000500];
ll col_cnt[5000500], color[1000500];
vector<ll> f, used_col;
vector<pair<ll,ll> > g;
vector<ll> used[5000500];
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	//print();
	fac[0] = 1;
	for (i = 1; i <= 1000000; i++)
		fac[i] = (fac[i-1]*i)%MOD;
	cin >> n >> m;
	col_cnt[0] = m;
	ll next_color = 1;
	for (i = 0; i < n; i++)
	{
		scanf("%I64d",&x);
		f.clear();
		g.clear();
		for (j = 0; j < x; j++)
		{
			scanf("%I64d",&y);
			f.push_back(y);
		}
		sort(f.begin(), f.end());
		k = 1;
		for (j = 0; j < x-1; j++)
		{
			if (f[j] == f[j+1])
			   k++;
			else
			{
				g.push_back(mp(k,f[j]));
				k = 1;
			}
		}
		g.push_back(mp(k,f[x-1]));
		sort(g.begin(), g.end());
		ll start = 0;
		x = g.size();
		for (j = 0; j < x-1; j++)
		{
			if (g[j].X != g[j+1].X)
			{
				bool fl = false;
				used_col.clear();
				for (k = start; k <= j; k++)
					if (color[g[k].Y] == 0)
					   col_cnt[0]--, color[g[k].Y] = next_color, col_cnt[next_color]++, fl = true;
					else
					{
						if (used[color[g[k].Y]].size() == 0)
						   used_col.push_back(color[g[k].Y]);
						used[color[g[k].Y]].push_back(g[k].Y);
					}
				if (fl)
				   next_color++;
				for (k = 0; k < used_col.size(); k++)
				{
					if (used[used_col[k]].size() != col_cnt[used_col[k]])
					{
						for (int l = 0; l < used[used_col[k]].size(); l++)
						{
							col_cnt[used_col[k]]--;
							color[used[used_col[k]][l]] = next_color;
							col_cnt[next_color]++;
						}
						next_color++;
					}
					used[used_col[k]].clear();
				}
				start = j+1;
			}
		}
		
		j = x-1;
		bool fl = false;
		used_col.clear();
		for (k = start; k <= j; k++)
			if (color[g[k].Y] == 0)
			   col_cnt[0]--, color[g[k].Y] = next_color, col_cnt[next_color]++, fl = true;
			else
			{
				if (used[color[g[k].Y]].size() == 0)
				   used_col.push_back(color[g[k].Y]);
				used[color[g[k].Y]].push_back(g[k].Y);
			}
		if (fl)
		   next_color++;
		for (k = 0; k < used_col.size(); k++)
		{
			if (used[used_col[k]].size() != col_cnt[used_col[k]])
			{
				for (int l = 0; l < used[used_col[k]].size(); l++)
				{
					col_cnt[used_col[k]]--;
					color[used[used_col[k]][l]] = next_color;
					col_cnt[next_color]++;
				}
				next_color++;
			}
			used[used_col[k]].clear();
		}
	}
	ll ans = 1;
	for (i = 0; i <= 5000000; i++)
		ans = (ans*fac[col_cnt[i]])%MOD;
	cout << ans << endl;
    return 0;
}