#include <iostream>
#include <cstdio>
#define maxn 55
using namespace std;
int T, n, a[maxn];
int t[50 * 50];
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			t[a[i] - a[j]] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 50; i++) ans += t[i];
	printf("%d\n", ans);
	for (int i = 1; i <= 50; i++) t[i] = 0;
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}