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
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r;
ll dp[100500];
string lst[10050],s,s1;
char t[1005];
vector <ll> res[100500];
map<string, string> thing;
vector <string> ans;
struct node
{
	ll letters[26];
	bool e;
};
string lw(string x)
{
	for (int i = 0; i < x.size(); i++)
		if (x[i] >= 'A' && x[i] <= 'Z')
		   x[i] += 'a' - 'A';
	return x;
}
node nd[1005000];
int main()
{
	cin >> n;
	cin >> s;
	dp[0] = 1;
	cin >> m;
	for (i = 0; i <= 1000050; i++)
		for (j = 0; j < 26; j++)
			nd[i].letters[j] = 0, nd[i].e = false;
	ll sz = 1;
	for (i = 0; i < m; i++)
	{
		scanf("%s",t);
		k = strlen(t);
		s1.clear();
		ll cur = 1;
		for (j = 0; j < k; j++)
		{
			s1.push_back(t[j]);
			if (t[j] >= 'A' && t[j] <= 'Z')
			   t[j] += 'a' - 'A';
			if (nd[cur].letters[t[j]-'a'] == 0)
			{
				nd[cur].letters[t[j]-'a'] = ++sz;
				cur = sz;
			} else
			  cur = nd[cur].letters[t[j]-'a'];
		}
		nd[cur].e = true;
		thing[lw(s1)] = s1;
	}
	for (i = 0; i < n; i++)
	{
		ll cur = 1;
		string tmp;
		for (j = i; j >= 0; j--)
		{
			tmp.push_back(s[j]);
			if (nd[cur].letters[s[j]-'a'] == 0)
			   break;
			cur = nd[cur].letters[s[j]-'a'];
			if (dp[j] == 1 && nd[cur].e)
			{
				dp[i+1] = 1;
				lst[i+1] = thing[tmp];
				break;
			}
		}
	}
	if (dp[n] == 1)
	{
		while (n)
		{
			ans.push_back(lst[n]);
			n -= lst[n].size();
		}
	}
	reverse(ans.begin(), ans.end());
	for (i = 0; i < ans.size(); i++)
	if (i == 0)
	   cout << ans[i];
	else
		cout << " " << ans[i];
	cout << endl;
	return 0;
}