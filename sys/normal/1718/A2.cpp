#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, a[Maxn], f[Maxn];
map <int, int> Ma;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int x = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		Ma.clear();
		Ma[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			f[i] = 0;
			x ^= a[i];
			f[i] = max(f[i - 1], f[i]);
			if (Ma.find(x) == Ma.end()) Ma[x] = -0x3f3f3f3f;
			f[i] = max(f[i], Ma[x] + 1);
			Ma[x] = max(Ma[x], f[i]);
		}
		printf("%d\n", n - f[n]);
	}
	return 0;
}
// f_{j-1} + 1 -> f_i ([j, i] = 0)