#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 105
using namespace std;
int T, n, a[maxn], t[maxn];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(t, 0, sizeof(t));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			t[a[i]]++;
		}
		int ans = 0;
		for (int i = 1; i <= 100; i++) ans = max(ans, t[i]);
		printf("%d\n", ans);
	}
	return 0;
}