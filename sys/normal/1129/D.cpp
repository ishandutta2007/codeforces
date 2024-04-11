#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100505, p = 998244353;
int n, k, bloc, per, cnt[Maxn], bel[Maxn], las[Maxn], pre[Maxn];
long long f[Maxn], tot[Maxn], tag[Maxn], sum[305][Maxn];
void clear(int x)
{
	tot[x] = 0;
	for (int i = (x - 1) * per + 1; i <= x * per; i++)
		sum[x][cnt[i]] = 0;
}
void build(int x)
{
	for (int i = (x - 1) * per + 1; i <= x * per; i++)
	{
		cnt[i] += tag[x];
		(sum[x][cnt[i]] += f[i]) %= p;
		if (cnt[i] <= k) (tot[x] += f[i]) %= p;
	}
	tag[x] = 0;
}
void inc(int x)
{
	if (k >= tag[x]) (tot[x] += p - sum[x][k - tag[x]]) %= p;
	tag[x]++;
}
void dec(int x)
{
	tag[x]--;
	if (k >= tag[x]) (tot[x] += sum[x][k - tag[x]]) %= p;
}
void inc(int lt, int rt)
{
	if (lt > rt) return ;
	if (bel[lt] == bel[rt])
	{
		clear(bel[lt]);
		for (int i = lt; i <= rt; i++)
			cnt[i]++;
		build(bel[lt]);
		return ;
	}
	clear(bel[lt]);
	for (int i = lt; i <= bel[lt] * per; i++)
		cnt[i]++;
	build(bel[lt]);
	clear(bel[rt]);
	for (int i = (bel[rt] - 1) * per + 1; i <= rt; i++)
		cnt[i]++;
	build(bel[rt]);
	for (int i = bel[lt] + 1; i <= bel[rt] - 1; i++)
		inc(i);
}
void dec(int lt, int rt)
{
	if (lt > rt) return ;
	if (bel[lt] == bel[rt])
	{
		clear(bel[lt]);
		for (int i = lt; i <= rt; i++)
			cnt[i]--;
		build(bel[lt]);
		return ;
	}
	clear(bel[lt]);
	for (int i = lt; i <= bel[lt] * per; i++)
		cnt[i]--;
	build(bel[lt]);
	clear(bel[rt]);
	for (int i = (bel[rt] - 1) * per + 1; i <= rt; i++)
		cnt[i]--;
	build(bel[rt]);
	for (int i = bel[lt] + 1; i <= bel[rt] - 1; i++)
		dec(i);
}
int main()
{
	scanf("%d%d", &n, &k);
	bloc = min(300, (int)sqrt(n)), per = ceil(n / (double) bloc);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		pre[i] = las[x];
		las[x] = i;
		int tmp = pre[pre[i]];
		if (!tmp) tmp++, cnt[0] -= (bool) pre[i];
		dec(tmp, pre[i] - 1);
		tmp = pre[i];
		if (!tmp) tmp++, cnt[0]++;
		inc(tmp, i - 1);
		for (int j = 1; j <= bloc; j++)
			(f[i] += tot[j]) %= p;
		if (cnt[0] <= k) f[i]++;
		bel[i] = (i - 1) / per + 1;
		clear(bel[i]);
		build(bel[i]);
	}
	printf("%lld", f[n]);
	return 0;
}