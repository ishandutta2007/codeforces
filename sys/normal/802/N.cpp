#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, k, a[Maxn], b[Maxn];
long long ans;
priority_queue <pair <long long, bool> > Pr;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	long long lt = 0, rt = 2e9;
	while (true)
	{
		long long mid = (lt + rt) >> 1;
		int cnt = 0;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			Pr.push(make_pair(-a[i], false));
			long long tmp = b[i] - mid - Pr.top().first;
			if (tmp < 0) ans += tmp, Pr.pop(), Pr.push(make_pair(b[i] - mid, true));
		}
		while (!Pr.empty()) cnt += Pr.top().second, Pr.pop();
		if (cnt == k)
		{
			printf("%lld", ans + k * mid);
			return 0;
		}
		if (cnt < k) lt = mid + 1;
		else rt = mid - 1;
	}
	return 0;
}