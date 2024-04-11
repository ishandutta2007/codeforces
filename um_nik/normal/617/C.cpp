#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define mp make_pair

const int N = 2020;
int n;
pll A, B;
pll a[N];
ll ans;

ll sqr(ll x)
{
	return x * x;
}
ll getDist(pll a, pll b)
{
	return sqr(a.first - b.first) + sqr(a.second - b.second);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld%lld%lld", &n, &A.first, &A.second, &B.first, &B.second);
	for (int i = 0; i < n; i++)
	{
		pll C;
		scanf("%lld%lld", &C.first, &C.second);
		a[i] = mp(getDist(A, C), getDist(B, C));
	}
	sort(a, a + n);
	ans = (ll)1e18;
	for (int i = 0; i <= n; i++)
	{
		ll val = 0;
		for (int j = i; j < n; j++)
			val = max(val, a[j].second);
		ans = min(ans, val + (i == 0 ? 0 : a[i - 1].first));
	}
	printf("%lld\n", ans);

	return 0;
}