#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int t, n, h, g, a[3000001], b[3000001], pos[3000001], dep[3000001];
vector<int> ans;
bool del(int x)
{
	int now = x;
	while (a[now])
	{
		now = a[now << 1] < a[now << 1 | 1] ? now << 1 | 1 : now << 1;
	}
	now >>= 1;
	if (dep[now] == g)
	{
		return 0;
	}
	while (now)
	{
		pos[a[now]] = pos[a[now >> 1]];
		now >>= 1;
	}
	while (a[x])
	{
		if (!a[x << 1] && !a[x << 1 | 1])
		{
			a[x] = 0;
		}
		else
		{
			if (a[x << 1] < a[x << 1 | 1])
			{
				a[x] = a[x << 1 | 1];
				x = x << 1 | 1;
			}
			else
			{
				a[x] = a[x << 1];
				x <<= 1;
			}
		}
	}
	return 1;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &h, &g);
		n = (1 << h) - 1;
		ans.clear();
		dep[1] = 1;
		long long sum = 0, left = n, t = n;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			b[i] = a[i];
			pos[a[i]] = i;
			dep[i] = dep[i >> 1] + 1;
		}
		sort(b + 1, b + n + 1);
		while (left >= (1 << g))
		{
			int tmp = pos[b[t]];
			if (!del(tmp))
			{
				t--;
			}
			else
			{
				ans.push_back(tmp);
				sum -= b[t--];
				left--;
			}
		}
		printf("%lld\n", sum);
		for (auto i : ans)
		{
			printf("%d ", i);
		}
		printf("\n");
		for (int i = 1; i <= n; i++)
		{
			a[i] = 0;
		}
	}
	return 0;
}