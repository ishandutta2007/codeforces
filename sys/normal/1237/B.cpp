#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, a[Maxn], b[Maxn], rk[Maxn], ans;
int sum[Maxn];
int lowbit(int x)
{
	return x & -x;
}
void add(int x)
{
	for (int i = x; i <= n; i += lowbit(i))
		sum[i]++;
}
int ask(int x)
{
	int tmp = 0;
	for (int i = x; i; i -= lowbit(i))
		tmp += sum[i];
	return tmp;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), rk[a[i]] = i;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		if (rk[b[i]] + (ask(n) - ask(rk[b[i]])) > i) ans++, add(rk[b[i]]);
	}
	printf("%d", ans);
	return 0;
}