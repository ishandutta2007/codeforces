#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

ll n, a, d;
int m;
ll t[N];

ll cdiv(ll a, ll b)
{
	return (a + b - 1) / b;
}

void solve()
{
	scanf("%lld%d%lld%lld", &n, &m, &a, &d);
	for (int i = 0; i < m; ++i)
		scanf("%lld", &t[i]);
	ll now = 1;
	ll ans = 0;

	auto skip = 1 + d / a;

	for(int i = 0; i < m; ++i)
	{
		if (t[i] < now)
			continue;
		eprintf("%d : %lld, %lld", i, ans, now);
		auto num = cdiv(now, a);
		if (num > n || num * a > t[i])
		{
			++ans;
			now = t[i] + d + 1;
			eprintf(" ME");
		}
		else
		{
			ll k;
			if (a * n < t[i])
				k = (n - num) / skip;
			else
				k = (t[i] - a * num) / (a * skip);
			ans += k + 1;
			num += k * skip;
			now = num * a + d + 1;
			--i;
		}
		eprintf("\n");
	}

	auto num = cdiv(now, a);
	if (num <= n)
	{
		ll k = (n - num) / skip;
		ans += k + 1;
	}

	printf("%lld\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}