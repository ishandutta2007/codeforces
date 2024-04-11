#include <bits/stdc++.h>
using namespace std;
int n;
int a[100020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	printf("%d\n", (n - 1) / 2);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d ", a[n - 1 - i / 2]);
		}
		else
		{
			printf("%d ", a[i / 2]);
		}
	}
	printf("\n");
	return 0;
}