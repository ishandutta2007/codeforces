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
ll k,i,j,n,m,d,x,y,last_time;
ll a[1005605], fac[1005000];
set<pair<string,string> > was_used;
map<string, vector<string> > f;
map<string, vector<string> >::iterator itr;
map<vector<string>, vector<string> > ans;
map<vector<string>, vector<string> >::iterator itr2;
char s[150];
vector<string> total[1005000];
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		scanf("%s",s);
		m = strlen(s);
		for (j = 7; j < m; j++)
			if (s[j] == '/')
			   break;
		string t1,t2;
		for (k = 7; k < j; k++)
			t1.push_back(s[k]);
		if (j != m)
		   t2.push_back('/');
		for (k = j+1; k < m; k++)
			t2.push_back(s[k]);
		if (was_used.find(mp(t1,t2)) == was_used.end())
		   f[t1].push_back(t2);
		was_used.insert(mp(t1,t2));
	}
	for (itr = f.begin(); itr != f.end(); itr++)
	{
		string key = (*itr).X;
		sort(f[key].begin(), f[key].end());
		ans[f[key]].push_back(key);
	}
	ll sz = 0;
	for (itr2 = ans.begin(); itr2 != ans.end(); itr2++)
	{
		vector<string> key = (*itr2).X;
		if (ans[key].size() != 1)
		{
			for (i = 0; i < ans[key].size(); i++)
				total[sz].push_back(ans[key][i]);
			sz++;
		}
	}
	cout << sz << endl;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < total[i].size(); j++)
			cout << "http://" << total[i][j] << " ";
		cout << endl;
	}
	return 0;
}