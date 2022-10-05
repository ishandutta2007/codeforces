#include <bits/stdc++.h>
using namespace std;

int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int a, b, n, cnt = 0;
		scanf("%d%d%d", &a, &b, &n);
		while (max(a, b) <= n)
		{
			if (a > b) swap(a, b);
			a += b;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}