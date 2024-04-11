#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int T, n, k, cnt;
char a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		scanf("%d%d%s", &n, &k, a + 1);
		for (int i = 1; i <= k; i++)
		{
			int val = 0;
			for (int j = i; j <= n; j += k)
				if (a[j] != '?') val = a[j];
			if (val) 
				for (int j = i; j <= n; j += k)
				{
					if (val && a[j] == '?')
						a[j] = val;
					if (val && a[j] != val)
					{
						puts("NO");
						goto END;
					}
				}
		}
		for (int i = 1; i <= k; i++)
		{
			if (a[i] == '0') cnt++;
			if (a[i] == '1') cnt--;
		}
		for (int i = 1; i <= k; i++)
		{
			if (a[i] == '?' && cnt >= 0)
			{
				for (int j = i; j <= n; j += k)
					a[j] = '1';
				cnt--;
			}
			if (a[i] == '?' && cnt < 0)
			{
				for (int j = i; j <= n; j += k)
					a[j] = '0';
				cnt++;
			}
		}
		if (cnt)
		{
			puts("NO");
			goto END;
		}
		for (int i = k + 1; i <= n; i++)
			if (a[i] != a[i - k])
			{
				puts("NO");
				goto END;
			}
		puts("YES");
		END:;
	}
	return 0;
}