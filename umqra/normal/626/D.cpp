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
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int DIFF = 5000 * 3 + 10;
const int N = 2010;
ull dp[8][2 * DIFF + 10];

int a[N];

void setDiff(int id, int value, ull x)
{
	dp[id][value + DIFF] = x;
}

ull getDiff(int id, int value)
{
	return dp[id][value + DIFF];
}

void addDiff(int id, int value, ull x)
{
	dp[id][value + DIFF] += x;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	setDiff(0, 0, 1);

	for (int i = 0; i < n; i++)
	{
		for (int d = 1; d >= 0; d--)
		{
			for (int s = -DIFF; s <= DIFF; s++)
			{
				ull curValue = getDiff(d, s);
				if (curValue == 0)
					continue;
				if (d == 0)
					addDiff(1, s + a[i], curValue);
				else
					addDiff(2, s - a[i], curValue);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int d = 3; d >= 2; d--)
		{
			for (int s = -DIFF; s <= DIFF; s++)
			{
				ull curValue = getDiff(d, s);
				if (curValue == 0)
					continue;
				if (d == 2)
					addDiff(3, s + a[i], curValue);
				else
					addDiff(4, s - a[i], curValue);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int d = 5; d >= 4; d--)
		{
			for (int s = -DIFF; s <= DIFF; s++)
			{
				ull curValue = getDiff(d, s);
				if (curValue == 0)
					continue;
				if (d == 5)
					addDiff(6, s + a[i], curValue);
				else
					addDiff(5, s - a[i], curValue);
			}
		}
	}
	ull sum = 0;
	for (int i = 1; i < DIFF; i++)
	{
		sum += getDiff(6, i);
	}
	ull mult = n * (n - 1) / 2;
	ull total = mult * mult * mult;
	printf("%.10lf\n", 1. * sum / total);
	return 0;
}