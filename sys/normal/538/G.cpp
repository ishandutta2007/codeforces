#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2000005;
int n, l, ord[Maxn];
long long t[Maxn], x[Maxn], y[Maxn], k[Maxn], r[Maxn], mini_x, maxi_x = 0x3f3f3f3f3f3f3f3fLL, mini_y, maxi_y = 0x3f3f3f3f3f3f3f3fLL;
bool type_x[Maxn], type_y[Maxn];
int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++)
	{
		long long a, b;
		scanf("%lld%lld%lld", &t[i], &a, &b);
		if ((a + b + t[i]) & 1)
			return puts("NO"), 0;
		x[i] = (a + b + t[i]) / 2, y[i] = (b - a + t[i]) / 2;
		ord[i] = i;
		k[i] = t[i] / l, r[i] = t[i] % l;
	}
	sort(ord + 1, ord + 1 + n, [](int a, int b){return t[a] % l < t[b] % l;});
	k[++n] = -1, r[n] = l, ord[n] = n;
	for (int i = 1; i <= n; i++)
	{
		long long dx = x[ord[i]] - x[ord[i - 1]], dy = y[ord[i]] - y[ord[i - 1]], dk = k[ord[i]] - k[ord[i - 1]], dw = r[ord[i]] - r[ord[i - 1]];
		if (!dk && !(dx >= 0 && dx <= dw))
			return puts("NO"), 0;
		if (dk > 0) mini_x = max(mini_x, (dx - dw + dk - 1) / dk), maxi_x = min(maxi_x, dx / dk);
		if (dk < 0) mini_x = max(mini_x, (-dx - dk - 1) / -dk), maxi_x = min(maxi_x, (-dx + dw) / -dk);
		if (!dk && !(dy >= 0 && dy <= dw))
			return puts("NO"), 0;
		if (dk > 0) mini_y = max(mini_y, (dy - dw + dk - 1) / dk), maxi_y = min(maxi_y, dy / dk);
		if (dk < 0) mini_y = max(mini_y, (-dy - dk - 1) / -dk), maxi_y = min(maxi_y, (-dy + dw) / -dk);
	}
	if (mini_x > maxi_x || mini_y > maxi_y)
		return puts("NO"), 0;
	ord[n + 1] = n + 1;
	t[n + 1] = -l;
	for (int i = 1; i <= n + 1; i++)
	{
		int need_x = x[ord[i]] - x[ord[i - 1]] - mini_x * (k[ord[i]] - k[ord[i - 1]]);
		int need_y = y[ord[i]] - y[ord[i - 1]] - mini_y * (k[ord[i]] - k[ord[i - 1]]);
		for (int j = r[ord[i - 1]]; j < r[ord[i]]; j++)
		{
			if (need_x) type_x[j] = 1, need_x--;
			if (need_y) type_y[j] = 1, need_y--;
		}
	}
	char ch[2][2] = {{'D', 'L'}, {'R', 'U'}};
	for (int i = 0; i < l; i++)
		putchar(ch[type_x[i]][type_y[i]]);
	return 0;
}