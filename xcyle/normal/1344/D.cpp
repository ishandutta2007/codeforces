#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 100005
using namespace std;
const long long INF = 4e18;
int n;
long long k, a[maxn], b[maxn];
inline long long calc(long long x)
{
	long long l = 0, r = 1e9, mid;
	while(l < r)
	{
		mid = (l + r) / 2;
		if(3 * mid * mid + 3 * mid >= x) r = mid;
		else l = mid + 1; 
	}
//	printf("%d %d\n", x, l);
	return l;
}
long long check(long long x)
{
	long long tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += min(a[i], calc(a[i] - 1 - x));
	}
	return tot;
}
struct node
{
	int id;
	long long data;
}tmp[maxn];
inline int cmp(node a, node b)
{
	return a.data > b.data;
}
int main()
{
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	long long l = -INF, r = INF, mid;
	long long res, t = 0;
	while(l < r)
	{
		mid = (l + r) / 2;
		long long tp = check(mid);
		if(tp <= k) r = mid - 1;
		else l = mid + 1;
		if(tp <= k && tp > t) 
		{
			t = tp;
			res = mid;
		}
	}
	l = res;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		b[i] = min(a[i], calc(a[i] - 1 - l));
		k -= b[i];
		if(a[i] != b[i]) tmp[++cnt] = (node){i, a[i] - 1 - 3 * b[i] * b[i] - 3 * b[i]};
	}
//	printf("%lld\n", l);
//	for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
//	printf("\n");
	sort(tmp + 1, tmp + cnt + 1, cmp);
	for (int i = 1; i <= k; i++)
	{
		b[tmp[i].id]++;
	}
	for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
	return 0;
}