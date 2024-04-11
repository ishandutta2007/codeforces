#include <bits/stdc++.h>
using namespace std;
 
long long u, v, p, now;
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
struct Rand
{
	int val[105];
	bool operator < (const Rand &tmp) const
	{
		for (int i = 1; i <= 100; i++)
			if (val[i] != tmp.val[i]) return val[i] < tmp.val[i];
		return false;
	}
} tmp;
map <int, Rand> Ma;
int main()
{
	scanf("%lld%lld%lld", &u, &v, &p);
	for (int i = 1; i <= 100; i++)
		tmp.val[i] = rand() % 3 + 1;
	if (p <= 200)
	{
		int ct = 0;
		while (u != v) ct++, u = (u + 1) % p;
		printf("%d\n", ct);
		for (int i = 1; i <= ct; i++)
			printf("1 ");
		return 0;
	}
	for (int i = 1; i <= 1e5; i++)
	{
		long long now = u;
		random_shuffle(tmp.val + 1, tmp.val + 1 + 100);
		for (int j = 1; j <= 100; j++)
			if (tmp.val[j] == 1) now = (now + 1) % p;
			else if (tmp.val[j] == 2) now = (now - 1 + p) % p;
			else now = fast_pow(now, p - 2);
		Ma[now] = tmp;
	}
	for (int i = 1; i <= 1e5; i++)
	{
		long long now = v;
		random_shuffle(tmp.val + 1, tmp.val + 1 + 100);
		for (int j = 1; j <= 100; j++)
			if (tmp.val[j] == 1) now = (now - 1 + p) % p;
			else if (tmp.val[j] == 2) now = (now + 1) % p;
			else now = fast_pow(now, p - 2);
		if (Ma.find(now) != Ma.end())
		{
			printf("200\n");
			Rand Front = Ma[now];
			for (int j = 1; j <= 100; j++)
				printf("%d ", Front.val[j]);
			for (int j = 100; j >= 1; j--)
				printf("%d ", tmp.val[j]);
			return 0;
		}
	}
	return 0;
}