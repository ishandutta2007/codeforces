#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

typedef long long ll;

const int N = 200500;
const int LIM = 1e5;
int n;
ll r;
ll l[N], t[N];

vector<ll> ans;

void solve()
{
	scanf("%d%lld", &n, &r);
	for (int i = 0; i < n; i++)
		scanf("%lld", &l[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &t[i]);

	for (int i = 0; i < n; i++)
	{
		if (l[i] > t[i])
		{
			printf("-1\n");
			return;
		}
	}

	ll timer = 0, rem = 0;
	ll ansCnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (rem > 0)
		{
			ll fast = min(rem, l[i]);
			rem -= fast;
			l[i] -= fast;
			t[i] -= fast;
			timer += fast;
		}

		if (l[i] == 0)
			continue;
		if (2 * l[i] <= t[i])
		{
			timer += 2 * l[i];
			continue;
		}

		ll m = 2 * l[i] - t[i];
		ll cnt = m / r + (m % r > 0);
		ansCnt += cnt;
		rem = cnt * r - m;

		ll cur = timer + 2 * (l[i] - m);
		for (int j = 0; j < cnt && ans.size() < LIM; j++)
		{
			ans.push_back(cur);
			cur += r;
		}

		timer += t[i];
	}

	printf("%lld\n", ansCnt);
	if (ansCnt > LIM)
		return;

	for (int i = 0; i < ansCnt; i++)
		printf("%lld ", ans[i]);
	printf("\n");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}