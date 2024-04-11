#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, pos[Maxn];
long long sum, ans, val[Maxn], mask[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &val[i], &mask[i]);
		for (int j = 62; j >= 0; j--)
			if (mask[i] & (1LL << j))
			{
				pos[i] = j;
				break;
			}
		sum += val[i];
	}
	if (sum < 0)
		for (int i = 1; i <= n; i++) val[i] *= -1;
	for (int i = 0; i <= 62; i++)
	{
		long long tmp = 0;
		for (int j = 1; j <= n; j++)
			if (pos[j] == i) tmp += val[j];
		if (tmp > 0)
		{
			ans |= 1LL << i;
			for (int j = 1; j <= n; j++)
				if (mask[j] & (1LL << i)) val[j] = -val[j];
		}
	}
	printf("%lld", ans);
	return 0;
}