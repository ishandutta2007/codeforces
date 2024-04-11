#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define maxn 200005
using namespace std;
int n, m, u, v, vis[maxn], vis2[maxn], t[maxn], t2[maxn];
vector<int> G[maxn], G2[maxn];
int flag = 0, cnt = 0;
int d[maxn];
void work(int x)
{
	for (register int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		d[V]--;
		t[V] = min(t[V], t[x]);
		t[V] = min(t[V], x);
		if(!d[V]) work(V);
	}
	cnt++;
}
void work2(int x)
{
	for (register int i = 0; i < G2[x].size(); i++)
	{
		int V = G2[x][i];
		d[V]--;
		t2[V] = min(t2[V], t2[x]);
		t2[V] = min(t2[V], x);
		if(!d[V]) work2(V);
	}
}
inline int read()
{
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x;
}
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		u = read(), v = read();
		G[u].push_back(v);
		G2[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		G[n + 1].push_back(i);
		G2[n + 1].push_back(i);
	} 
	for (int i = 1; i <= n; i++) d[i] = G2[i].size() + 1;
	for (int i = 1; i <= n + 1; i++) t[i] = t2[i] = n + 1;
	work(n + 1);
	for (int i = 1; i <= n; i++) d[i] = G[i].size() + 1;
	work2(n + 1);
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		if(t[i] > i && t2[i] > i) num++;
	}
	if(cnt != n + 1)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n", num);
	for (int i = 1; i <= n; i++)
	{
		if(t[i] > i && t2[i] > i) putchar('A');
		else putchar('E');
	}
	return 0;
}