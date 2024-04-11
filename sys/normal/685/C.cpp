#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n;
long long x[Maxn], y[Maxn], z[Maxn], X, Y, Z, l[5], r[5], tmp_l[5], tmp_r[5];
void get_max(long long &now, long long val)
{
	now = max(now, val);
}
void get_min(long long &now, long long val)
{
	now = min(now, val);
}
bool check(long long now)
{
	for (int i = 1; i <= 4; i++)
		l[i] = -9e18, r[i] = 9e18;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 4; j++)
		{
			long long tmp = ((j == 2) ? -1 : 1) * x[i] + ((j == 3) ? -1 : 1) * y[i] + ((j == 4) ? -1 : 1) * z[i];
			get_min(r[j], tmp + now);
			get_max(l[j], tmp - now);
		}
	for (int i = 1; i <= 4; i++)
		if (l[i] > r[i]) return false;
	for (int i = 0; i <= 1; i++)
	{
		tmp_l[1] = l[1] - 3 * i, tmp_r[1] = r[1] - 3 * i;
		for (int j = 2; j <= 4; j++)
			tmp_l[j] = l[j] - i, tmp_r[j] = r[j] - i;
		for (int j = 1; j <= 4; j++)
			tmp_l[j] = (tmp_l[j] + 1) >> 1, tmp_r[j] = tmp_r[j] >> 1;
		long long L = tmp_l[2] + tmp_l[3] + tmp_l[4], R = tmp_r[2] + tmp_r[3] + tmp_r[4];
		for (int j = 1; j <= 4; j++)
			if (tmp_l[j] > tmp_r[j]) goto A;
		if (tmp_l[1] <= R && L <= tmp_r[1])
		{
			long long a = tmp_l[2], b = tmp_l[3], c = tmp_l[4];
			if (a + b + c < tmp_l[1]) a += min(tmp_r[2] - tmp_l[2], tmp_l[1] - a - b - c);
			if (a + b + c < tmp_l[1]) b += min(tmp_r[3] - tmp_l[3], tmp_l[1] - a - b - c);
			if (a + b + c < tmp_l[1]) c += min(tmp_r[4] - tmp_l[4], tmp_l[1] - a - b - c); 
			X = b + c + i, Y = a + c + i, Z = a + b + i;
			return true;
		}
		A:;
	}
	return false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
		long long l = 0, r = 6e18;
		while (l + 1 <= r)
		{
			long long mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		check(l);
		printf("%lld %lld %lld\n", X, Y, Z);
	}
	return 0;
}