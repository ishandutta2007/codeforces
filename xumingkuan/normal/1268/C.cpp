#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int MAXN = 202020;
int n, p[MAXN], pos[MAXN];
set<int> s;
class Node
{
public:
	int v, h, num;
	Node *l, *r;
	Node(int v_): v(v_)
	{
		l = r = 0;
		num = 1;
		h = rand();
	}
};
Node *root;
//int n;
int zishu(Node *p)
{
	return p ? p->num : 0;
}
void update(Node *p)
{
	p->num = zishu(p->l) + zishu(p->r) + 1;
}
void right_rotate(Node *&p)
{
	Node *tmp = p->l;
	p->l = tmp->r;
	tmp->r = p;
	update(p);
	p = tmp;
}
void left_rotate(Node *&p)
{
	Node *tmp = p->r;
	p->r = tmp->l;
	tmp->l = p;
	update(p);
	p = tmp;
}
Node *insert(Node *&p, int x)
{
	if(!p)
		return p = new Node(x);
	p->num++;
	if(x <= p->v)
	{
		p->l = insert(p->l, x);
		if(p->l->h > p->h)
			right_rotate(p);
	}
	else
	{
		p->r = insert(p->r, x);
		if(p->r->h > p->h)
			left_rotate(p);
	}
	update(p);
	return p;
}
Node *merge(Node *p, Node *q)
{
	if(!p)
		return q;
	if(!q)
		return p;
	if(p->h > q->h)
	{
		p->num += q->num;
		p->r = merge(p->r, q);
		return p;
	}
	else
	{
		q->num += p->num;
		q->l = merge(p, q->l);
		return q;
	}
}
void delnum(Node *&p, int x)
{
	if(!p)
		return;
	if(p->v == x)
	{
		p = merge(p->l, p->r);
		return;
	}
	if(x < p->v)
		delnum(p->l, x);
	else
		delnum(p->r, x);
	p->num = zishu(p->l) + zishu(p->r) + 1;
}
int findsmall(Node *p, int k)
{
	if(!p)
		return -1;
	if(k == zishu(p->l) + 1)
		return p->v;
	if(k <= zishu(p->l))
		return findsmall(p->l, k);
	else
		return findsmall(p->r, k - zishu(p->l) - 1);
}
pair<int, int> findlow(Node *p, int x)
{
	if(!p)
		return make_pair(-1, 0);
	if(x > p->v)
	{
		pair<int, int> ret = findlow(p->r, x);
		ret.second += zishu(p->l) + 1;
		return ret;
	}
	else
	{
		pair<int, int> tmp = findlow(p->l, x);
		return tmp.first == -1 ? make_pair(p->v, zishu(p->l)) : tmp;
	}
}
long long ans = 0;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	insert(root, pos[1]);
	s.insert(pos[1]);
	auto ml = s.begin(), mr = s.begin();
	printf("0");
	for(int i = 2; i <= n; i++)
	{
		pair<int, int> now = findlow(root, pos[i]);
//		printf("find: %d %d\n", now.first, now.second);
		ans += i - 1 - now.second;
		insert(root, pos[i]);
		
		if(pos[i] > *mr)
			ans += pos[i] - *mr - (now.second - (i + 1) / 2) - (i - 1 - now.second) - 1;
		else if(pos[i] < *ml)
			ans += *ml - pos[i] - (i / 2 - 1 - now.second) - now.second - 1;
		else
			ans -= i / 2;
		
		s.insert(pos[i]);
		if(i % 2 == 0)
		{
			if(pos[i] > *mr)
				mr++;
			else
				ml--;
		}
		else
		{
			if(pos[i] > *mr)
				ml++;
			else if(pos[i] < *ml)
				mr--;
			else
			{
				ml++;
				mr--;
			}
		}
		printf(" %I64d", ans);
	}
	return 0;
}