#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
const int MAXN = 505050, MAXM = 8080808;
const long long oo = 1020304050607080ll;
class Edge
{
public:
	int to, v, next;
};
Edge e[MAXM];
int head[MAXN], en = 1, numtot;
void insert(int u, int v, int w)
{
	e[++en].to = v;
	e[en].v = w;
	e[en].next = head[u];
	head[u] = en;
}
class Segment_tree
{
public:
	int st, ed, num;
	Segment_tree *l, *r;
	void build(int st_, int ed_)
	{
		st = st_;
		ed = ed_;
		if(st == ed)
		{
			num = st;
			return;
		}
		num = ++numtot;
		l = new Segment_tree();
		l->build(st, (st + ed) >> 1);
		r = new Segment_tree();
		r->build(((st + ed) >> 1) + 1, ed);
	}
	void work(int st_, int ed_, int to, int v, bool rev) const
	{
		if(st >= st_ && ed <= ed_)
		{
			if(rev)
				insert(to, num, v);
			else
				insert(num, to, v);
			return;
		}
		if(l->ed >= st_)
			l->work(st_, ed_, to, v, rev);
		if(r->st <= ed_)
			r->work(st_, ed_, to, v, rev);
	}
	void dfs(bool tp) const
	{
		if(st == ed)
			return;
		if(tp)
		{
			insert(num, l->num, 0);
			insert(num, r->num, 0);
		}
		else
		{
			insert(l->num, num, 0);
			insert(r->num, num, 0);
		}
		l->dfs(tp);
		r->dfs(tp);
	}
}*rt1, *rt2;
int n, qq, s;
long long dist[MAXN];
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
void dijkstra()
{
	memset(dist, 63, sizeof(dist));
	q.push(make_pair(dist[s] = 0, s));
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
}
int main()
{
	scanf("%d%d%d", &n, &qq, &s);
	memset(head, -1, sizeof(head));
	numtot = n;
	rt1 = new Segment_tree();
	rt1->build(1, n);
	rt1->dfs(true);
	rt2 = new Segment_tree();
	rt2->build(1, n);
	rt2->dfs(false);
	for(int i = 1; i <= qq; i++)
	{
		int t, v, l, r, w;
		scanf("%d", &t);
		if(t == 1)
		{
			scanf("%d%d%d", &v, &l, &w);
			insert(v, l, w);
		}
		else if(t == 2)
		{
			scanf("%d%d%d%d", &v, &l, &r, &w);
			rt1->work(l, r, v, w, true);
		}
		else if(t == 3)
		{
			scanf("%d%d%d%d", &v, &l, &r, &w);
			rt2->work(l, r, v, w, false);
		}
	}
	dijkstra();
	for(int i = 1; i <= n; i++)
		printf("%I64d ", dist[i] > oo ? -1 : dist[i]);
	return 0;
}