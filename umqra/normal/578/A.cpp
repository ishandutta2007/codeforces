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
			
const double INF = 1e18;

int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);

	double ans = INF;
	if (a - b > 0)
	{
		ll k = (a - b) / (2 * b);
		for (ll d = k - 2; d <= k + 2; d++)
		{
			if (2 * d * b <= a - b && d >= 0)
				ans = min(ans, 1. * (a - b) / (2. * d));
		}
	}
	if (a + b > 0)
	{
		ll k = (a + b) / (2 * b);
		for (ll d = k - 2; d <= k + 2; d++)
		{
			if (2 * d * b <= a + b && d >= 0)
				ans = min(ans, 1. * (a + b) / (2. * d));
		}
	}
	if (ans > INF / 2)
		puts("-1");
	else
		printf("%.10lf", ans);
	return 0;
}