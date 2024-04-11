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
ll k,i,j,n,m,d,x,y,w,dw,l;
ll a[100500], b[100500], out[100500], in[100500];
string s;
set<pii> f;
set<pii>::iterator itr;
vector <ll> g[100500];
map<pii,ll> to_save;
vector<ll> ans;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
		to_save[mp(a[i],b[i])] = i+1;
		g[a[i]].push_back(b[i]);
		out[a[i]]++;
		in[b[i]]++;
	}
	for (i = 1; i <= n; i++)
		f.insert(mp(in[i],i));
	while (!f.empty())
	{
		if (f.size() == 1)
		{
			itr = f.begin();
			ans.push_back((*itr).Y);
			f.erase(itr);
			continue;
		}
		itr = f.begin();
		ll v = (*itr).Y;
		//cout << v << " " << f.size() << endl;
		ans.push_back(v);
		itr++;
		if ((*itr).X == 0)
		{
			cout << -1 << endl;
			return 0;
		}
		f.erase(mp(0LL,v));
		for (i = 0; i < g[v].size(); i++)
		{
			ll to = g[v][i];
			f.erase(mp(in[to],to));
			in[to]--;
			f.insert(mp(in[to],to));
		}
	}
	ll total = 0;
	ll sz = ans.size();
	for (i = 0; i < sz-1; i++)
		total = max(total, to_save[mp(ans[i],ans[i+1])]);
	cout << total << endl;
	return 0;
}