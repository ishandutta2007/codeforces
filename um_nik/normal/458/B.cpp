#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e18;
ll n, m;
ll a[100100], b[100100];
ll ans = INF;

ll mul(ll x, ll y)
{
	if (2LL * INF / x < y)
		return INF + 1LL;
	return x * y;
}

int main()
{
	scanf("%I64d%I64d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%I64d", &b[i]);
	sort(a, a + n);
	sort(b, b + m);
	ll sumb = 0;
	ll suma = 0;
	for (int i = 0; i < m; i++)
		sumb += b[i];
	for (ll i = 0; i < n; i++)
	{
		ll tmp = suma + mul((n - i), sumb);
		ans = min(ans, tmp);
		suma += a[i];
	}
	sumb = 0;
	for (ll i = 0; i < m; i++)
	{
		ll tmp = sumb + mul((m - i), suma);
		ans = min(ans, tmp);
		sumb += b[i];
	}
	printf("%I64d\n", ans);
//	cin >> n;
	return 0;
}