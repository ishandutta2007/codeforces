#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 101010
int k, n, m, t, nt;
int b[MAXN], f[MAXN];
class Edge
{
	public:
		int to, next;
};
Edge e[MAXN];
int head[MAXN], edgenum;
void insert(int u, int v)
{
	e[++edgenum].to = v;
	e[edgenum].next = head[u];
	head[u] = edgenum;
}
void solve()
{
	edgenum = 0;
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for(int i = n; i >= 1; i--)
		insert(b[i], i);
	for(int i = 1; i <= m + 1; i++)
		f[i] = n * t + 2;
	for(int i = 1; i <= m; i++)
	{
		if(head[i] < 0)
			continue;
		int zz1 = 1, zz2 = head[i], circle = 0;
		while(circle < nt)
		{
			int now = circle + e[zz2].to;
			while(f[zz1] <= now)
				zz1++;
			if((zz2 = e[zz2].next) < 0)
				zz2 = head[i], circle += n;
			if(now > f[zz1 - 1])
			{
				int tmp = f[zz1];
				f[zz1++] = now;
				if(tmp == n * t + 2)
					break;
				while(circle < nt && circle + e[zz2].to <= tmp)
					if((zz2 = e[zz2].next) < 0)
						zz2 = head[i], circle += n;
			}
		}
	}
	for(int i = 1; i <= m + 1; i++)
		if(f[i] == n * t + 2)
		{
			printf("%d\n", i - 1);
			break;
		}
}
int main()
{
	scanf("%d%d%d%d", &k, &n, &m, &t);
	if(t > n)
		t = n;
	if(t > m)
		t = m;
	nt = n * t;
	f[0] = -1;
	for(int i = 1; i <= k; i++)
		solve();
	return 0;
}
/*
2 10 10 2
1 10 5 6 4 8 2 3 9 7
2 5 3 6 4 7 5 8 6 1
*/