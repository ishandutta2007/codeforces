#include <bits/stdc++.h>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int sum = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			sum = (sum + x) % n;
		}
		printf("%d\n", (bool) sum);
	}
	return 0;
}