#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, k, a[Maxn], cnt[Maxn];
long long ans;
long long cal(long long x, int y)
{
	return (x / y + 1) * (x / y + 1) * (x % y) + (x / y) * (x / y) * (y - x % y);
}
priority_queue <pair <long long, int> > Pr;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), Pr.push(make_pair(cal(a[i], 1) - cal(a[i], 2), i));
	for (int i = 1; i <= k - n; i++)
	{
		int u = Pr.top().second;
		Pr.pop();
		cnt[u]++;
		Pr.push(make_pair(cal(a[u], cnt[u] + 1) - cal(a[u], cnt[u] + 2), u));
	}
	for (int i = 1; i <= n; i++)
		ans += cal(a[i], cnt[i] + 1);
	printf("%lld", ans);
	return 0;
}