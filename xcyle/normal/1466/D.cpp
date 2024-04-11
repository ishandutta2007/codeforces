#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 100005
using namespace std;
const int INF = 20000000;
int T, a, b;
int n, aa[maxn], d[maxn];
int id[maxn];
inline int cmp(int x, int y)
{
	return aa[x] > aa[y];
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) d[i] = -1;
	for (int i = 1; i <= n; i++) scanf("%d", &aa[i]);
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		d[a]++, d[b]++;	
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += aa[i];
	printf("%lld ", ans);
	for (int i = 1; i <= n; i++)
	{
		while(d[id[i]])
		{
			ans += aa[id[i]];
			printf("%lld ", ans);
			d[id[i]]--;
		}
	}
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}