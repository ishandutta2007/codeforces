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
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r;
ll dp[2005][2005][4], md[1001005];
ll a[300005];
string s,t;
int main()
{
	//freopen("input.txt","r",stdin);
	ll d;
	cin >> m >> d >> s >> t;
	ll n = s.size();
	for (i = 0; i < n; i++)
		s[i] -= '0';
	for (i = 0; i < n; i++)
		t[i] -= '0';
	md[0] = 1%m;
	for (i = 1; i <= 2000; i++)
		md[i] = (md[i-1]*10)%m;
	dp[0][0][3] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			for (k = 0; k < 4; k++)
				dp[i][j][k] %= MOD;
		if (i % 2 == 1)
		{
			for (j = 0; j < m; j++)
				if (d == s[i] && d == t[i])
				{
				   dp[i+1][(j + d*md[n-i-1])%m][3] += dp[i][j][3];
				   dp[i+1][(j + d*md[n-i-1])%m][2] += dp[i][j][2];
				   dp[i+1][(j + d*md[n-i-1])%m][1] += dp[i][j][1];
				   dp[i+1][(j + d*md[n-i-1])%m][0] += dp[i][j][0];
 			    }
				else
				if (d == s[i])
				{
				   dp[i+1][(j + d*md[n-i-1])%m][1] += dp[i][j][1] + dp[i][j][3];
				   dp[i+1][(j + d*md[n-i-1])%m][0] += dp[i][j][0];
				   if (d < t[i])
					  dp[i+1][(j + d*md[n-i-1])%m][0] += dp[i][j][2];
				} else
				if (d == t[i])
				{
				   dp[i+1][(j + d*md[n-i-1])%m][2] += dp[i][j][2] + dp[i][j][3];
				   dp[i+1][(j + d*md[n-i-1])%m][0] += dp[i][j][0];
				   if (d > s[i])
					  dp[i+1][(j + d*md[n-i-1])%m][0] += dp[i][j][1];
				} else
				if (d > s[i] && d < t[i])
				{
					dp[i+1][(j + d*md[n-i-1])%m][0] +=
					dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3];
				} else
				{
				  dp[i+1][(j + d*md[n-i-1])%m][0] += dp[i][j][0];
				  if (d > s[i])
					  dp[i+1][(j + d*md[n-i-1])%m][0] += dp[i][j][1];
				  if (d < t[i])
					  dp[i+1][(j + d*md[n-i-1])%m][0] += dp[i][j][2];
  		  		  }
		} else
		{
			for (j = 0; j < m; j++)
				for (k = 0; k < 10; k++)
				if (k != d)
				{
					if (k == s[i] && k == t[i])
					{
					   dp[i+1][(j + k*md[n-i-1])%m][3] += dp[i][j][3];
					   dp[i+1][(j + k*md[n-i-1])%m][2] += dp[i][j][2];
					   dp[i+1][(j + k*md[n-i-1])%m][1] += dp[i][j][1];
					   dp[i+1][(j + k*md[n-i-1])%m][0] += dp[i][j][0];
	 			    }
					else
					if (k == s[i])
					{
					   dp[i+1][(j + k*md[n-i-1])%m][1] += dp[i][j][1] + dp[i][j][3];
					   dp[i+1][(j + k*md[n-i-1])%m][0] += dp[i][j][0];
					   if (k < t[i])
					   	  dp[i+1][(j + k*md[n-i-1])%m][0] += dp[i][j][2];
					} else
					if (k == t[i])
					{
					   dp[i+1][(j + k*md[n-i-1])%m][2] += dp[i][j][2] + dp[i][j][3];
					   dp[i+1][(j + k*md[n-i-1])%m][0] += dp[i][j][0];
					   if (k > s[i])
					   	  dp[i+1][(j + k*md[n-i-1])%m][0] += dp[i][j][1];
					} else
					if (k > s[i] && k < t[i])
					{
						dp[i+1][(j + k*md[n-i-1])%m][0] +=
						dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3];
					} else
					{
					  dp[i+1][(j + k*md[n-i-1])%m][0] += dp[i][j][0];
					  if (k < t[i])
					   	  dp[i+1][(j + k*md[n-i-1])%m][0] += dp[i][j][2];
					  if (k > s[i])
					   	  dp[i+1][(j + k*md[n-i-1])%m][0] += dp[i][j][1];
	  		  		  }
				}
		}
	}
	ll ans = 0;
		for (j = 0; j < 4; j++)
			ans += dp[n][0][j];
	ans %= MOD;
	cout << ans << endl;
	return 0;
}