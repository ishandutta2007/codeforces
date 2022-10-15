#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long q, n, k, a[200001];
int main()
{
	scanf("%lld", &q);
	while (q--)
	{
		long long sum = 0;
		scanf("%lld%lld", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		if ((!(k % 2) && (sum & 1)) || ((k & 1) && !(sum % 2)))
		{
			printf("NO\n");
			continue;
		}
		else
		{
			long long tmp = 0, tot = 0;
			for (int i = 1; i <= n; i++)
			{
				tmp += a[i];
				if (tmp & 1)
				{
					tot++;
					tmp = 0;
				}
			}
			if (tot < k)
			{
				printf("NO\n");
				continue;
			}
			else
			{
				tmp = tot = 0;
				printf("YES\n");
				for (int i = 1; i <= n; i++)
				{
					if (tot == k - 1)
					{
						printf("%lld\n", n);
						break;
					}
					tmp += a[i];
					if (tmp & 1)
					{
						printf("%d ", i);
						tot++;
						tmp = 0;
					}
				}
			}
		}
	}
	return 0;
}