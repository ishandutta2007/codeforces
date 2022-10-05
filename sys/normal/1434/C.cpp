#include <bits/stdc++.h>
using namespace std;

int T, a, b, c, d;
long long work(long long x)
{
	if (x < 0) return -0x3f3f3f3f3f3f3f3fLL;
	long long s2, t2 = (x - 1) * d - c;
	s2 = t2 % d;
	s2 = max(s2, 0LL), t2 = max(t2, 0LL);
	return x * a - ((x - 1) * d) * x / 2 * b + (s2 + t2) * ((t2 - s2) / d + 1LL) / 2 * b;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (work(3e6) > work(3e6 - 1))
		{
			puts("-1");
			continue;
		}
		int lt = 0, rt = 3e6;
		while (lt + 1 <= rt)
		{
			int mid = (lt + rt) >> 1;
			if (work(mid) < work(mid + 1)) lt = mid + 1;
			else rt = mid;
		}
		printf("%lld\n", work(lt));
	}
	return 0;
}