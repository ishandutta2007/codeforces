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

const int N = (int)2e5 + 10;
const int INF = (int)1e9 + 10;
const int R2 = 1899;
int delta[N], d[N];
int n;

int getDiv(int x)
{
	if (x <= R2)
		return 2;
	return 1;
}

bool check(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (getDiv(x) != d[i - 1])
			return false;
		x += delta[i];
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &delta[i], &d[i - 1]);
	}
	int maxRating = INF;
	if (d[0] == 2)
		maxRating = R2;
	for (int i = 1; i < n; i++)
	{
		sum += delta[i];
		if (d[i] == 2)
			maxRating = min(maxRating, R2 - sum);
	}
	if (check(maxRating))
	{
		if (maxRating == INF)
			puts("Infinity");
		else
			printf("%d\n", maxRating + sum + delta[n]);
	}
	else
		puts("Impossible");
	return 0;
}