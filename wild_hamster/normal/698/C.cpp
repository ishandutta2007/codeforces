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
ll i,j,n,x,y,z,m,k,l,r,flag,timer,glob,sz, q;
ld dp[1048600], a[55], c[55], ans[55];
ll b[55], d[55];
vector<ll> g[25];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> x;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] != 0)
		{
			d[m] = i;
		   c[m++] = a[i];
		}
	}
	for (i = 0; i < (1<<m); i++)
	{
		ll bits = 0;
		for (j = 0; j < m; j++)
			if ((i&(1<<j)) != 0)
			   bits++;
		g[bits].push_back(i);
	}
	x = min(x, m);
	dp[0] = 1;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < g[i].size(); j++)
		{
			ll v = g[i][j];
			q = 0;
			ld sum = 0;
			for (k = 0; k < m; k++)
				if ((v&(1<<k)) == 0)
				   b[q++] = k;
				else
					sum += c[k];
			for (k = 0; k < q; k++)
			{
				ll cur = b[k];
				dp[v|(1<<cur)] += dp[v]*(c[cur]/(1.-sum));
			}
		}
	}
	k = x;
	for (i = 0; i < g[k].size(); i++)
	{
		ll v = g[k][i];
		for (j = 0; j < m; j++)
			if ((v&(1<<j))!=0)
			   ans[d[j]] += dp[v];
	}
	for (i = 0; i < n; i++)
		printf("%.12f ",(double)ans[i]);
	return 0;
}