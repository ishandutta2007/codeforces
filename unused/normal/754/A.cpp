#include <bits/stdc++.h>
using namespace std;

int dat[105];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &dat[i]);

	int sum = 0;
	bool allzero = true;
	for (int i = 0; i < n; i++)
	{
		if (dat[i])
		{
			allzero = false;
		}
		sum += dat[i];
	}

	if (allzero) printf("NO\n");
	else
	{
		printf("YES\n");
		if (sum == 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (dat[i])
				{
					printf("2\n1 %d\n%d %d\n", i + 1, i + 2, n);
					break;
				}
			}
		}
		else
		{
			printf("%d\n1 %d\n", 1, n);
		}
	}
}