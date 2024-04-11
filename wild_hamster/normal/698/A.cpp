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
#define INF ((ll)1e+9)
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
ll i,j,n,x,y,z,m,k,l,r,flag,timer,glob,sz, w[100500];
ll a[100500], dp[100005][4];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 0; i <= n; i++)
		for (j = 0; j < 3; j++)
			dp[i][j] = n+500;
	dp[0][0] = 0;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		   dp[i+1][0] = min(min(dp[i][0], dp[i][1]), dp[i][2]) + 1;
		if (x == 1)
		   dp[i+1][0] = min(min(dp[i][0], dp[i][1]), dp[i][2]) + 1, dp[i+1][1] = min(dp[i][0], dp[i][2]);
		if (x == 2)
		   dp[i+1][0] = min(min(dp[i][0], dp[i][1]), dp[i][2]) + 1, dp[i+1][2] = min(dp[i][0], dp[i][1]);
		if (x == 3)
		{
			dp[i+1][0] = min(min(dp[i][0], dp[i][1]), dp[i][2]) + 1;
			dp[i+1][1] = min(dp[i][0], dp[i][2]);
			dp[i+1][2] = min(dp[i][0], dp[i][1]);
		}
	}
	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;
	return 0;
}