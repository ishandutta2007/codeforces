#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, ord[Maxn], f[65][Maxn];
long long a[Maxn], now = 1;
void work(int x, bool w)
{
	int cost = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int now = (a[i] >> (x - 1)) & 1;
		if (now + w == 2) cnt++;
		if (now + w == 1) cost++;
	}
	f[x][cnt] = min(f[x][cnt], f[x - 1][0] + cost);
	for (int i = 1; i <= n; i++)
	{
		int now = (a[ord[i]] >> (x - 1)) & 1;
		if (now + w == 0 || now + w == 2) cost++;
		if (now + w == 1) cnt++, cost--;
		f[x][cnt] = min(f[x][cnt], f[x - 1][i] + cost);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		a[i] = a[n] - a[i];
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) ord[i] = i;
	for (int i = 1; i <= 60; i++)
	{
		work(i, 0), work(i, 1);
		for (int j = 1; j <= n; j++) ord[j] = j;
		now *= 2;
		sort(ord + 1, ord + 1 + n, [](int x, int y){return a[x] % now > a[y] % now;});
	}
	printf("%d", f[60][0]);
	return 0;
}