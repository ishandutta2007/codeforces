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
#define N 1000
#define SUM 23423
#define MAG 100000000
#define OPEN 0
#define CLOSE 1
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c;
ll a[200500], used[200500], dp[100500];
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = 0;
	for (i = 0; i < n; i++)
	{
		dp[i+1] = dp[i] + 20;
		ll l = upper_bound(a, a+n, a[i]-90) - a;
		dp[i+1] = min(dp[i+1], dp[l] + 50);
		l = upper_bound(a, a+n, a[i]-1440) - a;
		dp[i+1] = min(dp[i+1], dp[l] + 120);
	}
	for (i = 0; i < n; i++)
		cout << dp[i+1] - dp[i] << endl;
    return 0;
}