#include <bits/stdc++.h>
using namespace std;

int n, ans;
int main()
{
	scanf("%d", &n);
	int L = n, R = n * 2000;
	while (L + 1 <= R)
	{
		int mid = (L + R) >> 1, x;
		printf("? %d\n", mid);
		fflush(stdout);
		scanf("%d", &x);
		if (x != 1) L = mid + 1;
		else R = mid;
	}
	ans = L;
	for (int i = 2; i <= n; i++)
	{
		int x;
		printf("? %d\n", (L - 1) / i);
		fflush(stdout);
		scanf("%d", &x);
		if (x == i) ans = min(ans, (L - 1) / i * i);
	}
	printf("! %d", ans);
	return 0;
}