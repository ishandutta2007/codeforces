/*
	Team: Dandelion
	Room: 258
*/

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
const ll INF = (ll)1e17 + 10;

int n;
ll a, b;
int arr[N];

ll ans = INF;
ll costPref[N], costSuff[N];
int r[N];

void solveForD(int x)
{
	for (int i = 0; i < n; i++)
	{
		r[i] = (arr[i] % x);
		if (r[i] == x - 1)
			r[i] = 1;
	}

	costPref[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (r[i] == 0)
			costPref[i + 1] = costPref[i];
		else if (r[i] == 1)
			costPref[i + 1] = costPref[i] + b;
		else
			costPref[i + 1] = INF;
	}

	costSuff[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (r[i] == 0)
			costSuff[i] = costSuff[i + 1];
		else if (r[i] == 1)
			costSuff[i] = costSuff[i + 1] + b;
		else
			costSuff[i] = INF;
	}
	ans = min(ans, costPref[n]);

	ll minCostLeft = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		minCostLeft = min(costSuff[i], minCostLeft + a);
		ans = min(ans, minCostLeft + costPref[i]);
	}
}

int main()
{
	scanf("%d%lld%lld", &n, &a, &b);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	if (n == 1)
	{
		puts("0");
		return 0;
	}

	for (int d = -1; d <= 1; d++)
	{
		for (int pos = 0; pos < n; pos += n - 1)
		{
			int value = arr[pos] + d;
			for (int x = 2; x * x <= value; x++)
			{
				if (value % x == 0)
				{
					while (value % x == 0)
						value /= x;
					solveForD(x);
				}
			}
			if (value != 1)
				solveForD(value);
		}
	}
	printf("%lld\n", ans);

	return 0;
}