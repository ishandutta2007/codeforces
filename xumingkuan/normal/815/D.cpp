#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
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
const int MAXN = 505050;
int n, p, q, r;
class Segment_tree
{
public:
	int st, ed;
	Segment_tree *l, *r;
	int mn, mncnt, mn2;
	long long sum;
	Segment_tree(int st, int ed, Segment_tree *l, Segment_tree *r): st(st), ed(ed), l(l), r(r), mn(1), mncnt(ed - st + 1), mn2(MAXN), sum(ed - st + 1) {}
	void change(int x)
	{
		if(x <= mn)
			return;
		if(x < mn2)
		{
			sum += (long long)mncnt * (x - mn);
			mn = x;
			return;
		}
		l->change(x);
		r->change(x);
		update();
	}
	void down()
	{
		l->change(mn);
		r->change(mn);
	}
	void update()
	{
		sum = l->sum + r->sum;
		if(l->mn < r->mn)
		{
			mn = l->mn, mncnt = l->mncnt;
			mn2 = min(l->mn2, r->mn);
		}
		else if(l->mn == r->mn)
		{
			mn = l->mn, mncnt = l->mncnt + r->mncnt;
			mn2 = min(l->mn2, r->mn2);
		}
		else
		{
			mn = r->mn, mncnt = r->mncnt;
			mn2 = min(l->mn, r->mn2);
		}
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
long long query(Segment_tree *p, int st, int ed)
{
	if(p->st >= st && p->ed <= ed)
		return p->sum;
	long long ret = 0;
	p->down();
	if(p->l->ed >= st)
		ret += query(p->l, st, ed);
	if(p->r->st <= ed)
		ret += query(p->r, st, ed);
	return ret;
}
class Edge
{
public:
	int to, next;
}e[MAXN];
int head[MAXN], en = 0;
void insert(int u, int v)
{
	e[++en].to = v;
	e[en].next = head[u];
	head[u] = en;
}
class Card
{
public:
	int a, b, c;
	void read(int id)
	{
		inputnum(a);
		inputnum(b);
		inputnum(c);
		insert(a, id);
	}
}a[MAXN];
long long ans = 0;
int main()
{
	inputnum(n);
	inputnum(p);
	inputnum(q);
	inputnum(r);
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; i++)
		a[i].read(i);
	root = build(1, q);
	for(int i = 1; i <= n; i++)
		change(root, 1, a[i].b, a[i].c + 1);
	int mnb = 1;
	for(int i = p; i >= 1; i--)
	{
		for(int j = head[i]; j > 0; j = e[j].next)
		{
			mnb = max(mnb, a[e[j].to].b + 1);
			change(root, 1, q, a[e[j].to].c + 1);
		}
		if(mnb > q)
			break;
		ans += (long long)(q - mnb + 1) * (r + 1) - query(root, mnb, q);
	}
	printf("%I64d\n", ans);
	return 0;
}