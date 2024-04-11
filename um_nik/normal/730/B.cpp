#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int query(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char c;
	scanf(" %c", &c);
	if (c == '=') return 0;
	if (c == '<') return -1;
	if (c == '>') return 1;
	throw;
}

void solve()
{
	int n;
	scanf("%d", &n);
	vector<int> a, b, c;
	for (int i = 1; i <= n; i++)
		a.push_back(i);
	while(a.size() > 1)
	{
		int x = a.back();
		a.pop_back();
		int y = a.back();
		a.pop_back();
		int z = query(x, y);
		if (z == 0)
			a.push_back(x);
		else
		{
			if (z > 0) swap(x, y);
			b.push_back(x);
			c.push_back(y);
		}
	}
	if (!a.empty())
	{
		b.push_back(a.back());
		c.push_back(a.back());
	}
	while(b.size() > 1)
	{
		int x = b.back();
		b.pop_back();
		int y = b.back();
		b.pop_back();
		int z = query(x, y);
		if (z > 0)
			b.push_back(y);
		else
			b.push_back(x);
	}
	while(c.size() > 1)
	{
		int x = c.back();
		c.pop_back();
		int y = c.back();
		c.pop_back();
		int z = query(x, y);
		if (z < 0)
			c.push_back(y);
		else
			c.push_back(x);
	}
	printf("! %d %d\n", b.back(), c.back());
	fflush(stdout);
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();

	return 0;
}