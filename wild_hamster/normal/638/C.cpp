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
ll k,i,j,n,m,x,y,dw,l,cur, w[200500], used[200500];
string s;
vector <ll> g[200500];
vector <ll> days[200500];
map<pii, ll> nums;
void dfs(ll v, ll p = -1)
{
	ll flag = 0;
	for (int i = 0; i < g[v].size(); i++)
	{
		ll to = g[v][i];
		if (to == p)
		{
		   flag--;
		   continue;
        }
		if (used[v] == i+1+flag)
		   flag++;
		//cout << v << " " << to << " " << i+1+flag << endl;
		days[i+1+flag].push_back(nums[mp((to>v?v:to), (to>v?to:v))]);
		used[to] = i+1+flag;
		dfs(to, v);
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n-1; i++)
	{
		cin >> x >> y;
		if (x > y)
		   swap(x,y);
		nums[mp(x,y)] = i+1;
		g[x].push_back(y);
		g[y].push_back(x);
		w[x]++;
		w[y]++;
	}
	for (i = 1; i <= n; i++)
		k = max(k, w[i]);
	dfs(1);
	cout << k << endl;
	for (i = 1; i <= k; i++)
	{
		cout << days[i].size();
		for (j = 0; j < days[i].size(); j++)
			cout << " " << days[i][j];
		cout << endl;

	}
	return 0;
}