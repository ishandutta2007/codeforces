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
ll a[100500];
ll binpow(ll x, ll y)
{
	if (y == 0)
	   return 1;
	ll tmp = binpow(x,y/2);
	tmp = (tmp*tmp)%MOD;
	if (y % 2)
	   return (x*tmp)%MOD;
	return tmp;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	ll flag1 = 1;
	ll flag2 = 0;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i]%2 == 0)
		   flag2 = 1;
		if (a[i] != 1)
		   flag1 = 0;
	}
	if (flag1)
	{
	   cout << "0/1" << endl;
	   return 0;
	}
	if (flag2)
	{
		ll ans = 2;
		for (i = 0; i < n; i++)
			ans = binpow(ans, a[i]);
		ans = ans*binpow(2,MOD-2)%MOD;
		cout << (ans+1+MOD)*binpow(3,MOD-2)%MOD << "/" << ans << endl;
	} else
	{
		ll ans = 2;
		for (i = 0; i < n; i++)
			ans = binpow(ans, a[i]);
		ans = ans*binpow(2,MOD-2)%MOD;
		cout << (ans-1+MOD)*binpow(3,MOD-2)%MOD << "/" << ans  << endl;
	}
	return 0;
}