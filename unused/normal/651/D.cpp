#include <stdio.h>
#include <algorithm>

long long L[500005];
long long R[500005];
char dat[500005];

int main()
{
	int n, a, b, T;
	scanf("%d%d%d%d%s", &n, &a, &b, &T, dat);

	if (dat[0] == 'w')
	{
		T -= b;
	}

	T -= 1;

	if (T < 0)
	{
		printf("0\n");
		return 0;
	}
	else if (T == 0)
	{
		printf("1\n");
		return 0;
	}

	int ans = 1;

	char *p = dat + n;
	for (int i = 1; i <= n - 1; i++)
	{
		--p;
		L[i] = L[i - 1];
		L[i] += a;
		if (*p == 'w') L[i] += b;
		L[i] += 1;
	}

	p = dat;
	for (int i = 1; i <= n - 1; i++)
	{
		++p;
		R[i] = R[i - 1];
		R[i] += a;
		if (*p == 'w') R[i] += b;
		R[i] += 1;
	}

	int left = n, right = 0;

	while (--left >= 0)
	{
		long long remain = T - L[left] - (long long)left * a;
		if (remain < 0) continue;
		while (R[right] <= remain && right <= n - 1) right++;
		ans = std::max(ans, left + right);
	}

	left = 0, right = n;

	while (--right >= 0)
	{
		long long remain = T - R[right] - (long long)right * a;
		if (remain < 0) continue;
		while (L[left] <= remain && left <= n - 1) left++;
		ans = std::max(ans, left + right);
	}

	printf("%d\n", std::min(ans, n));
}