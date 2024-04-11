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

const int INF = (int)1e9 + 10;
const int N = (int)1e6 + 10;
int s[N], g[N];
int bound[N];

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &s[i], &g[i]);
		bound[i] = s[i] + g[i];
	}
	int value = INF;
	for (int i = 0; i < n; i++)
	{
		bound[i] = min(bound[i], value);
		value = min(value, s[i] + g[i]) + 1;
	}
	value = INF;
	for (int i = n - 1; i >= 0; i--)
	{
		bound[i] = min(bound[i], value);
		value = min(value, s[i] + g[i]) + 1;
	}

	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += bound[i] - s[i];
		if (bound[i] < s[i])
		{
			puts("-1");
			return;
		}
	}
	cout << sum << endl;
	for (int i = 0; i < n; i++)
		printf("%d ", bound[i]);
	puts("");
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