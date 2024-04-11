#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define mp make_pair

const ll C = (ll)1e6 + 100;
const int N = 200200;
int n;
int m;
ll ans = 0;
ll curSum = 0;
ll a[N];
ll sum[N];
pll h[N];

void addLine(ll k, ll y)
{
	while(m > 0)
	{
		ll l = -C, r = C;
		ll k1 = h[m - 1].first, y1 = h[m - 1].second;
		if (k1 * l + y1 >= k * l + y)
		{
			m--;
			continue;
		}
		if (k1 * r + y1 <= k * r + y) return;
		if (m == 1) break;
		while(r - l > 1)
		{
			ll x = (l + r) / 2;
			if (k1 * x + y1 < k * x + y)
				l = x;
			else
				r = x;
		}
		if (h[m - 2].first * l + h[m - 2].second <= k1 * l + y1)
			m--;
		else
			break;
	}
	h[m++] = mp(k, y);
	return;
}

ll getVal(ll x)
{
	if (m == 1 || h[0].first * x + h[0].second <= h[1].first * x + h[1].second)
		return h[0].first * x + h[0].second;
	int l = 0, r = m - 1;
	while(r - l > 1)
	{
		int p = (l + r) / 2;
		if (h[p].first * x + h[p].second >= h[p + 1].first * x + h[p + 1].second)
			l = p;
		else
			r = p;
	}
	return h[r].first * x + h[r].second;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		curSum += a[i] * (i + 1);
		sum[i + 1] = sum[i] + a[i];
	}
	for (int i = 0; i <= n; i++)
		addLine(-i, sum[i]);
	for (int i = 0; i < n; i++)
	{
		ll val = -getVal(a[i]);
		val += sum[i] - a[i] * i;
		ans = max(ans, val);
	}
	printf("%lld\n", curSum + ans);

	return 0;
}