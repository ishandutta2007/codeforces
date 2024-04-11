#include <bits/stdc++.h>
using namespace std;

int dat[100005];
map<int, vector<int>> buckets;
int c1[1024], c2[1024];

int main()
{
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	int hif = 1;
	while (hif <= x) hif <<= 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		buckets[dat[i] / hif].push_back(dat[i] % hif);
	}

	auto &&v1 = buckets.begin()->second;
	for (int e : v1) c1[e]++;
	int *p1 = c1, *p2 = c2;

	for (int i = 0; i < k; i++)
	{
		memset(p2, 0, sizeof(int) * 1024);
		int odd = 1;
		for (int j = 0; j < 1024; j++)
		{
			p2[j ^ x] += p1[j] / 2;
			p2[j] += p1[j] / 2;
			if (p1[j] % 2)
			{
				if (odd) p2[j ^ x] += 1;
				else p2[j] += 1;
			}
			odd ^= p1[j] % 2;
		}

		swap(p1, p2);
	}
	int maxima, minima;

	for (int j = 0; j < 1024; j++)
	{
		if (p1[j])
		{
			minima = buckets.begin()->first * hif + j;
			break;
		}
	}

	if (buckets.size() == 1)
	{
		for (int j = 1023; j >= 0; j--)
		{
			if (p1[j])
			{
				maxima = buckets.begin()->first * hif + j;
				break;
			}
		}

		printf("%d %d\n", maxima, minima);
		return 0;
	}

	auto &&v2 = buckets.rbegin()->second;
	memset(c1, 0, sizeof(c1));
	for (int e : v2) c1[e]++;
	p1 = c1, p2 = c2;
	int isodd = (n - v2.size()) % 2 == 0;

	for (int i = 0; i < k; i++)
	{
		memset(p2, 0, sizeof(int) * 1024);
		int odd = isodd;
		for (int j = 0; j < 1024; j++)
		{
			p2[j ^ x] += p1[j] / 2;
			p2[j] += p1[j] / 2;
			if (p1[j] % 2)
			{
				if (odd) p2[j ^ x] += 1;
				else p2[j] += 1;
			}
			odd ^= p1[j] % 2;
		}

		swap(p1, p2);
	}

	for (int j = 1023; j >= 0; j--)
	{
		if (p1[j])
		{
			maxima = buckets.rbegin()->first * hif + j;
			break;
		}
	}

	printf("%d %d\n", maxima, minima);
}