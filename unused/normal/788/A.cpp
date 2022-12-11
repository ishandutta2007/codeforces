#include <bits/stdc++.h>
using namespace std;

int dat[100005];
long long s[100005];

int main()
{
	int n;
	scanf("%d", &n);

	long long ans = LLONG_MIN;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
		s[i] = abs(dat[i] - dat[i - 1]);
	}

    s[1] = 0;
	long long now = 0;
	for (int i = 2; i <= n; i += 2)
	{
		now = max(now + s[i] - s[i - 1], s[i]);
		ans = max(ans, now);
	}

    now = 0;

	for (int i = 3; i <= n; i += 2)
	{
		now = max(now + s[i] - s[i - 1], s[i]);
		ans = max(ans, now);
	}

	printf("%lld\n", ans);
}