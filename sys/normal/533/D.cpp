#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, ct, top, ans, d[Maxn], pos[Maxn], sta[Maxn], far1[Maxn], far2[Maxn], mini[Maxn], tmp[Maxn];
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int y)
{
	for (int i = x; i <= ct; i += lowbit(i))
		mini[i] = min(mini[i], y);
}
int ask(int x)
{
	int tmp = 0x3f3f3f3f;
	for (int i = x; i; i -= lowbit(i))
		tmp = min(tmp, mini[i]);
	return tmp;
}
int main()
{
//	freopen("CF533D.in", "r", stdin);
	memset(mini, 0x3f, sizeof(mini));
	scanf("%d", &n);
	for (int i = 0; i <= n + 1; i++)
		scanf("%d", &pos[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= n; i++)
	{
		while (top && far1[sta[top]] < pos[i]) top--;
		far1[i] = pos[i] + 2 * d[i] + pos[sta[top]] - pos[i];
		while (top && far1[sta[top]] <= far1[i]) top--;
		sta[++top] = i;
	}
	top = 0;
	sta[++top] = n + 1;
	for (int i = n; i >= 1; i--)
	{
		while (top && far2[sta[top]] > pos[i]) top--;
		far2[i] = pos[i] - 2 * d[i] + pos[sta[top]] - pos[i];
		while (top && far2[sta[top]] >= far2[i]) top--;
		sta[++top] = i;
	}
	for (int i = 1; i <= n; i++)
		if (far1[i] >= pos[n + 1] || far2[i] <= 0)
		{
			puts("0");
			return 0;
		}
	for (int i = 1; i <= n; i++)
		tmp[i] = far1[i];
	sort(tmp + 1, tmp + 1 + n);
	ct = unique(tmp + 1, tmp + 1 + n) - tmp - 1;
	ans = pos[n + 1] - pos[0];
	for (int i = n; i >= 1; i--)
	{
		if (far1[i] > pos[i])
		{
			ans = min(ans, pos[n + 1] - pos[i]);
			ans = min(ans, ask(lower_bound(tmp + 1, tmp + 1 + ct, far1[i]) - tmp) - pos[i]);
		}
		if (far2[i] < pos[i])
		{
			ans = min(ans, pos[i]);
			add(lower_bound(tmp + 1, tmp + 1 + ct, far2[i]) - tmp, pos[i]);
		}
	}
	printf("%d.%d", ans / 2, (ans & 1) * 5);
	return 0;
}