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
#define N 202100
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko;
ll dp[105][2*N+100], pa[2*N+100];
string s;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> x >> y >> k >> n;
	k *= 2;
	dp[0][x-y+N] = 1;
	for (i = 0; i < n; i++)
	{
		pa[0] = 0;
		for (j = 0; j <= 2*N; j++)
		{
			pa[j+1] = pa[j] + dp[i][j];
			if (pa[j+1] >= MOD)
			   pa[j+1] -= MOD;
		}
		ll sum = 0;
		for (j = 0; j <= k; j++)
			sum += (j+1)*dp[i][j];
		for (j = k+1; j <= 2*k; j++)
			sum += (2*k-j+1)*dp[i][j];
		sum %= MOD;
		dp[i+1][k] = sum;
		for (j = k+1; j <= 2*N-k; j++)
		{
			sum -= (pa[j]-pa[j-k-1]);
			sum += (pa[j+k+1]-pa[j]);
			while (sum < 0)
				  sum += MOD;
			while (sum >= MOD)
				  sum -= MOD;
			dp[i+1][j] = sum;
		}
	}
	ll ans = 0;
	//for (i = N-k; i <= N+k; i++)
	//	cout << i-N << " " << dp[n][i] << endl;
	for (i = N+1; i <= 2*N; i++)
		ans += dp[n][i];
	cout << ans%MOD << endl;
	return 0;
}