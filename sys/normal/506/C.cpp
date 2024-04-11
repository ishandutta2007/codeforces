#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
long long l, r;
int n, m, k, p, h[Maxn], a[Maxn];
struct sta
{
	long long now, val;
	int h, a;
	bool operator < (const sta &tmp) const
	{
		return val > tmp.val;
	}
};
priority_queue <sta> Pr;
bool check(long long now)
{
	long long cnt = 0;
	for (int i = 1; i <= n; i++)
		Pr.push((sta){now, now / a[i], h[i], a[i]});
	for (int i = 1; i < m; i++)
	{
		if (Pr.top().now < i * (long long) Pr.top().a) return false;
		cnt += k;
		while (cnt)
		{
			sta u = Pr.top();
			if (u.now >= (i + 1) * (long long) u.a)
				break;
			Pr.pop();
			cnt--;
			u.now += p;
			u.val = u.now / u.a;
			Pr.push(u);
		}
	}
	if (Pr.top().now < m * (long long) Pr.top().a) return false;
	cnt += k;
	while (!Pr.empty())
	{
		sta u = Pr.top();
		Pr.pop();
		if (u.now - u.a * (long long) m < u.h)
			cnt -= (u.h - u.now + u.a * (long long) m - 1) / p + 1;
	}
	if (cnt >= 0)
		return true;
	return false;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &h[i], &a[i]);
	r = 1LL << 60;
	while (l + 1 <= r)
	{
		long long mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
		while (!Pr.empty()) Pr.pop();
	}
	check(l);
	printf("%lld", l);
	return 0;
}