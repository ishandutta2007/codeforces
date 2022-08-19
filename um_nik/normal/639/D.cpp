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
#include <complex>
#include <valarray>
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

const int N = (int)1e6 + 10;
int n, k, B, C;
int t[N];

void simple()
{
	ll ans = (ll)1e18;

	ll sum = 0;
	for (int i = 0; i < k - 1; i++)
		sum += (t[k - 1] - t[i]) * 1LL * C;
	ans = min(ans, sum);
	for (int i = k; i < n - 1; i++)
	{
		sum -= (t[i - 1] - t[i - k]) * 1LL * C;
		sum += (k - 1) * 1LL * (t[i] - t[i - 1]);
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
}

multiset <ll> setPoints;

ll solveForRem(int r)
{
	setPoints.clear();
	ll ans = (ll)1e18;
	ll point = r;
	ll sumDist = 0;

	for (int i = 0; i < n; i++)
	{
		ll distToPoint = 0;
		int rounded = t[i];
		while ((rounded - r) % 5 != 0)
		{
			distToPoint += C;
			rounded++;
		}

		distToPoint += ((point - rounded) / 5) * 1LL * B;

		setPoints.insert(distToPoint);
		sumDist += distToPoint;

		if ((int)setPoints.size() > k)
		{
			auto value = prev(setPoints.end());
			setPoints.erase(value);
			sumDist -= *value;
		}

		if ((int)setPoints.size() == k)
		{
			ans = min(ans, sumDist - ((point - rounded) / 5) * 1LL * B * k);
		}
	}
	return ans;
}

void hard()
{
	ll ans = (ll)1e18;
	for (int rem = 0; rem < 5; rem++)
		ans = min(ans, solveForRem(rem));
	printf("%lld\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif
	scanf("%d%d%d%d", &n, &k, &B, &C);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	sort(t, t + n);
	if (5 * C <= B)
		simple();
	else
		hard();

	return 0;
}