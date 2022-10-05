#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n;
long long a[Maxn], b[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	if (n == 1)
	{
		printf("1 1\n%lld\n1 1\n-1\n1 1\n1\n", -a[1]);
		return 0;
	}
	printf("%d %d\n", 1, n - 1);
	for (int i = 1; i < n; i++)
	{
		long long tmp = a[i] * (n - 1LL);
		a[i] += tmp;
		printf("%lld ", tmp);
	}
	puts("");
	printf("%d %d\n%lld\n", n, n, n - a[n]);
	a[n] = n;
	printf("%d %d\n", 1, n);
	for (int i = 1; i <= n; i++)
		printf("%lld ", -a[i]);
	return 0;
}