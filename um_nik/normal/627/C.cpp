#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define mp make_pair
#define X first
#define Y second

const ll INF = (ll)1e9 + 100;
const int N = 200200;
ll m, mm, d;
pll a[N];
ll distToNxt[N];
pll st[N];
int sz;
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%lld%d", &d, &m, &n);
	mm = m;
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &a[i].X, &a[i].Y);
	sort(a, a + n);
	a[n++] = mp(d, 0);
	sz = 0;
	st[sz++] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		while(sz > 0 && st[sz - 1].second >= a[i].second)
			 sz--;
		if (sz == 0) throw;
		distToNxt[i] = st[sz - 1].first - a[i].first;
		st[sz++] = a[i];
	}
	ll ans = 0;
	ll x = 0;
	for (int i = 0; i < n; i++)
	{
		ll t = a[i].first - x;
		x = a[i].first;
		if (t > m)
		{
			printf("-1\n");
			return 0;
		}
		m -= t;
		if (i == n - 1) break;
		if (m < distToNxt[i])
		{
			ll add = min(mm, distToNxt[i]) - m;
			m += add;
			ans += add * a[i].second;
		}
	}
	printf("%lld\n", ans);

	return 0;
}