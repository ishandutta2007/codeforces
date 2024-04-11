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

char str[10000];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	scanf(" %s", str);

	for (int i = 0; i < n; i++)
	{
		for (int d = 1; d < n; d++)
		{
			int cur = i;
			bool ok = true;
			for (int s = 0; s < 5; s++)
			{
				if (cur >= n || str[cur] == '.')
					ok = false;
				cur += d;
			}
			if (ok)
			{
				puts("yes");
				return 0;
			}
		}
	}
	puts("no");
	return 0;
}