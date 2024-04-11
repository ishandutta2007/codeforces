#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 202020;
int n, q, a[MAXN];
class Segment_tree
{
public:
	int st, ed;
	Segment_tree *l, *r;
	int v;
	Segment_tree(int st, int ed, Segment_tree *l, Segment_tree *r): st(st), ed(ed), l(l), r(r), v(0) {}
	void change(int x)
	{
		v = x;
	}
	void down()
	{
	}
	void update()
	{
		v = l->v + r->v;
	}
}*root;
Segment_tree *build(int st, int ed)
{
	if(st == ed)
		return new Segment_tree(st, ed, 0, 0);
	return new Segment_tree(st, ed, build(st, (st + ed) >> 1), build(((st + ed) >> 1) + 1, ed));
}
void change(Segment_tree *p, int st, int ed, int v)
{
	if(p->st >= st && p->ed <= ed)
	{
		p->change(v);
		return;
	}
	p->down();
	if(p->l->ed >= st)
		change(p->l, st, ed, v);
	if(p->r->st <= ed)
		change(p->r, st, ed, v);
	p->update();
}
int query(Segment_tree *p, int st, int ed)
{
	if(p->st >= st && p->ed <= ed)
		return p->v;
	int ret = 0;
	p->down();
	if(p->l->ed >= st)
		ret += query(p->l, st, ed);
	if(p->r->st <= ed)
		ret += query(p->r, st, ed);
	return ret;
}
int querymx(Segment_tree *p)
{
	if(!p->v)
		return 1;
	if(p->st == p->ed)
		return p->st;
	if(p->r->v)
		return querymx(p->r);
	return querymx(p->l);
}
int mn[MAXN], mx[MAXN];
vector<int> vec[MAXN], vec2[MAXN];
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= q; i++)
		mn[i] = n + 1, mx[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > 0)
		{
			mn[a[i]] = min(mn[a[i]], i), mx[a[i]] = max(mx[a[i]], i);
			vec[a[i]].push_back(i);
		}
	}
	if(mx[q] == 0)
	{
		bool ok = false;
		for(int i = 1; i <= n; i++)
			if(a[i] == 0)
			{
				a[i] = q, mn[q] = mx[q] = i, ok = true;
				break;
			}
		if(!ok)
		{
			printf("NO\n");
			return 0;
		}
	}
	root = build(1, n);
	for(int i = 1; i <= q; i++)
	{
		if(mx[i] == 0)
			continue;
//		printf("%d %d %d\n", i, mn[i], mx[i]);
		if(query(root, mn[i], mx[i]) != 0)
		{
			printf("NO\n");
			return 0;
		}
		for(int j: vec[i])
			change(root, j, j, 1);
		vec2[mn[i]].push_back(i);
		vec2[mx[i] + 1].push_back(-i);
	}
	root = build(1, q);
	for(int i = 1; i <= n; i++)
	{
		for(int j: vec2[i])
		{
//			printf("%d: %d\n", i, j);
			if(j > 0)
				change(root, j, j, 1);
			else
				change(root, -j, -j, 0);
		}
		if(a[i] == 0)
			a[i] = querymx(root);
	}
	printf("YES\n");
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}