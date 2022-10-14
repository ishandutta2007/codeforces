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
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[500500], b[500500], d[500500];
pii c[500500];
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main()
{
    ll n, A, cj, cm, m;
    cin >> n >> A >> cj >> cm >> m;
    ll sum = 0;
    for (i = 0; i < n; i++)
    {
    	scanf("%I64d", &a[i]);
    	sum += a[i];
    	c[i].first = a[i];
    	c[i].second = i;
    }
    sort(c, c+n);
    for (i = 0; i < n; i++)
    	d[c[i].second] = i;
    	
    if (A*n - sum <= m)
    {
    	cout << cj*n + cm*A << endl;
    	for (i = 0; i < n; i++)
    		printf("%I64d ",A);
    	cout << endl;
    	return 0;
    }
    sort(a, a+n);
    ll ans = -1;
	ll val = 0;
	for (i = 0; i < n; i++)
	{
		b[i] = a[i]*i - val;		
		val += a[i];
	}
	ll p = 0;
	k = n;
	if (a[n-1] != A)
	{
		ll can = m;
		ll pr = 0;
		ll l = 0, r = i-1;
		while (l < r)
		{
			ll mid = (l+r+1)/2;
			if (b[mid] <= can)
				l = mid;
			else
				r = mid - 1;
		}
		ll level = (can - b[l])/(l+1) + a[l];
		if (level * cm + pr * cj > ans)
		{
			ans = level * cm + pr * cj;
			q = level;
			k = l+1;
			y = n;
		}
	}
	for (i = n-1; i >= 1; i--)
	{
		p += A - a[i];
		if (p > m)
			break;
		ll can = m - p;
		ll pr = n-i;
		ll l = 0, r = i-1;
		while (l < r)
		{
			ll mid = (l+r+1)/2;
			if (b[mid] <= can)
				l = mid;
			else
				r = mid - 1;
		}
		ll level = (can - b[l])/(l+1) + a[l];
		if (level * cm + pr * cj > ans)
		{
			ans = level * cm + pr * cj;
			q = level;
			k = l+1;
			y = i;
		}
	}
	cout << ans << endl;
	for (i = 0; i < k; i++)
		a[i] = q;
	for (i = y; i < n; i++)
		a[i] = A;
	for (i = 0; i < n; i++)
		printf("%I64d ", a[d[i]]);
	cout << endl;
    return 0;
}