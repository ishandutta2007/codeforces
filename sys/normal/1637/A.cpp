#include <bits/stdc++.h>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		bool flag = false;
		scanf("%d", &n);
		int las = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (las > x) flag = true;
			las = x;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}