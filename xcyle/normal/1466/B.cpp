#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 200005
using namespace std;
int T, n, a[maxn];
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[n]++;
	for (int i = n - 1; i >= 1; i--)
	{
		if(a[i] + 1 != a[i + 1]) a[i]++;
		if(a[i] > a[i + 1]) swap(a[i], a[i + 1]);
	}
	sort(a + 1, a + n + 1);
//	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
//	printf("\n");
	int len = unique(a + 1, a + n + 1) - a - 1;
	printf("%d\n", len);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}