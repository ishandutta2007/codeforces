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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x,y;
ll a[1000500], b[1000500], primes[1005000];
map <ll, ll> was;
vector <ll> can, tmp;
int main()
{
	cin >> n >> x >> y;
	for (i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (i = 2; i <= 50000; i++)
		primes[i] = 1;
	for (i = 2; i <= 50000; i++)
		if (primes[i])
		{
			for (j = i*i; j <= 50000; j+=i)
				primes[j] = 0;
		}
	{
		ll k1 = a[0], k2 = a[0] - 1, k3 = a[0] + 1;
		for (i = 2; i <= 50000; i++)
		if (primes[i])
		{
			
			ll v = i;
			if (k1 % v == 0)
			{
				if (!was[v])
				{
					can.push_back(v);
					was[v] = 1;
				}
				while (k1 %v == 0)
					k1 /= v;				
			}
			
			if (k2 % v == 0)
			{
				if (!was[v])
				{
					can.push_back(v);
					was[v] = 1;
				}
				while (k2 %v == 0)
					k2 /= v;
			}
			if (k3 % v == 0)
			{
				if (!was[v])
				{
					can.push_back(v);
					was[v] = 1;
				}
				while (k3 %v == 0)
					k3 /= v;
			}
		}
		if (k1 > 1 && !was[k1])
		{
			was[k1] = 1;
			can.push_back(k1);
		}
		if (k2 > 1 && !was[k2])
		{
			was[k2] = 1;
			can.push_back(k2);
		}
		
		if (k3 > 1 && !was[k3])
		{
			was[k3] = 1;
			can.push_back(k3);
		}
	}
	
	{
		ll k1 = a[n-1], k2 = a[n-1] - 1, k3 = a[n-1] + 1;
		for (i = 2; i <= 50000; i++)
		if (primes[i])
		{
			
			ll v = i;
			if (k1 % v == 0)
			{
				if (!was[v])
				{
					can.push_back(v);
					was[v] = 1;
				}
				while (k1 %v == 0)
					k1 /= v;				
			}
			
			if (k2 % v == 0)
			{
				if (!was[v])
				{
					can.push_back(v);
					was[v] = 1;
				}
				while (k2 %v == 0)
					k2 /= v;
			}
			if (k3 % v == 0)
			{
				if (!was[v])
				{
					can.push_back(v);
					was[v] = 1;
				}
				while (k3 %v == 0)
					k3 /= v;
			}
		}
		if (k1 > 1 && !was[k1])
		{
			was[k1] = 1;
			can.push_back(k1);
		}
		if (k2 > 1 && !was[k2])
		{
			was[k2] = 1;
			can.push_back(k2);
		}
		
		if (k3 > 1 && !was[k3])
		{
			was[k3] = 1;
			can.push_back(k3);
		}
	}
	ll total_ans = (ll)1e+18;
	for (i = 0; i < can.size(); i++)
	{
		ll v = can[i];
		ll l = n+1, r = -1;
		for (j = 0; j < n; j++)
		{
			ll w = a[j];
			if (w % v != 0 && (w+1) % v != 0 && (w-1) % v != 0)
				l = min(l, j), r = max(r,j);
		}
		//cout << v << " " << l << " " << r << endl;
		if (r == -1)
		{
			ll tot = 0;
			ll ans = 0; ll sum = 0;
			for (j = 0; j < n; j++)
			{
				if (a[j] % v != 0)
					tot += y;
				if (a[j] % v != 0)
					sum += y;
				sum -= x;
				if (sum < 0)
					sum = 0;
				ans = max(ans, sum);				
			}
			tot -= ans;
			total_ans = min(total_ans, tot);
			continue;
		}
		ll sz = 0;
		for (j = 0; j < l; j++)
			b[sz++] = a[j];	
		reverse(b, b+sz);
		ll tot = (r-l+1)*x;
		ll ans = 0; ll sum = 0;
		for (j = 0; j < sz; j++)
		{
			if (b[j] % v != 0)
				tot += y;
			if (b[j] % v != 0)
				sum += y;
			sum -= x;
			ans = max(ans, sum);				
		}
		tot -= ans;
		
		sz = 0;
		for (j = r+1; j < n; j++)
			b[sz++] = a[j];
		ans = 0; sum = 0;
		for (j = 0; j < sz; j++)
		{
			if (b[j] % v != 0)
				tot += y;
			if (b[j] % v != 0)
				sum += y;
			sum -= x;
			ans = max(ans, sum);				
		}
		tot -= ans;
		total_ans = min(total_ans, tot);
	}
	cout << total_ans << endl;
	return 0;
}