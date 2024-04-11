#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 262144
int n;
class Route
{
	public:
		int u, v;
		void read()
		{
			scanf("%d%d", &u, &v);
			if(u > v)
				swap(u, v);
		}
		inline bool operator <(const Route &b) const
		{
			return u < b.u;
		}
};
Route a[MAXN / 2];
int t[MAXN * 2];
inline void insert(int x)
{
	for(t[x += MAXN]++; x >>= 1; t[x] = t[x << 1] + t[(x << 1) | 1]);
}
inline void erase(int x)
{
	for(t[x += MAXN] -= 2; x >>= 1; t[x] = t[x << 1] + t[(x << 1) | 1]);
}
inline int query(int l, int r)//(l,r)
{
	int ans = 0;
	for(l += MAXN, r += MAXN; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if(~l & 1)
			ans += t[l ^ 1];
		if(r & 1)
			ans += t[r ^ 1];
	}
	return ans;
}
int f[MAXN / 2], g[MAXN / 2], b[MAXN];
long long ans = 0;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		a[i].read();
	sort(a + 1, a + n + 1);
	b[0] = 0;
	for(int i = 1; i <= n; i++)
		b[a[i].u] = b[a[i].v] = i;
	memset(t, 0, sizeof(t));
	for(int i = 1; i <= (n << 1); i++)
		if(a[b[i]].v == i)
			insert(a[b[i]].u), f[b[i]] = query(a[b[i]].u, i);
	memset(t, 0, sizeof(t));
	for(int i = 1; i <= (n << 1); i++)
		if(a[b[i]].u == i)
			insert(i);
		else
			erase(a[b[i]].u), insert(a[b[i]].v), g[b[i]] = query(a[b[i]].u, i);
	for(int i = 1; i <= n; i++)
		ans += (long long)(n - 1 - f[i] - g[i]) * f[i] * 2 + (long long)(n - 1 - g[i]) * g[i];
	printf("%I64d\n", (long long)n * (n - 1) * (n - 2) / 6 - (ans >> 1));
	return 0;
}