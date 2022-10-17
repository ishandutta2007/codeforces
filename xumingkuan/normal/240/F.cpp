#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXN 101010
int n, m;
char s[MAXN];
class Count
{
	public:
		int a[26];
		inline int &operator [](int pos)
		{
			return a[pos];
		}
		inline const int operator [](int pos) const
		{
			return a[pos];
		}
		inline void clear()
		{
			memset(a, 0, sizeof(a));
		}
		Count(){}
		Count(int pos, int v)
		{
			clear();
			a[pos] = v;
		}
		inline Count operator +(const Count &b) const
		{
			Count ret;
			for(int i = 0; i < 26; i++)
				ret[i] = a[i] + b[i];
			return ret;
		}
		inline Count &operator +=(const Count &b)
		{
			for(int i = 0; i < 26; i++)
				a[i] += b[i];
			return *this;
		}
};
class Segment_tree
{
	public:
		Count a;
		int st, ed, len, lazy;
		Segment_tree *l, *r;
		inline void update()
		{
			if(!l)
				return;
			a = l->a + r->a;
		}
		inline void change(int v)
		{
			lazy = v;
			a.clear();
			a[v] = len;
		}
		inline void down()
		{
			if(lazy == -1 || !l)
				return;
			l->change(lazy);
			r->change(lazy);
			lazy = -1;
		}
		Segment_tree(int st, int ed, Segment_tree *l, Segment_tree *r): st(st), ed(ed), l(l), r(r)
		{
			if(st == ed)
			{
				a.clear();
				a[s[st] - 'a'] = 1;
			}
			else
				update();
			lazy = -1;
			len = ed - st + 1;
		}
};
Segment_tree *root;
Segment_tree *build(int st, int ed)
{
	if(st == ed)
		return new Segment_tree(st, ed, 0, 0);
	Segment_tree *x = build(st, (st + ed) >> 1);
	Segment_tree *y = build(((st + ed) >> 1) + 1, ed);
	return new Segment_tree(st, ed, x, y);
}
Count now;
Count query(Segment_tree *p, int st, int ed)
{
	//printf("query %d %d\n", p->st, p->ed);
	if(p->st >= st && p->ed <= ed)
		return p->a;
	if(p->lazy != -1)
		return Count(p->lazy, min(ed, p->ed) - max(st, p->st) + 1);
	//p->down();
	if(p->l->ed >= st)
		if(p->r->st <= ed)
			return query(p->l, st, ed) + query(p->r, st, ed);
		else
			return query(p->l, st, ed);
	else	
		return query(p->r, st, ed);
}
void change(Segment_tree *p, int st, int ed, int v)
{
	//printf("change %d %d %d %d %d\n", p->st, p->ed, st, ed, v);
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
void print(Segment_tree *p)
{
	if(p->st == p->ed)
	{
		for(int i = 0; i < 26; i++)
			if(p->a[i])
			{
				printf("%c", i + 'a');
				break;
			}
		return;
	}
	p->down();
	print(p->l);
	print(p->r);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	int x, y;
	root = build(1, n);
	for(int i = 1; i <= m; i++)
	{
		//printf("%d\n", i);
		scanf("%d%d", &x, &y);
		now = query(root, x, y);
		//for(int j = 0; j < 26; j++)
		//	printf("%d %d\n", j, now[j]);
		int tmp = -1;
		for(int j = 0; j < 26; j++)
			if(now[j] & 1)
			{
				if(tmp == -1)
					tmp = j;
				else
				{
					tmp = -2;
					break;
				}
			}
		if(tmp == -2)
			continue;
		for(int j = 0; j < 26; j++)
			if(y = (now[j] >> 1))
			{
				change(root, x, x + y - 1, j);
				x += y;
			}
		if(tmp >= 0)
		{
			change(root, x, x, tmp);
			x++;
		}
		for(int j = 25; j >= 0; j--)
			if(y = (now[j] >> 1))
			{
				change(root, x, x + y - 1, j);
				x += y;
			}
	}
	print(root);
	return 0;
}