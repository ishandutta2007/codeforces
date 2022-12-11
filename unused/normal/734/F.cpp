#include "bits/stdc++.h"
using namespace std;

int b[200005], c[200005];
int a[200005];
int bitcnt[30];

int main()
{
	mt19937 mt{ random_device{}() };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);

	long long gt = 0;
	for (int i = 0; i < n; i++) gt += b[i] + c[i];
	if (gt % (2 * n))
	{
		printf("-1");
		return 0;
	}

	gt /= 2 * n;

	for (int i = 0; i < n; i++)
	{
		long long na = b[i] + c[i] - gt;
		if (na % n || na < 0)
		{
			printf("-1");
			return 0;
		}
		a[i] = na / n;
		for (int j = 0; j < 30; j++)
		{
			if (a[i] & (1 << j)) bitcnt[j]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		long long s1 = 0, s2 = 0;
		for (int j = 0; j < 30; j++)
		{
			if (a[i] & (1 << j))
			{
				s1 += (1 << j) * bitcnt[j];
				s2 += (1 << j) * n;
			}
			else
			{
				s2 += (1 << j) * bitcnt[j];
			}
		}

		if (s1 != b[i] || s2 != c[i])
		{
			printf("-1");
			return 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}