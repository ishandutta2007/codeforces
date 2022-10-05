#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2000005, mod = 1e9 + 7;
int n, p[Maxn], maxi[Maxn], cnt[Maxn];
long long ans = 1;
vector <int> Ve;
void update(int x, int c)
{
	if (c == maxi[x]) cnt[x]++;
	else if (c > maxi[x]) cnt[x] = 1, maxi[x] = c;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	sort(p + 1, p + 1 + n);
	for (int i = n; i >= 1; i--)
	{
		if (!maxi[p[i]]) update(p[i], 1);
		else
		{
			Ve.push_back(p[i] - 1);
			int lim = sqrt(p[i] - 1), tmp = p[i] - 1;
			for (int j = 2; j <= lim; j++)
			{
				int ct = 0;
				while (tmp % j == 0) ct++, tmp /= j;
				update(j, ct);
			}
			if (tmp != 1) update(tmp, 1);
		}
	}
	for (int i = 1; i <= 2000000; i++)
		ans = ((long long) (ans * pow(i, maxi[i]) + 0.5)) % mod;
	for (auto now : Ve)
	{
		int lim = sqrt(now), tmp = now;
		for (int j = 2; j <= lim; j++)
		{
			int ct = 0;
			while (tmp % j == 0) ct++, tmp /= j;
			if (ct && ct == maxi[j] && cnt[j] == 1) goto END;
		}
		if (tmp != 1 && maxi[tmp] == 1 && cnt[tmp] == 1) goto END;
		ans++;
		break;
		END:;
	}
	printf("%lld", ans);
	return 0;
}