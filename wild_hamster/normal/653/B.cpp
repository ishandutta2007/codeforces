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
ll a[100500], b[100500];
string s[50], t[50];
set<string> dp[1000][10];
set<string>::iterator itr;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m;
	for (i = 0; i < m; i++)
		cin >> s[i] >> t[i];
	dp['a'][0].insert("a");
	for (i = 0; i < n-1; i++)
		for (j = 'a'; j <= 'f'; j++)
		{
			for (k = 0; k < m; k++)
				if (t[k][0] == j)
				{
					for (itr = dp[j][i].begin(); itr != dp[j][i].end(); itr++)
					{
					 string tmp = s[k];
					 tmp.append((*itr).substr(1));
					 //cout << tmp << endl;
				   	 dp[s[k][0]][i+1].insert(tmp);
  					}
	   			   }
		}
	ll ans = 0;
	for (i = 'a'; i <= 'f'; i++)
		ans += dp[i][n-1].size();
	cout << ans << endl;
	return 0;
}