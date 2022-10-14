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
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y, a[1005000];
string s;
vector <ll> prms;
ll Abs(ll x)
{
	return x>0?x:-x;
}
ll binpow(ll x, ll y, ll md)
{
	if (y == 0)
	   return 1LL%md;
	ll tmp = binpow(x, y/2, md);
	tmp = (tmp*tmp)%md;
	if (y % 2 == 0)
	   return tmp;
	return (x*tmp)%md;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
	   return a;
	return gcd(b,a%b);
}
int main()
{
	//freopen("input.txt","r",stdin);
	// ((10^n-1)/9)%k = 0
	// (10^n-1)%k = 0
	// n - ?
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	reverse(a, a+n);
	x = (ll)1e+10;
	ll ans = 0;
	for (i = 0; i < n; i++)
		if (a[i] < x)
		{
			x = a[i];
			ans += x;
		} else
		{
			x = max(x-1,0LL);
			ans += x;
		}
	cout << ans << endl;
	return 0;
}