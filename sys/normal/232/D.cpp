#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 400005;
int n, q, ct, h[Maxn], lg[Maxn], rk[Maxn], tmp[Maxn], ans[Maxn], buc[Maxn], sa[Maxn], first[Maxn], second[Maxn], mini[Maxn][21];
struct quest
{
	int pos1, pos2, val, id;
	bool operator < (const quest &tmp) const
	{
		return pos1 < tmp.pos1;
	}
} Q[6 * Maxn];
void radix_sort(void)
{
	for (int i = 1; i <= n; i++) buc[i] = 0;
	for (int i = 1; i <= n; i++) buc[first[second[i]]]++;
	for (int i = 1; i <= n; i++) buc[i] += buc[i - 1];
	for (int i = n; i >= 1; i--) sa[buc[first[second[i]]]--] = second[i];
}
void work(void)
{
	for (int i = 1; i <= n; i++)
		second[i] = i;
	for (int i = 1; i <= n; i++)
		first[i] = h[i];
	radix_sort();
	for (int gap = 1; gap <= n; gap <<= 1)
	{
		int cnt = 0;
		for (int i = n - gap + 1; i <= n; i++)
			second[++cnt] = i;
		for (int i = 1; i <= n; i++)
			if (sa[i] > gap) second[++cnt] = sa[i] - gap;
		radix_sort();
		for (int i = 1; i <= n; i++)
			swap(first[i], second[i]);
		cnt = 0;
		first[sa[1]] = ++cnt;
		for (int i = 2; i <= n; i++)
			first[sa[i]] = (second[sa[i]] == second[sa[i - 1]] && second[sa[i] + gap] == second[sa[i - 1] + gap]) ? cnt : ++cnt;
	}
 	for (int i = 1; i <= n; i++)
		rk[sa[i]] = i;
	int height = 0;
	for (int i = 1; i <= n; i++)
	{
		int u = sa[rk[i] - 1];
		if (height) height--;
		while (h[u + height] == h[i + height]) height++;
		mini[rk[i]][0] = height;
	}
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			mini[i][j] = min(mini[i][j - 1], mini[i + (1 << (j - 1))][j - 1]);
}
int lcp(int x, int y)
{
	int u = rk[x], v = rk[y], Range;
	if (u > v) swap(u, v);
	u++;
	Range = lg[v - u + 1];
	return min(mini[u][Range], mini[v - (1 << Range) + 1][Range]);
}
int sum[Maxn];
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int y)
{
	for (int i = x; i <= n; i += lowbit(i))
		sum[i] += y;
}
int ask(int x)
{
	int result = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		result += sum[i];
	return result;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	for (int i = n; i >= 2; i--)
		h[i] -= h[i - 1];
	h[1] = 0x3f3f3f3e;
	h[n + 1] = 0x3f3f3f3f;
	n++;
	for (int i = n + 1; i < 2 * n; i++) h[i] = -h[i - n];
	n = n * 2 - 1;
	for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; i++) tmp[i] = h[i];
	sort(tmp + 1, tmp + 1 + n);
	int c = unique(tmp + 1, tmp + 1 + n) - tmp - 1;
	for (int i = 1; i <= n; i++)
		h[i] = lower_bound(tmp + 1, tmp + 1 + c, h[i]) - tmp;
	work();
	scanf("%d", &q);
	for (int Cases = 1; Cases <= q; Cases++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r)
		{
			ans[Cases] = n / 2 - 1;
			continue;
		}
		int lt = rk[l + 1], rt = rk[l + 1];
		for (int i = 20; i >= 0; i--)
		{
			if (rt + (1 << i) <= n && lcp(l + 1, sa[rt + (1 << i)]) >= r - l) rt += 1 << i;
			if (lt - (1 << i) >= 1 && lcp(l + 1, sa[lt - (1 << i)]) >= r - l) lt -= 1 << i;
		}
		Q[++ct] = (quest){lt - 1, 2 * l - r, -1, Cases};
		Q[++ct] = (quest){lt - 1, r + 1, 1, Cases};
		Q[++ct] = (quest){lt - 1, n, -1, Cases};
		Q[++ct] = (quest){rt, 2 * l - r, 1, Cases};
		Q[++ct] = (quest){rt, r + 1, -1, Cases};
		Q[++ct] = (quest){rt, n, 1, Cases};
	}
	sort(Q + 1, Q + 1 + ct);
	int pnt = 1;
	while (!Q[pnt].pos1) pnt++;
	for (int i = 1; i <= n; i++)
	{
		if (sa[i] > n / 2 + 1) add(sa[i] - n / 2 - 1, 1);
		while (pnt <= ct && Q[pnt].pos1 == i)
			ans[Q[pnt].id] += Q[pnt].val * ask(Q[pnt].pos2), pnt++;
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}