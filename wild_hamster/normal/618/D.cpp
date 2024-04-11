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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x,y, w[200500];
string s1,s2,s3,s,t;
ll dp[200500][3];
vector <ll> g[205000];
void dfs(ll v, ll p = -1)
{
	if (w[v] == 0)
	{
		dp[v][0] = 0;
		dp[v][1] = 1;
		return;
	}
	if (w[v] == 1)
	{
		for (int i = 0; i < g[v].size(); i++)
		{
			ll to = g[v][i];
			if (to != p)
			{
				dfs(to, v);
				dp[v][0] = dp[to][0];
				dp[v][1] = min(dp[to][1] + 1, dp[to][0]+1);
			}
		}
		return;
	}
	ll sum = 0, min1 = INF, min2 = INF;
	for (int i = 0; i < g[v].size(); i++)
	{
		ll to = g[v][i];
		if (to != p)
		{
			dfs(to, v);
			sum += dp[to][1];
			if (dp[to][0] - dp[to][1] < min1)
				min2 = min1, min1 = dp[to][0] - dp[to][1];
			else
			if (dp[to][0] - dp[to][1] < min2)
				min2 = dp[to][0] - dp[to][1];
		}
	}

	dp[v][0] = min(sum + min1, sum);
	dp[v][1] = min(sum + min1 + min2, min(sum+min1, sum)) + 1;
}
int main()
{
    cin >> n >> x >> y;
    for (i = 0; i < n-1; i++)
    {
    	scanf("%I64d %I64d",&l,&r);
    	g[l].push_back(r);
    	g[r].push_back(l);
    	w[l]++;
    	w[r]++;
    	if (w[l] == n-1)
    		k = 1;
    	if (w[r] == n-1)
    		k = 1;
    }
    if (x >= y)
    {
    	if (n == 2)
    		cout << x << endl;
    	else
    	if (k == 1)
    		cout << y*(n-2) + x << endl;
    	else
    		cout << y*(n-1) << endl;
    	return 0;
    }
    k = 0;
    for (i = 2; i <= n; i++)
    {
    	w[i]--;
    }
    dfs(1);
    k =  min(dp[1][0]+1,dp[1][1]);
    k--;
    //for (i = 1; i <= n; i++)
	//	cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    cout << k*y + (n-k-1)*x << endl;
	return 0;
}