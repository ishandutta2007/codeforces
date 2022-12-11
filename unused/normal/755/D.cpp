#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (n < k * 2) k = n - k;

	long long now = 1;
	long long z = 0;
	for (int i = 0; i < n; i++)
	{
		now += (z - 1) / n + (z + k - 1) / n + 1;
		z += k;
		printf("%lld ", now);
	}
}