#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int n, a[Maxn], fa[Maxn], siz[Maxn];
long long ans;
bool flag, vis[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	if (a != b)
	{
		fa[a] = b;
		siz[b] += siz[a];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (vis[a[i]]) 
		{
			puts("-1");
			return 0;
		}
		vis[a[i]] = true;
		merge(i, a[i]);
	}
	for (int i = 1; i <= n; i++)
		if (get_fa(i) == i)
		{
			if (!ans) ans = siz[i];
			else ans = ans / __gcd(ans, (long long) siz[i]) * siz[i];
		}
	if (ans % 2 == 0) printf("%lld\n", ans / 2);
	else printf("%lld", ans);
	return 0;
}