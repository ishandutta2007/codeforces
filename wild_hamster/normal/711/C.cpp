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
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 500000
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r;
ll a[1005], c[105][105], dp[105][105][105];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m >> k;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
		for (j = 1; j <= m; j++)
			cin >> c[i][j];
	for (i = 0; i <= n; i++)
		for (j = 0; j <= m; j++)
			for (l = 0; l <= k; l++)
				dp[i][j][l] = INF;
	if (a[0] == 0)
	{
		for (i = 1; i <= m; i++)
			dp[0][i][1] = c[0][i];
	} else
	  dp[0][a[0]][1] = 0;
	for (i = 1; i < n; i++)
		for (j = 1; j <= m; j++)
			for (l = 0; l <= k; l++)
				for (int color = 1; color <= m; color++)
				if (a[i] == color || a[i] == 0)
				{
					if (color == j)
					   dp[i][color][l] = min(dp[i][color][l], dp[i-1][j][l] + (a[i]==color?0:c[i][color]));
					else
						dp[i][color][l+1] = min(dp[i][color][l+1], dp[i-1][j][l] + (a[i]==color?0:c[i][color]));
				}
	/*for (i = 0; i <= n; i++)
		for (j = 0; j <= m; j++)
			for (l = 0; l <= k; l++)
				cout << i << " " << j << " " << l << " " << dp[i][j][l] << endl;*/
	ll ans = INF;
	for (i = 1; i <= m; i++)
		ans = min(ans, dp[n-1][i][k]);
	if (ans == INF)
	   cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}