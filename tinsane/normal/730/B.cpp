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
const int N = 55;

int maxi[N], mini[N];

bool is_less(int a, int b)
{
	printf("? %d %d\n", a + 1, b + 1);
	fflush(stdout);
	char buf[2];
	scanf("%s", buf);
	return buf[0] == '<';
}

void solve()
{
	int n;
	scanf("%d", &n);

	int g = n / 2;
	for (int i = 0; i < g; i++)
	{
		if (is_less(2 * i, 2 * i + 1))
		{
			mini[i] = 2 * i;
			maxi[i] = 2 * i + 1;
		}
		else
		{
			mini[i] = 2 * i + 1;
			maxi[i] = 2 * i;
		}
	}
	if (n % 2 == 1)
	{
		mini[g] = n - 1;
		maxi[g] = n - 1;
		g++;
	}

	int min_id = mini[0];
	int max_id = maxi[0];
	for (int i = 1; i < g; i++)
	{
		if (is_less(mini[i], min_id))
			min_id = mini[i];
		if (is_less(max_id, maxi[i]))
			max_id = maxi[i];
	}

	printf("! %d %d\n", min_id + 1, max_id + 1);
	fflush(stdout);
}

int main()
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}