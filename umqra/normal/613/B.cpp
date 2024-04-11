#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 10;

int n;
ll A;
ll costFull, costMin;
ll money;
pair<ll, ll> level[N];
ll allSum[N];
ll res[N];

int main()
{
	scanf("%d%lld", &n, &A);
	scanf("%lld%lld", &costFull, &costMin);

	scanf("%lld", &money);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &level[i].X);
		level[i].Y = i;
		res[i] = level[i].X;
	}
	sort(level, level + n);
	reverse(level, level + n);
	for (int i = n - 1; i >= 0; i--)
	{
		allSum[i] = allSum[i + 1] + level[i].X;
	}

	ll ans = 0;
	ll curMin = A + 1;
	int curCntMin = 0;
	for (int i = 0; i < n; i++)
	{
		if (curMin > level[i].X)
		{
			curCntMin = 1;
			curMin = level[i].X;
		}
		else if (curMin == level[i].X)
			curCntMin++;
		if (curMin == level[i].X)
			curCntMin++;
		if (level[i].X == A)
			ans += costFull;
	}
	ans += curMin * costMin;

	ll need = 0;
	int bestPos = 0;
	int bestMid = n;
	ll bestLevel = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			need += A - level[i - 1].X;

		ll rem = money - need;
		if (rem < 0)
			continue;
		ll power = (ll)i * costFull;

		int l = i - 1, r = n;
		while (r - l > 1)
		{
			int mid = (l + r) / 2;
			if (mid == -1)
			{
				l = mid;
				continue;
			}
			int cnt = n - mid;
			if ((ll)cnt * level[mid].X - allSum[mid] <= rem)
				r = mid;
			else
				l = mid;
		}
		ll curM = rem - ((ll)(n - r) * level[r].X - allSum[r]);
		ll minLevel = level[r].X;
		minLevel += curM / (ll)(n - r);
		minLevel = min(minLevel, A);
		if (minLevel == A)
			power += costFull * (n - r) + costMin * minLevel;
		else
			power += minLevel * costMin;

		ans = max(ans, power);
		if (ans == power)
		{
			bestPos = i;
			bestMid = r;
			bestLevel = minLevel;
		}
	}
	printf("%lld\n", ans);
	for (int i = 0; i < bestPos; i++)
		res[level[i].Y] = A;
	for (int i = bestMid; i < n; i++)
		res[level[i].Y] = bestLevel;

	for (int i = 0; i < n; i++)
		printf("%lld ", res[i]);


	return 0;
}