#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, a, b, c, d;
ll l, r;

void solve(ll x)
{
	l = max(l, 1 - x);
	r = min(r, n - x);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
	l = 1;
	r = n;
	solve(b - c);
	solve(a - d);
	solve(a + b - c - d);
	ll ans = n * max(0LL, r - l + 1);
	printf("%lld\n", ans);

	return 0;
}