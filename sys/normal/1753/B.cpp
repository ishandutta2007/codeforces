#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, x, Left, cnt[Maxn];
int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		int y;
		scanf("%d", &y);
		cnt[y]++;
	}
	for (int i = 1; i <= x; i++)
	{
		if (Left % i)
			return puts("No"), 0;
		Left = Left / i + cnt[i];
	}
	printf("Yes");
	return 0;
}