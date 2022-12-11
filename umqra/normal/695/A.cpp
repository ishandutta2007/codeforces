#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>

#include <functional>
#include <complex>
#include <valarray>
#include <cassert>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int N = 20;
int n, k;
double p[N];
double dp[(1 << N) + 7];
double ans[N];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lf", &p[i]);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (p[i] > 0.000001)
			cnt++;
	if (cnt <= k)
	{
		for (int i = 0; i < n; i++)
			if (p[i] > 0.000001)
				printf("1 ");
			else
				printf("0 ");
		printf("\n");
		return 0;
	}
	dp[0] = 1;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1)
				sum += p[i];
		if (sum >= 0.99999) continue;
		for (int i = 0; i < n; i++)
		{
			if ((mask >> i) & 1) continue;
			dp[mask | (1 << i)] += dp[mask] * p[i] / (1 - sum);
		}
	}
	for (int mask = 0; mask < (1 << n); mask++)
	{
		cnt = 0;
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1)
				cnt++;
		if (cnt != k) continue;
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1)
				ans[i] += dp[mask];
	}
	for (int i = 0; i < n; i++)
		printf("%.13lf ", ans[i]);
	printf("\n");

	return 0;
}