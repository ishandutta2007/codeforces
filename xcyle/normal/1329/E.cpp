#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 400005
using namespace std;
const long long INF = 9e16;
int T, m;
long long n, k, a[maxn], b[maxn];
long long findl()
{
	long long l = 1, r = INF, mid;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		long long cnt = 0;
		for (register int i = 1; i <= m; i++) cnt += a[i] / mid;
		if(cnt >= k) l = mid;
		else r = mid - 1; 
	}
	return l;
}
long long findr()
{
	long long l = 1, r = INF, mid;
	while(l < r)
	{
		mid = (l + r) >> 1;
		long long cnt = 0;
		for (register int i = 1; i <= m; i++) cnt += (a[i] + mid - 1) / mid;
//		printf("%lld %lld\n", mid, cnt);
		if(cnt <= k) r = mid;
		else l = mid + 1; 
	}
	return l;
}
struct node
{
	long long l, r;
}p[maxn];
int num;
int cmp(node p1, node p2)
{
	return p1.l == p2.l ? p1.r > p2.r : p1.l < p2.l;
}
void solve()
{
	scanf("%lld%d%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	b[++m] = n;
	for (int i = 1; i <= m; i++) a[i] = b[i] - b[i - 1];
	k += m;
	long long ml = findl(), mr = findr();
//	printf("%lld %lld\n", ml, mr);
	if(ml >= mr)
	{
		printf("0\n");
		return;
	}
	num = 0;
	for (int i = 1; i <= m; i++)
	{
		if(a[i] / ml < (a[i] + mr - 1) / mr)
		{
			if(a[i] < mr + 1) p[++num] = (node){a[i] / (a[i] / ml + 1), INF};
			else p[++num] = (node){a[i] / (a[i] / ml + 1), (a[i] + ((a[i] + mr - 1) / mr - 1) - 1) / ((a[i] + mr - 1) / mr - 1)};
		}
	}
	p[++num] = (node){ml, mr};
	sort(p + 1, p + num + 1, cmp);
	long long maxr = mr, ans = INF;
	int tmp = 1;
	for (int i = 1; i <= num; i++)
	{
//		printf("%lld %lld\n", p[i].l, p[i].r);
		if(p[i].l > ml) break;
		while(tmp <= num && p[tmp].l < p[i].l)
		{
			maxr = max(maxr, p[tmp].r);
			tmp++;
		}
		ans = min(ans, maxr - p[i].l);
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}