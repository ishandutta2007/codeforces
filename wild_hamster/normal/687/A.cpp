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
#define MOD 1000000009
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
ll i,j,n,x,y,z,m,k,l,r,flag,timer,glob,sz;
string s,t;
vector<ll> g[N+500];
ll a[N+500];

ll part[N+500];
bool ok = true;
vector<int> q (N+500);
vector <ll> f[3];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i = 1; i <= n; i++)
		part[i] = -1;
	for (int st=1; st<=n; ++st)
	if (part[st] == -1) {
		int h=0, t=0;
		q[t++] = st;
		part[st] = 0;
		while (h<t) {
			int v = q[h++];
			for (int i=0; i<g[v].size(); ++i) {
				int to = g[v][i];
				if (part[to] == -1)
					part[to] = !part[v],  q[t++] = to;
				else
					ok &= part[to] != part[v];
			}
		}
	}
	if (ok)
	{
		for (i = 1; i <= n; i++)
			if (part[i] != -1)
			  f[part[i]].push_back(i);
		for (j = 0; j < 2; j++)
		{
		cout << f[j].size() << endl;
		for (i = 0; i < f[j].size(); i++)
			cout << f[j][i] << " ";
		cout << endl;
		}
	} else
	  cout << -1 << endl;
	return 0;
}