#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 60
using namespace std;
int t, n, a[maxn], ans[maxn];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + 2 * n + 1);
		for (int i = 1; i <= n; i++)
		{
			printf("%d %d ", a[i], a[2 * n - i + 1]);
		}
		printf("\n");
	}
	return 0;
}