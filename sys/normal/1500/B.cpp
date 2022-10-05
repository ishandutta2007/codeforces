#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, m, a[Maxn], b[Maxn], cnt[Maxn], pos[Maxn];
long long k, l;
long long lcm(int x, int y)
{
	return x * (long long) y / __gcd(x, y);
}
long long calc(long long x)
{
	long long ans = 0, ct = x / l;
	int p = 0;
	do
	{
		ans += ct * cnt[p];
		(p += m) %= n;
		x -= ct * m;
	}
	while (p);
	p = 0;
	while (true)
	{
		if (x < m)
		{
			for (int j = p, c = 0; x; j = (j + 1) % n, c++)
			{
				x--;
				if (b[c] == a[j]) ans++;
			}
			return ans;
		}
		ans += cnt[p];
		(p += m) %= n;
		x -= m;
	}
}
int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	l = lcm(n, m);
	if (n >= m)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);
	}
	else
	{
		swap(n, m);
		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
	}
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < m; i++)
		pos[b[i]] = i;
	for (int i = 0; i < n; i++)
	{
		if (pos[a[i]] == -1) continue;
		int d = i - pos[a[i]];
		if (d < 0) d += n;
		cnt[d]++;
	}
	long long lt = 0, rt = 1e18;
	while (lt + 1 <= rt)
	{
		long long mid = (lt + rt) >> 1;
		if (mid - calc(mid) >= k) rt = mid;
		else lt = mid + 1;
	}
	printf("%lld", lt);
	return 0;
}