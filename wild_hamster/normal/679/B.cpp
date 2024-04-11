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
#define INF (1LL+(ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 19
#define mx 112
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 1000
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,i,j,k,kk,l,r,x,y,z,ans,flag;
ll dp[1005][1005], a[100505], b[105005];
string s;
ll cube(ll x)
{
	return x*x*x;
}
ll make(ll x)
{
	ll l = upper_bound(a,a+N,x)-a-1;
	return l;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	i = 0;
	ll pointer = 1;
	while (a[i]+cube(pointer) <= (ll)1e+15)
	{
		if (a[i]+cube(pointer) < cube(pointer+1))
		{
			i++;
			a[i] = a[i-1] + cube(pointer);
		} else
		{
			pointer++;
			//i++;
			//a[i] = a[i-1] + cube(pointer);
		}
	}
	ll x = make(n), p = 100000;
	cout << x << " ";
	ll ans = 0;
	for (i = p; i >= 1; i--)
	{
		ll tmp = 0;
		n = min(n, cube(i+1)-1);
		while (make(n-cube(i)) >= x-1 && x > 0 && tmp+cube(i) < cube(i+1))
		{
			tmp += cube(i);
			//cout << i << " " << make(n-cube(i)) << endl;
			x--;
			ans += cube(i);
			n -= cube(i);
		}
	}
	cout << ans << endl;
	return 0;
}