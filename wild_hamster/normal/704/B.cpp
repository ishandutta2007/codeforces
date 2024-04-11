#include <iostream>
//#include <cmath>
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
#define MOD3 10000000000000061LL
#define INF ((ll)1e+18)
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
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,y,z,m,k,l,r,flag,timer,sz, q, total, ans, k1,k2;
ll a[5005], b[5005], c[5005], d[5005], x[5005], dp[5][5005][5], s, e;
ll o(ll y)
{
	if (y == 0)
	   return 55;
	return x[y] - x[y-1];
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> s >> e;
	s--;
	e--;
	for (i = 0; i < n; i++)
		cin >> x[i];
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
		cin >> b[i];
	for (i = 0; i < n; i++)
		cin >> c[i];
	for (i = 0; i < n; i++)
		cin >> d[i];
	ll fs = 0, fe = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j <= n; j++)
			for (k = 0; k < 5; k++)
				dp[i][j][k] = INF;
	dp[0][0][1] = 0;
	for (i = 0; i < n; i++)
	{
	 ll cur = i%2;
	 ll nxt = (i+1)%2;
	 for (j = 0; j <= n; j++)
		 for (k = 0; k < 3; k++)
			 dp[nxt][j][k] = INF;
	 for (j = 0; j <= n; j++)
		 for (k = 0; k < 3; k++)
		 	 if (dp[cur][j][k] != INF)
			 {
			 	if (i == e)
			 	{
			 		if (j > 0 && (j + j + k - 2 > 0 || i == n-1))
			 		{
					   dp[nxt][j-1][k+1] = min(dp[nxt][j-1][k+1], dp[cur][j][k] + (j+j+k-1)*o(i) + a[i]);
					}
					dp[nxt][j][k+1] = min(dp[nxt][j][k+1], dp[cur][j][k] + (j+j+k-1)*o(i) + b[i]);
			 	} else
			 	if (i == s)
			 	{
					if (j+k-1 > 0 && (j-1+j-1+k > 0 || i == n-1))
					{
						dp[nxt][j][k-1] = min(dp[nxt][j][k-1], dp[cur][j][k] + (j+j+k-1)*o(i) + c[i]);
					}
					dp[nxt][j+1][k-1] = min(dp[nxt][j+1][k-1], dp[cur][j][k] + (j+j+k-1)*o(i) + d[i]);
			 	} else
			 	{
  	  			  if (j > 0 && j + k - 1 > 0 && (j + j + k - 2 > 1 || i == n-1))
		   		  	 dp[nxt][j-1][k] = min(dp[nxt][j-1][k], dp[cur][j][k] + (j+j+k-1)*o(i) + a[i] + c[i]);
				  if (j > 0)
					 dp[nxt][j][k] = min(dp[nxt][j][k], dp[cur][j][k] + (j+j+k-1)*o(i) + a[i] + d[i]);
				  if (j+k-1 > 0)
					 dp[nxt][j][k] = min(dp[nxt][j][k], dp[cur][j][k] + (j+j+k-1)*o(i) + b[i] + c[i]);
				  dp[nxt][j+1][k] = min(dp[nxt][j+1][k], dp[cur][j][k] + (j+j+k-1)*o(i) + b[i] + d[i]);
			 	}
			 }
	}

	cout << dp[n%2][0][1] << endl;
	return 0;
}