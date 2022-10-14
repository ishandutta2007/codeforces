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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x,y;
ld dp[10005], newdp[10005];
ll a[10005];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	ll k = n*(n-1)/2;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			dp[a[j] - a[i]] += 1./(ld)k;
	for (i = 1; i <= 5000; i++)
		for (j = 1; j <= 5000; j++)
			newdp[i+j] += dp[i] * dp[j];
	ld ans = 0;
	for (i = 3; i <= 5000; i++)
	{
		for (j = 2; j < i; j++)
			ans += dp[i]*newdp[j];
	}
	printf("%.9f\n", (double)ans);
	return 0;
}