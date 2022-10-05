#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn], mini, pos;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		mini = 0x3f3f3f3f;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
		{ 
			if (a[i] - i >= mini)
			{
				printf("Yes\n%d %d\n", pos, i);
				goto END;
			}
			if (mini > a[i] - i + 1)
			{
				mini = a[i] - i + 1;
				pos = i;
			}
		}
		reverse(a + 1, a + 1 + n);
		mini = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
		{ 
			if (a[i] - i >= mini)
			{
				printf("Yes\n%d %d\n", n + 1 - i, n + 1 - pos);
				goto END;
			}
			if (mini > a[i] - i + 1)
			{
				mini = a[i] - i + 1;
				pos = i;
			}
		}
		puts("No");
		END:;
	}
	return 0;
}