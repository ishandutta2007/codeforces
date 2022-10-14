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
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer;
ll dp[76][1048577];
vector<pii> g[85];
string s;
ll get_bin(string x)
{
	ll sz = x.size();
	ll ans = 0;
	for (int i = 0; i < sz; i++)
	{
		ans = ans*2 + x[i] - '0';
		if (ans > 20)
		   break;
	}
	return ans;
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	//print();
	cin >> n;
	cin >> s;
	for (i = 0; i < n; i++)
		for (j = i+1; j <= n; j++)
		{
			ll x = get_bin(s.substr(i,j-i));
			if (x > 0 && x <= 20)
			{
			   g[i].push_back(mp(j,x));
			 //  cout << i << " " << j << " " << x << endl;
			}
		}
	for (i = 0; i <= n-1; i++)
		dp[i][0] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < 1048576; j++)
			if (dp[i][j] > 0)
			{
				for (k = 0; k < g[i].size(); k++)
				{
					ll to = g[i][k].X;
					ll val = g[i][k].Y;
				//	cout << to << " " << val << " " << i << " " << j << " " << dp[i][j] << endl;
					dp[to][j|(1<<(val-1))] += dp[i][j];
					if (dp[to][j|(1<<(val-1))] >= MOD)
					   dp[to][j|(1<<(val-1))] -= MOD;
				}
			}
	/*for (i = 0; i <= n; i++)
		for (j = 0; j <= 8; j++)
			cout << i << " " << j << " " << dp[i][j] << endl;*/
	long long ans = 0;
	for (i = 0; i <= n; i++)
		for (j = 1; j <= 20; j++)
			ans += dp[i][(1<<j)-1];
	cout << ans%MOD << endl;
    return 0;
}