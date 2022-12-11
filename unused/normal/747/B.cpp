#include <bits/stdc++.h>
using namespace std;

char str[300];
int cnt[256];

int main()
{
	int n;
	scanf("%d%s", &n, str);
	if (n % 4)
	{
		printf("===");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] != '?')
		{
			if (++cnt[str[i]] > n / 4)
			{
				printf("===");
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (str[i] != '?') printf("%c", str[i]);
		else
		{
			if (cnt['A']++ < n / 4) printf("A");
			else if (cnt['G']++ < n / 4) printf("G");
			else if (cnt['C']++ < n / 4) printf("C");
			else printf("T");
		}
	}
}