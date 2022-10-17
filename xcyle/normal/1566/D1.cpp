#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 100005
using namespace std;
int T, n, m;
struct node
{
	int a, id;
}p[maxn];
inline int cmp1(node pp, node qq)
{
	return pp.a == qq.a ? pp.id < qq.id : pp.a < qq.a;
}
int t[305][305], num[maxn];
inline void add(int pos, int x)
{
	for (; x <= m; x += (x & (-x))) t[pos][x]++;
}
inline int que(int pos, int x)
{
	int res = 0;
	for (; x; x -= (x & (-x))) res += t[pos][x];
	return res;
}
void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			t[i][j] = 0;
		}
	}
	for (int i = 1; i <= n * m; i++)
	{
		scanf("%d", &p[i].a);
		p[i].id = i;
	}
	sort(p + 1, p + n * m + 1, cmp1);
	int last = 1;
	p[n * m + 1].a = -1;
	for (int i = 2; i <= n * m + 1; i++)
	{
		if(p[i].a == p[last].a) continue;
		int rw1 = (last - 1) / m + 1, cl1 = (last - 1) % m + 1;
		int rw2 = (i - 2) / m + 1, cl2 = (i - 2) % m + 1, now = last;
		for (int j = rw1; j <= rw2; j++)
		{
			int l = max(last, (j - 1) * m + 1), r = min(i - 1, j * m);
			l = (l - 1) % m + 1, r = (r - 1) % m + 1;
			for (int k = r; k >= l; k--)
			{
				num[p[now++].id] = (j - 1) * m + k;
			}
		}
		last = i;
	}
	long long ans = 0;
	for (int i = 1; i <= n * m; i++)
	{
		if(!num[i]) continue;
		int rw = (num[i] - 1) / m + 1, cl = (num[i] - 1) % m + 1;
		ans += que(rw, cl);
		add(rw, cl);
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}