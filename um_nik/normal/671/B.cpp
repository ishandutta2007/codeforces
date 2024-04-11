#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = (ll)3e9;
const int N = 500500;
int n;
ll k;
ll a[N];

ll getLeft()
{
	ll l = -INF, r = INF;
	while(r - l > 1)
	{
		ll m = (l + r) / 2;
		ll s = 0;
		for (int i = 0; i < n; i++)
			s += max(0LL, m - a[i]);
		if (s <= k)
			l = m;
		else
			r = m;
	}
	return l;
}
ll getRight()
{
	ll l = -INF, r = INF;
	while(r - l > 1)
	{
		ll m = (l + r) / 2;
		ll s = 0;
		for (int i = 0; i < n; i++)
			s += max(0LL, a[i] - m);
		if (s <= k)
			r = m;
		else
			l = m;
	}
	return r;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll l = getLeft(), r = getRight();
	if (l < r)
		printf("%lld\n", r - l);
	else
	{
		ll s = 0;
		for (int i = 0; i < n; i++)
			s += a[i];
		if (s % n == 0)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}