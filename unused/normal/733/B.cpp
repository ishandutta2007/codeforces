#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> dat[100005];

int main()
{
	int n;
	scanf("%d", &n);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &dat[i].first, &dat[i].second);
		sum1 += dat[i].first;
		sum2 += dat[i].second;
	}

	int ans1 = -1, ans2 = abs(sum1 - sum2);
	for (int i = 0; i < n; i++)
	{
		sum1 += dat[i].second; sum2 += dat[i].first;
		sum1 -= dat[i].first; sum2 -= dat[i].second;

		if (abs(sum1 - sum2) > ans2)
		{
			ans2 = abs(sum1 - sum2);
			ans1 = i;
		}

		sum1 -= dat[i].second; sum2 -= dat[i].first;
		sum1 += dat[i].first; sum2 += dat[i].second;
	}

	printf("%d", ans1 + 1);
}