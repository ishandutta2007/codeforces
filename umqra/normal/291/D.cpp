#include <iostream>
#include <cstdio>
using namespace std;

const int N = (int)1e5;

int cur[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++)
		cur[i] = 1;
	cur[n] = 0;

	if (n == 1)
	{
		for (int i = 0; i < k; i++)
			printf("1\n");
		return 0;
	}

	int lastOK = n - 1;
	int step = 1;
	int curMax = 1;
	for (int i = 0; i < k; i++)
	{                      
		for (int s = 1; s <= n; s++)
		{
			int t = n - s;
			if (t - cur[s] > curMax)
			{
				printf("%d ", lastOK);
				cur[s] += curMax;
			}
			else
			{
				printf("%d ", n - (t - cur[s]));
				cur[s] = n - s;
			}
		}	
		puts("");
		curMax *= 2;
		lastOK -= step;
		step *= 2;
	}

	return 0;
}