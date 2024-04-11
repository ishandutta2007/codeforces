#include <bits/stdc++.h>
using namespace std;

int T, n, k1, k2, w, b;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d%d", &n, &k1, &k2, &w, &b);
		if (k1 / 2 + k2 / 2 + ((k1 & 1) && (k2 & 1)) >= w && (n - k1) / 2 + (n - k2) / 2 + (((n - k1) & 1) && ((n - k2) & 1)) >= b)
			puts("Yes");
		else puts("No");
	}
	return 0;
}