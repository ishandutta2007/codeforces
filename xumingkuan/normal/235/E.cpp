#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXM 2020
#define MAXN 4040404
#define MOD 1073741824
int n1, n2, n3, n, n0;
int prime[MAXM], pnum = 0;
int d[MAXN], p[MAXN], cnt[MAXN], m[MAXN], rm[MAXN];
unsigned f[100][MAXM], ans = 0;
int g[100][MAXM], num[100];
class Edge
{
	public:
		int to, next;
};
Edge e[MAXN];
int head[MAXN], need[MAXN], edgenum = 0, st = 0;
void init()
{
	memset(p, 0, sizeof(p));
	d[1] = 1;
	rm[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		if(!p[i] && i <= n0)
		{
			prime[++pnum] = i;
			p[i] = m[i] = i;
			cnt[i] = rm[i] = 1;
			d[i] = 2;
		}
		else if(!p[i])
			continue;
		for(int j = 1; j <= pnum && prime[j] < p[i] && (long long)i * prime[j] <= n; j++)
		{
			int now = i * prime[j];
			p[now] = m[now] = prime[j];
			cnt[now] = 1;
			rm[now] = i;
			d[now] = d[i] * 2;
		}
		if((long long)i * p[i] <= n)
		{
			int now = i * p[i];
			p[now] = p[i];
			m[now] = m[i] * p[i];
			cnt[now] = cnt[i] + 1;
			rm[now] = rm[i];
			d[now] = d[i] / cnt[now] * (cnt[now] + 1);
		}
	}
}
inline void insert(int u, int v)
{
	e[++edgenum].to = v;
	e[edgenum].next = head[u];
	head[u] = edgenum;
}
unsigned getf(int u, int i)
{
	if(g[u][i] == num[u])
		return f[u][i];
	g[u][i] = num[u];
	return f[u][i] = getf(u - 1, i) * (cnt[num[u]] + 1) - getf(u - 1, i / p[num[u]]) * cnt[num[u]];
}
void dfs(int v)
{
	ans += getf(st, n3) * need[v];
	for(int i = head[v]; i; i = e[i].next)
	{
		num[++st] = e[i].to;
		f[st][0] = 0;
		g[st][0] = e[i].to;
		f[st][1] = d[e[i].to];
		g[st][1] = e[i].to;
		dfs(e[i].to);
		st--;
	}
}
int main()
{
	scanf("%d%d%d", &n1, &n2, &n3);
	n = max(n1 * n2, n3);
	n0 = max(max(n1, n2), n3);
	init();
	memset(head, 0, sizeof(head));
	memset(need, 0, sizeof(need));
	memset(g, 0, sizeof(g));
	for(int i = 1; i <= n1; i++)
		for(int j = 1; j <= n2; j++)
			if(!need[i * j]++)
				insert(rm[i * j], i * j);
	f[0][0] = 0;
	num[0] = 1;
	g[0][0] = 1;
	for(int i = 1; i <= n3; i++)
		f[0][i] = f[0][i - 1] + d[i], g[0][i] = 1;
	dfs(1);
	printf("%u\n", ans % MOD);
	return 0;
}