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
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r,p,d;
pii a[500500];
ll rmq[300500][25], lg2[300500];

ll findmin(ll l, ll r)
{
	if (l > r)
	   return INF;
	ll vl = lg2[r-l+1];
	return min(rmq[l][vl], rmq[r+1-(1<<vl)][vl]);
}

int main()
{
	lg2[1] = 0;
	for (i = 2; i <= 257878; i++)
	{
		ll j = i;
		ll k = 0;
		while (j != 1)
			  j /= 2, k++;
		lg2[i] = k;
	}
	
	
	cin >> d >> m >> n;
	for (i = 0; i < n; i++)
		scanf("%I64d %I64d",&a[i].X, &a[i].Y);
	sort(a,a+n);
	for (i = 1; i < n; i++)
		if (a[i].X - a[i-1].X > m)
		{
			cout << -1 << endl;
			return 0;
		}
	if (a[0].X > m)
	{
		cout << -1 << endl;
		return 0;
	}
	if (d - a[n-1].X > m)
	{
		cout << -1 << endl;
		return 0;
	}
	
	for (i = 0; i < n; i++)
		rmq[i][0] = a[i].Y;
	for (j = 1; j < 19; j++)
		for (i = 0; i < n; i++)
			if (i+(1<<(j-1)) < n)
			   rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
	ll ans = 0;
	ll bak = m;
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		   bak -= a[i].X;
		else
			bak -= a[i].X - a[i-1].X;

		//cout << ans << " " << bak << endl;
		if (a[i].X + bak >= d)
		   break;
		ll pos = upper_bound(a, a+n, mp(bak+a[i].X,INF)) - a - 1;
		ll min_cost = findmin(i+1,pos);
		if (min_cost < a[i].Y)
		   continue;
		pos = upper_bound(a, a+n, mp(m+a[i].X,INF)) - a - 1;
		min_cost = findmin(i+1,pos);
		if (min_cost >= a[i].Y)
		{
			ll to_add = min(d-bak-a[i].X, m-bak);
			bak += to_add;
			ans += to_add*a[i].Y;
			continue;
		}
		ll l = bak+1, r = m;
		while (l < r)
		{
			ll mid = (l+r-1)/2;
			pos = upper_bound(a, a+n, mp(mid+a[i].X,INF)) - a - 1;
			if (findmin(i+1,pos) < a[i].Y)
			   r = mid;
			else
				l = mid+1;
		}
		ll to_add = l-bak;
		bak += to_add;
		ans += to_add*a[i].Y;
	}
	cout << ans << endl;
	return 0;
}