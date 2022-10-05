#include <bits/stdc++.h>
using namespace std;

int T, n, a;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		bool flag = false;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			if (!a) ans += flag, flag = false;
			else flag = true;
		}
		ans += flag;
		printf("%d\n", min(2, ans)); 
	}
	return 0;
}