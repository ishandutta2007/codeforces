#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

const int N = (int)2e6 + 10;
char str[N];
int cnt[N];
int z[N];

void calcZ(int n)
{
	int l = 0, r = 0;
	for (int i = 1; i < n; i++)
	{
		if (i < r)
			z[i] = min(z[i - l], r - i + 1);
		while (str[i + z[i]] == str[z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	scanf(" %s", str);
	calcZ(n);

	for (int len = 1; len <= n; len++)
	{
		int i, j;
		bool ok = true;
		for (i = len, j = 0; i < n && j < k - 1; i += len, j++)
		{
			if (z[i] < len)
			{
				ok = false;
				break;
			}
		}
		if (ok && j == k - 1)
		{
			int t = min(z[i], len);
			cnt[i - 1]++;
			cnt[i + t]--;
		}
	}
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		x += cnt[i];
		printf("%d", x == 0 ? 0 : 1);
	}

	return 0;
}