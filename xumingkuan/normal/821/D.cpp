#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
namespace Input
{
	const int BUF = 65536;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
}
inline char inputchar()
{
	using namespace Input;
	if(head == tail)
		*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
	return *head++;
}
inline void inputnum(int &ret)
{
	char ch = inputchar();
	while(ch < '0' || ch > '9')
		ch = inputchar();
	ret = ch - '0';
	ch = inputchar();
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + ch - '0';
		ch = inputchar();
	}
}
const int MAXN = 10101, MAXN2 = 101010, MAXM = 1010101, oo = 10101010;
int n, m, k, S, T;
map<int, int> r[MAXN], c[MAXN];
class Edge
{
public:
	int to, v, next;
}e[MAXM];
int head[MAXN2], en = 0;
void insert(int u, int v, int w)
{
//	printf("insert %d %d %d\n", u, v, w);
	e[++en].to = v;
	e[en].v = w;
	e[en].next = head[u];
	head[u] = en;
}
int dist[MAXN2];
int dijkstra()
{
	static priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	memset(dist, 63, sizeof(dist));
	q.push(make_pair(dist[S] = 0, S));
	while(!q.empty())
	{
		int now = q.top().second;
		if(dist[now] != q.top().first)
		{
			q.pop();
			continue;
		}
		q.pop();
		for(int i = head[now]; i > 0; i = e[i].next)
			if(dist[e[i].to] > dist[now] + e[i].v)
				q.push(make_pair(dist[e[i].to] = dist[now] + e[i].v, e[i].to));
	}
	return dist[T] >= oo ? -1 : dist[T];
}
int main()
{
	inputnum(n);
	inputnum(m);
	inputnum(k);
	for(int i = 1; i <= k; i++)
	{
		int x, y;
		inputnum(x);
		inputnum(y);
		r[x][y] = i;
		c[y][x] = i;
	}
	S = r[1][1];
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; i++)
	{
		int now = k + i;
		int lastpos = -1, lastval = -1;
		for(map<int, int>::iterator it = r[i].begin(); it != r[i].end(); it++)
		{
			if(lastpos == it->first - 1)
				insert(lastval, it->second, 0), insert(it->second, lastval, 0);
			if(i != 1)
				insert(it->second, now - 1, 1);//
			insert(it->second, now, 1);
			if(i != n)
				insert(it->second, now + 1, 1);//
			if(i != 1)
				insert(now - 1, it->second, 0);
			insert(now, it->second, 0);
			if(i != n)
				insert(now + 1, it->second, 0);
			lastpos = it->first;
			lastval = it->second;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int now = k + n + i;
		int lastpos = -1, lastval = -1;
		for(map<int, int>::iterator it = c[i].begin(); it != c[i].end(); it++)
		{
			if(lastpos == it->first - 1)
				insert(lastval, it->second, 0), insert(it->second, lastval, 0);
			if(i != 1)
				insert(it->second, now - 1, 1);//
			insert(it->second, now, 1);
			if(i != m)
				insert(it->second, now + 1, 1);//
			if(i != 1)
				insert(now - 1, it->second, 0);
			insert(now, it->second, 0);
			if(i != m)
				insert(now + 1, it->second, 0);
			lastpos = it->first;
			lastval = it->second;
		}
	}
	if(r[n][m])
		T = r[n][m];
	else
	{
		T = k + n + m + 1;
		insert(k + n, T, 0);
		insert(k + n + m, T, 0);
//		insert(k + n - 1, T, 0);
//		insert(k + n + m - 1, T, 0);
//		if(r[n - 1][m])
//			insert(r[n - 1][m], T, 0);
//		if(r[n][m - 1])
//			insert(r[n][m - 1], T, 0);
	}
	printf("%d\n", dijkstra());
	return 0;
}