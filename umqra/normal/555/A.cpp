#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)1e5 + 10;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	int ans = n - 1;
	for (int i = 0; i < k; i++)
	{
		int t;
		scanf("%d", &t);
		int len = 0;
		for (int s = 0; s < t; s++)
		{
			int x;
			scanf("%d", &x);
			if (x == s + 1)
				len++;
		}
		ans -= max(len - 1, 0);
		ans += t - 1 - max(len - 1, 0);
	}
	printf("%d", ans);

	return 0;
}