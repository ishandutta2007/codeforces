#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define mp make_pair

const int N = 200200;
int n, m;
ll k;
ll x;
ll s;
ll ans = (ll)5e18;
pll a[N], b[N];

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%lld%d%d", &k, &n, &m);
	scanf("%lld%lld", &x, &s);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i].second);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i].first);
	for (int i = 0; i < m; i++)
		scanf("%lld", &b[i].second);
	for (int i = 0; i < m; i++)
		scanf("%lld", &b[i].first);
	sort(a, a + n);
	sort(b, b + m);
	int nn = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i].second >= a[nn - 1].second) continue;
//		if (a[i].first == a[nn - 1].first) nn--;
		a[nn++] = a[i];
	}
	n = nn;
	nn = 1;
	for (int i = 1; i < m; i++)
	{
		if (b[i].second <= b[nn - 1].second) continue;
		if (b[i].first == b[nn - 1].first) nn--;
		b[nn++] = b[i];
	}
	m = nn;

	ans = k * x;
	int it = n - 1;
	while(it >= 0 && a[it].first > s) it--;
	if (it >= 0)
		ans = min(ans, k * a[it].second);
	for (int i = 0; i < m; i++)
	{
		if (b[i].first > s) break;
		while(it >= 0 && a[it].first + b[i].first > s) it--;
		ans = min(ans, (k - b[i].second) * (it >= 0 ? a[it].second : x));
	}
	printf("%lld\n", ans);

	return 0;
}