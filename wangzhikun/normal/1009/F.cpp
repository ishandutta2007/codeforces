#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

// RJ? No, thanks

using namespace std;

const int N = 1000043;

struct state
{
	vector<int>* a;
	int cur_max;
	int sz()
	{
		return a->size();
	}
	void add(int i, int val)
	{
		(*a)[i] += val;
		if(make_pair((*a)[i], i) > make_pair((*a)[cur_max], cur_max))
			cur_max = i;
	}
};

state pull(state z)
{
	if(z.sz() == 0)
	{
		state c;
		c.a = new vector<int>(1, 1);
		c.cur_max = 0;
		return c;
	}
	else
	{
		state c;
		c.a = z.a;
		c.cur_max = z.cur_max;
		c.a->push_back(0);
		c.add(c.sz() - 1, 1);
		return c;
	}
}

state merge(state a, state b)
{
	if(a.sz() < b.sz())
		swap(a, b);
	state c;
	c.a = a.a;
	c.cur_max = a.cur_max;
	int as = c.sz();
	int bs = b.sz();
	for(int i = 0; i < bs; i++)
		a.add(as - i - 1, (*(b.a))[bs - i - 1]);
	return a;
}

state s[N];
int ans[N];
vector<int> g[N];

void dfs(int x, int p = -1)
{
	s[x].a = new vector<int>(0);
	s[x].cur_max = 0;
	for(auto y : g[x])
		if(y != p)
		{
			dfs(y, x);
			s[x] = merge(s[x], s[y]);
		}
	s[x] = pull(s[x]);
	ans[x] = s[x].sz() - s[x].cur_max - 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	for(int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}