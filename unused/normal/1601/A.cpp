#include <stdio.h>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int dat[200005];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int bitcount[32] = {};

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &dat[i]);
			for (int j = 0; j <= 30; j++)
			{
				if (dat[i] & (1 << j))
				{
					bitcount[j]++;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i <= 30; i++)
		{
			ans = gcd(ans, bitcount[i]);
		}

		for (int k = 1; k <= n; k++)
		{
			if (ans % k == 0)
			{
				printf("%d ", k);
			}
		}
		printf("\n");
	}
}