#include <bits/stdc++.h>
using namespace std;

int d1[105], d2[105];
int c1[5], c2[5];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d1[i]); c1[d1[i] - 1]++;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &d2[i]); c2[d2[i] - 1]++;
	}

	int ans = 0;

	for (int i = 0; i < 5; i++)
	{
		if ((c1[i] + c2[i]) & 1)
		{
			printf("-1\n");
			return 0;
		}
		ans += abs((c1[i] + c2[i]) / 2 - c1[i]);
	}
	printf("%d\n", ans / 2);
}