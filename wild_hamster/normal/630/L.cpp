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
ll dp[1005][1005];
string s;
ll fib[600500];
ll gcd(ll a, ll b)
{
	if (b == 0)
	   return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
	return a*b/gcd(a,b);
}
vector<ll> f;
int main()
{
	//freopen("input.txt","r",stdin);
	//C(n+2, 3)*C(n+4,5)

	cin >> n;
	while (n)
	{
		f.push_back(n%10);
		n /= 10;
	}
	n = f[0]*100 + f[1] * 10 + f[2]*1000 + f[3] + f[4]*10000;
	x = 1;
	for (i = 0; i < 5; i++)
	{
		x = (x*n)%100000;
	}
	f.clear();
	while (x)
	{
		f.push_back(x%10);
		x /= 10;
	}
	while (f.size() < 5)
	{
		  f.push_back(0);
	}
	for (i = 4; i >= 0; i--)
		cout << f[i];
	cout << endl;
	return 0;
}