#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 600005
using namespace std;
int t, n, a[maxn], b[maxn];
inline bool cmp(int x, int y)
{
	return x > y;
}
void solve()
{
	scanf("%d", &n);
	for (int i = n + 1; i <= 5 * n; i++) a[i] = b[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &b[i]);
	}
	sort(b + 1, b + n + 1, cmp);
	int now = n - n / 4;
	int suma = 0, sumb = 0;
	for (int i = 1; i <= now; i++)
	{
		suma += a[i];
		sumb += b[i];
	}
	if(suma >= sumb) 
	{
		printf("0\n");
		return;
	}
	for (int i = 1; i <= 5 * n; i++)
	{
		suma += 100;
		suma -= a[now];
		now--;
		if(i + n - (i + n) / 4 > now + i)
		{
			suma += a[now + 1];
			now++;
			sumb += b[i + n - (i + n) / 4];
		}
//		printf("%d %d %d\n", now, suma, sumb);
		if(suma >= sumb)
		{
			printf("%d\n", i);
			return;
		}
	}
}
int main()
{
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}