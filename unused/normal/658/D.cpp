#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a[300005];

int bitsum[300000];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	int lastidx = -1;

	for (int i = 0; i <= n; i++)
	{
		int bit = (a[i] < 0) ? -1 : 1;
		int target = abs(a[i]);
		for (int j = 0; j < 32; j++)
		{
			if (target & (1 << j))
			{
				bitsum[i + j] += bit;
				lastidx = max(lastidx, i + j);;
			}
		}
	}

	for (int i = 0; i <= lastidx; i++)
	{
		if (bitsum[i] < -1)
		{
			int carry = (-bitsum[i]) / 2;
			bitsum[i + 1] -= carry;
			bitsum[i] += carry * 2;
			lastidx = max(lastidx, i + 1);
		}
		else if (bitsum[i] > 1)
		{
			int carry = bitsum[i] / 2;
			bitsum[i + 1] += carry;
			bitsum[i] -= carry * 2;
			lastidx = max(lastidx, i + 1);
		}
	}

	while (bitsum[lastidx] == 0) --lastidx;

	int sign = bitsum[lastidx];
	if (sign == -1)
	{
		for (int i = 0; i <= lastidx; i++) bitsum[i] *= -1;
	}

	int lastone = -1;
	int firstone = -1;

	for (int i = 0; i <= lastidx; i++)
	{
		if (bitsum[i] < 0)
		{
			bitsum[i] += 2;
			bitsum[i + 1] -= 1;
		}
		if (bitsum[i])
		{
			lastone = i;
			if (firstone == -1) firstone = i;
		}
	}

	long long dep = 0;
	for (int i = lastone; i >= firstone; i--)
	{
		dep = dep * 2 + bitsum[i];
		if (dep > 2ll * k) break;
	}

	int ans = 0;
	for (int i = firstone; i >= 0; i--)
	{
		if (dep > 2ll * k) break;
		if (i <= n && abs(a[i] - dep * sign) <= k && (i != n || a[i] != dep * sign)) ans++;
		dep *= 2;
	}
	printf("%d\n", ans);
}