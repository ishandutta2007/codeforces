#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
const int INF = 2000000000;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		w |= ch == '-';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return w ? -x : x;
}
int n, q, a[maxn], b[maxn], w[maxn], x, y;
long long tw[maxn], t2[maxn];
void add(int x, long long data)
{
	int p = x;
	for(p; p <= n; p += (p & (-p))) t2[p] = (t2[p] + (ll)(data % mo + mo) % mo * (b[x] % mo + mo) % mo % mo) % mo;
	p = x;
	for(p; p <= n; p += (p & (-p))) tw[p] += data;
}
long long que2(int x)
{
	long long res = 0;
	for (; x; x -= (x & (-x))) res = (res +  t2[x]) % mo;
	return res;
} 
long long quew(int x)
{
	long long res = 0;
	for (; x; x -= (x & (-x))) res += tw[x];
	return res;
} 
int check(int t)
{
	int pos = lower_bound(b + 1, b + n + 2, t - x) - b;
	pos = max(pos, x), pos = min(pos, y + 1);
	return quew(pos - 1) - quew(x - 1) <= quew(y) - quew(pos - 1);
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = a[i] - i;
	b[n + 1] = INF;
	for (int i = 1; i <= n; i++) w[i] = read();
	for (int i = 1; i <= n; i++) add(i, w[i]);
	while(q--)
	{
		x = read(), y = read();
		if(x < 0)
		{
			add(-x, y - w[-x]);
			w[-x] = y;
		}
		else
		{
			int l = 1, r = 1000000000, mid, ans = 1;
			while(l <= r)
			{
				mid = (l + r) >> 1;
//				printf("%d %d %d\n", l, r, mid);
				if(check(mid))
				{
					ans = max(ans, mid);
					l = mid + 1;
				}
				else r = mid - 1;
			}
			l = ans;
			int pos = lower_bound(b + 1, b + n + 2, l - x) - b;
			pos = max(pos, x), pos = min(pos, y + 1);
			printf("%lld\n", ((que2(y) - que2(pos - 1) - que2(pos - 1) + que2(x - 1) + (long long)2 * mo) % mo + (ll)(l - x) * ((quew(pos - 1) - quew(x - 1) - quew(y) + quew(pos - 1) + (long long)2 * mo) % mo + mo) % mo) % mo);
		} 
	}
	return 0;
}