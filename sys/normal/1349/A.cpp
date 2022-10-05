#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, a[Maxn], cnt[Maxn];
pair <int, int> mini[Maxn];
long long ans = 1;
int main()
{
	memset(mini, 0x3f, sizeof(mini));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		int Maxi = sqrt(a[i]);
		for (int j = 2; j <= Maxi; j++)
			if (a[i] % j == 0)
			{
				cnt[j]++;
				int ct = 0;
				while (a[i] % j == 0) a[i] /= j, ct++;
				if (ct <= mini[j].first) mini[j].second = mini[j].first, mini[j].first = ct;
				else if (ct <= mini[j].second) mini[j].second = ct;
			}
		if (a[i] != 1)
		{
			cnt[a[i]]++;
			if (1 <= mini[a[i]].first) mini[a[i]].second = mini[a[i]].first, mini[a[i]].first = 1;
			else if (1 <= mini[a[i]].second) mini[a[i]].second = 1;
		}
			
	}
	for (int i = 1; i <= 200000; i++)
	{
		if (cnt[i] == n) ans *= powl(i, mini[i].second);
		if (cnt[i] == n - 1) ans *= powl(i, mini[i].first);
	}
	printf("%lld", ans);
	return 0;
}