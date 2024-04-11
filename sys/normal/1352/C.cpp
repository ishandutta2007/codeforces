#include <bits/stdc++.h>
using namespace std;

int T, n, k;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		if (k % (n - 1) == 0)
			printf("%d\n", k / (n - 1) * n - 1);
		else printf("%d\n", k / (n - 1) * n + k % (n - 1));
	}
	return 0;
}