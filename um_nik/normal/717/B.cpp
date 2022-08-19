#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 20000;
ll c0, c1;
ll n;
ll C[N];

bool check(ll x)
{
	ll cnt = (x / c0) + 1;
	for (int i = 0; i < N; i++)
		C[i] = i + 1;
	for (int i = 1; cnt < n && i * c1 <= x; i++)
	{
		for (int j = 0; cnt < n && j * c0 + i * c1 <= x; j++)
		{
			cnt += C[j];
			if (j > 0)
				C[j] += C[j - 1];
		}
	}
	return cnt >= n;
}

ll solve(ll x)
{
	ll cnt = (x / c0) + 1;
	ll sum = cnt * (cnt - 1) / 2 * c0;
	for (int i = 0; i < N; i++)
		C[i] = i + 1;
	for (int i = 1; i * c1 <= x; i++)
	{
		for (int j = 0; j * c0 + i * c1 <= x; j++)
		{
			cnt += C[j];
			sum += C[j] * (j * c0 + i * c1);
			if (j > 0)
				C[j] += C[j - 1];
		}
	}
	return sum - (cnt - n) * x;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%lld%lld", &n, &c0, &c1);
	if (c0 > c1) swap(c0, c1);
	n--;
	ll ans = n * (c0 + c1);
	if (n == 1 || c0 == 0)
	{
		printf("%lld\n", ans);
		return 0;
	}
	ll l = 0, r = c0 * n;
	while(r - l > 1)
	{
		ll x = (l + r) / 2;
		if (check(x))
			r = x;
		else
			l = x;
	}
	ans += solve(r);
	printf("%lld\n", ans);

	return 0;
}