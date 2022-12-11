#include <iostream>
#include <cstdio>
#include <algorithm>    
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
ll h[N], p[N];

ll abs64(ll a)
{
	if (a < 0)
		return -a;
	return a;
}

ll min64(ll a, ll b)
{
	if (a < b)
		return a;
	return b;
}

ll getDist(ll a, ll b, ll c)
{              
	ll fD = (a - b) + (c - b);
	ll sD = abs64(a - c) + (c - b);
	return min64(fD, sD);
}

bool check(int n, int k, ll tme)
{                       
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		if (cur == k)
			break;
		if (p[cur] < h[i])
		{
			if (h[i] - p[cur] > tme)
				return false;               
			ll st = p[cur];
			while (cur < k && getDist(h[i], st, p[cur]) <= tme)
			{
				cur++;
			}
		}
		else	
		{
			ll z = tme;
			ll last = h[i];
			while (cur < k && p[cur] - last <= z)
			{
				z -= (p[cur] - last);
				last = p[cur];
				cur++;
			}
		}
	}           
	if (cur == k)
		return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &h[i]);
	for (int s = 0; s < k; s++)
		scanf("%lld", &p[s]);

	ll l = -1, r = (ll)1e11;
	while (r - l > 1)
	{
		ll m = (l + r) / 2;
		if (check(n, k, m))
			r = m;
		else
			l = m;
	}
	cout << r;

	return 0;
}