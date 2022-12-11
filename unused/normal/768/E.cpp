#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> grundy[63];

long long getgrundy(int n, long long flag)
{
	for (int i = n + 1; i <= 60; i++)
	{
		flag &= ~(1LL << i);
	}
	auto itr = grundy[n].emplace(flag, 0);
	if (itr.second)
	{
		set<long long> nxt;
		for (int i = 1; i <= n; i++)
		{
			if (flag & (1LL << i)) continue;
			nxt.insert(getgrundy(n - i, flag | (1LL << i)));
		}
		long long z = 0;
		for (long long e : nxt)
		{
			if (z != e)
			{
				break;
			}
			++z;
		}
		itr.first->second = z;
	}
	return itr.first->second;
}

int main()
{
	int n;
	scanf("%d", &n);
	long long grundy = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		grundy ^= getgrundy(tmp, 0);
	}
	if (grundy == 0) printf("YES\n");
	else printf("NO\n");
}