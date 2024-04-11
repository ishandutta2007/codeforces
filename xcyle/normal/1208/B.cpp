#include <iostream>
#include <cstdio>
#define maxn 2005
using namespace std;
int T, a[maxn], n, pre[maxn], suf[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = n, r = 1;
	for (int i = 1; i <= n; i++)
	{
		pre[i] = n + 1;
		for (int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			if(a[i] == a[j])
			{
				pre[i] = j;
				l = min(l, max(i, j) - 1);
				break;
			}
		}
		suf[i] = 1;
		for (int j = n; j >= 1; j--)
		{
			if(i == j) continue;
			if(a[i] == a[j])
			{
				suf[i] = j;
				r = max(r, min(i, j) + 1);
				break;
			}
		}
	}
	int ans = min(n - l, r - 1);
	for (int i = 1; i <= l; i++)
	{
		r = max(r, suf[i] + 1);
//		printf("%d %d\n", i, r);
		ans = min(ans, r - i - 1);
	}
	printf("%d\n", max(0, ans));
	return 0;
}