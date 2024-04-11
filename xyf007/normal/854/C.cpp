#include <bits/stdc++.h>
using namespace std;
long long n, k, c[1000001], t[1000001];
priority_queue<pair<long long, long long> > q;
int main()
{
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &c[i]);
		if (i <= k)
		{
			q.push(make_pair(c[i], i));
		}
	}
	long long ans = 0;
	for (long long i = k + 1; i <= k + n; i++)
	{
		q.push(make_pair(c[i], i));
		pair<long long, long long> temp = q.top();
		q.pop();
		ans += temp.first * (i - temp.second);
		t[temp.second] = i;
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld ", t[i]);
	}
	return 0;
}