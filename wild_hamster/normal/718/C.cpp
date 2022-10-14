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
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko;
ll a[1000500];
long long to_push[1005000];
string s;
struct fib
{
	ll x,y;
	fib()
	{
		x = 0;
		y = 1;
	}
	fib(long long x, long long y)
	{
		if (x >= MOD)
		   this->x = x%MOD;
		else
			this->x = x;
		if (y >= MOD)
		   this->y = y%MOD;
		else
			this->y = y;
	}
};
fib t[400500];
fib add(fib x, fib y)
{
	return fib((x.x + y.x), (x.y + y.y));
}

fib multiply(fib x, fib y)
{
	return fib(
	(1LL*x.x*(y.y-y.x+MOD) + 1LL*x.y*y.x),
	(1LL*x.x*y.x + 1LL*x.y*y.y));
}

fib binpow(long long x)
{
	if (x == 0)
	{
		return fib();
	}
	fib tmp = binpow(x/2);
	tmp = multiply(tmp, tmp);
	if (x&1)
	{
	   tmp = multiply(fib(1,1),tmp);
	   return tmp;
 	}
	return tmp;
}

fib updateF(fib x, long long y)
{
	if (y == 0)
	   return x;
	fib t = binpow(y);
	return fib((1LL*x.x*(t.y-t.x+MOD) + 1LL*x.y*t.x),(1LL*x.x*t.x + 1LL*x.y*t.y));
}

void build (ll a[], ll v, ll tl, ll tr) {
	if (tl == tr)
		t[v] = binpow(a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = add(t[v*2], t[v*2+1]);
	}
}

fib sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
	{
		return fib(0,0);
	}
	if (l == tl && r == tr)
		return updateF(t[v], to_push[v]);
	int tm = (tl + tr) / 2;
	t[v] = updateF(t[v], to_push[v]);
	to_push[v*2] += to_push[v];
	to_push[v*2+1] += to_push[v];
	to_push[v] = 0;
	return add(sum (v*2, tl, tm, l, min(r,tm)), sum (v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update (int v, int tl, int tr, int l, int r, int ad) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		to_push[v] += ad;
	else {
		int tm = (tl + tr) / 2;
		to_push[v*2] += to_push[v];
		to_push[v*2+1] += to_push[v];
		to_push[v] = 0;
		update (v*2, tl, tm, l, min(r,tm), ad);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, ad);
		fib t1 = updateF(t[v*2], to_push[v*2]);
		fib t2 = updateF(t[v*2+1], to_push[v*2+1]);
		t[v] = add(t1, t2);
	}
}


int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	build(a, 1, 0, n-1);
	for (i = 0; i < m; i++)
	{
		ll test;
		scanf("%d", &test);
		if (test == 1)
		{
			scanf("%d %d %d", &l, &r, &x);
			l--;
			r--;
			update(1, 0, n-1, l, r, x);
		} else
		{
			scanf("%d %d", &l, &r);
			l--;
			r--;
		  	printf("%d\n", sum(1, 0, n-1, l, r).x);
		}
	}
	return 0;
}