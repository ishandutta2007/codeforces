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
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r,p;
ll a[500500], forbidden[50];
ll ta[900500], tb[900500];

ll suma (ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return ta[v];
	ll tm = (tl + tr) / 2;
	return suma (v*2, tl, tm, l, min(r,tm))
		+ suma (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void updatea (ll v, ll tl, ll tr, ll pos, ll new_val) {
	if (tl == tr)
		ta[v] = new_val;
	else {
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			updatea (v*2, tl, tm, pos, new_val);
		else
			updatea (v*2+1, tm+1, tr, pos, new_val);
		ta[v] = ta[v*2] + ta[v*2+1];
	}
}

ll sumb (ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return tb[v];
	ll tm = (tl + tr) / 2;
	return sumb (v*2, tl, tm, l, min(r,tm))
		+ sumb (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void updateb (ll v, ll tl, ll tr, ll pos, ll new_val) {
	if (tl == tr)
		tb[v] = new_val;
	else {
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			updateb (v*2, tl, tm, pos, new_val);
		else
			updateb (v*2+1, tm+1, tr, pos, new_val);
		tb[v] = tb[v*2] + tb[v*2+1];
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	ll q;
	cin >> n >> k >> x >> y >> q;
	for (i = 0; i < q; i++)
	{
		ll test;
		ll ans = 0;
		scanf("%I64d",&test);
		if (test == 1)
		{
			scanf("%I64d%I64d",&l,&r);
			a[l] += r;
			updatea(1,1,n,l,min(x,a[l]));
			updateb(1,1,n,l,min(y,a[l]));
		} else
		{
			scanf("%I64d",&p);
			ans += suma(1,1,n,p+k,n);
			ans += sumb(1,1,n,1,p-1);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}