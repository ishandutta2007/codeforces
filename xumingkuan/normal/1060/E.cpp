#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 202020;
int n;
class Edge
{
public:
	int to, next;
}e[MAXN * 2];
int head[MAXN], en = 1;
void insert()
{
	int u, v;
	scanf("%d%d", &u, &v);
	e[++en].to = v;
	e[en].next = head[u];
	head[u] = en;
	e[++en].to = u;
	e[en].next = head[v];
	head[v] = en;
}
int f[MAXN][2];//even, odd
int sum[MAXN];
long long add[MAXN];
long long ans = 0;
void dfs(int p, int fa)
{
	f[p][0] = 1;
	sum[p] = 1;
	for(int i = head[p]; i > 0; i = e[i].next)
		if(e[i].to != fa)
		{
			int to = e[i].to;
			dfs(to, p);
			ans += add[p] * sum[to];
			ans += add[to] * sum[p];
			ans += (long long)sum[to] * sum[p];
			ans += (long long)f[p][1] * f[to][1];
			sum[p] += sum[to];
			add[p] += add[to] + f[to][1];
			f[p][0] += f[to][1];
			f[p][1] += f[to][0];
		}
}
int main()
{
	scanf("%d", &n);
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; i++)
		insert();
	memset(f, 0, sizeof(f));
	memset(sum, 0, sizeof(sum));
	memset(add, 0, sizeof(add));
	dfs(1, 0);
	printf("%I64d\n", ans);
	return 0;
}