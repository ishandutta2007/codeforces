#include "bits/stdc++.h"
using namespace std;

int dat[200005];
int freecnt;

int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		if (i + 1 == s && dat[i])
		{
			ans++;
			dat[i] = 0;
		}
		else if (i + 1 != s && dat[i] == 0)
		{
			ans++;
			dat[i] = -1;
			freecnt++;
		}
	}

	sort(dat, dat + n);
	int i;
	for (i = 0; dat[i] == -1; i++);
	int poped = 0;
	for (; i < n - poped; i++)
	{
		if (dat[i] == 0) continue;

		if (dat[i] - dat[i - 1] > 1)
		{
			if (freecnt)
			{
				dat[i - 1]++;
				freecnt--;
			}
			else
			{
				poped++; ans++;
				dat[i - 1]++;
			}
			i--;
		}
	}

	printf("%d", ans);
}