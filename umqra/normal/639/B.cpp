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

int main()
{
	int n, d, h;
	scanf("%d%d%d", &n, &d, &h);
	if (2 * h < d)
	{
		puts("-1");
		return 0;
	}
	if (h == d)
	{
		if (h == 1)
		{
			if (n == 2)
				printf("1 2\n");
			else
				printf("-1\n");
		}
		else
		{
			for (int i = 1; i <= h; i++)
				printf("%d %d\n", i, i + 1);
			for (int i = h + 2; i <= n; i++)
				printf("2 %d\n", i);
		}
		return 0;
	}
	for (int i = 1; i <= h; i++)
		printf("%d %d\n", i, i + 1);
	for (int i = 0; i < d - h; i++)
	{
		if (i == 0)
			printf("1 %d\n", h + 2);
		else
			printf("%d %d\n", h + i + 1, h + i + 2);
	}
	for (int i = d + 2; i <= n; i++)
	{
		printf("%d %d\n", 1, i);
	}
	return 0;
}