#include <bits/stdc++.h>
using namespace std;

long long mp[10000007];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	long long sum = 0;
	int top = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		mp[tmp]++;
		sum += tmp;
		top = max(top, tmp);
	}

	if (sum < k)
	{
		printf("-1");
		return 0;
	}

	sum = 0;
	int itr = top;

	while (itr)
	{
		if (top != itr && (top + 1) / 2 >= itr)
		{
			sum -= mp[top];
			if (top & 1)
			{
				mp[top / 2] += mp[top];
				mp[top / 2 + 1] += mp[top];
				
			}
			else
			{
				mp[top / 2] += mp[top] * 2;
			}
			while (mp[--top] == 0)
				;

			continue;
		}

		sum += mp[itr];

		if (sum >= k)
		{
			printf("%d", itr);
			return 0;
		}

		--itr;
	}
}