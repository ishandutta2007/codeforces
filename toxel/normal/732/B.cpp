#include<bits/stdc++.h>
const int N = 600;
int main()
{
	int n, k, a[N], cnt = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (n == 1)
		return printf("0\n%d", a[0]), 0;
	for (int i = 1; i < n; i++)
		if (a[i - 1] + a[i] < k)
		{
			cnt += k - a[i - 1] - a[i];
			a[i] += k - a[i - 1] - a[i];
		}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}