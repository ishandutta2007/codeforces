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
typedef int ll;
typedef long double ld;
using namespace std;
ll k,i,j,n,m,x,y,w,dw,l,cur;
ll a[400500], b[400500], used[400500];
vector<ll> g[400500];
set<ll> not_used,ns;
set<ll>::iterator itr;
void dfs(ll v)
{
	//cout << v << endl;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		ll to = g[v][i];
		if (cur && to == 1)
		   continue;
		if (not_used.find(to) != not_used.end())
		{
			not_used.erase(to);
			ns.insert(to);
		}
	}
	vector<ll> tmp;
	for (itr = not_used.begin(); itr != not_used.end(); itr++)
		tmp.push_back(*itr);
	not_used = ns;
	ns.clear();
	for (int i = 0; i < tmp.size(); i++)
		dfs(tmp[i]);
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m >> k;
	for (i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
		if (a[i] == 1 || b[i] == 1)
		{
			l++;
		}
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	if (n-l-1 < k)
	{
		cout << "impossible" << endl;
		return 0;
	}
	for (i = 1; i <= n; i++)
		not_used.insert(i);
	for (i = 1; i <= n; i++)
		if (!used[i])
		{
			//cout << "koko" << endl;
			dfs(i);
			x++;
		}
	cur = 1;
	//cout << x << endl;
	if (x != 1)
	{
		cout << "impossible" << endl;
		return 0;
	}
	x = 0;
	not_used.clear();
	ns.clear();
	for (i = 2; i <= n; i++)
	{
		not_used.insert(i);
		used[i] = 0;
	}
	for (i = 2; i <= n; i++)
		if (!used[i])
		{
			//cout << "koko" << endl;
			dfs(i);
			x++;
		}
	//cout << x << endl;
	if (x <= k)
	   cout << "possible" << endl;
	else
		cout << "impossible" << endl;
	return 0;
}