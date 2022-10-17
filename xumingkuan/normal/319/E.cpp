#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100010, MAXP = 262144, MAXS = 462200;
vector <int> a[MAXS];
int n, fa[MAXN], le[MAXN], ri[MAXN], num = 0;
int getanc(int x)
{
	return fa[x] == x ? x : fa[x] = getanc(fa[x]);
}
void merge(int x, int p)
{
	for(x += MAXP; x; x >>= 1)
		while(!a[x].empty())
		{
			const int now = a[x].back();
			a[x].pop_back();
			le[p] = min(le[p], le[now]);
			ri[p] = max(ri[p], ri[now]);
			fa[now] = p;
		}
}
void insert(int l, int r, int p)
{
	for(l += MAXP, r += MAXP; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if(~l & 1)
			a[l ^ 1].push_back(p);
		if(r & 1)
			a[r ^ 1].push_back(p);
	}
}
pair <int, int> numbers[MAXN * 2];
int number = 0;
class Query
{
	public:
		int type, x, y;
		void read()
		{
			scanf("%d%d%d", &type, &x, &y);
		}
}qry[MAXN];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		qry[i].read();
		if(qry[i].type == 1)
		{
			numbers[++number] = make_pair(qry[i].x, i);
			numbers[++number] = make_pair(qry[i].y, i);
		}
	}
	sort(numbers + 1, numbers + number + 1);
	int tmp = 0;
	numbers[0].first = numbers[1].first - 1;
	for(int i = 1; i <= number; i++)
	{
		if(numbers[i].first != numbers[i - 1].first)
			tmp++;
		if(numbers[i].first == qry[numbers[i].second].x)
			qry[numbers[i].second].x = tmp;
		else
			qry[numbers[i].second].y = tmp;
	}
	for(int i = 1; i <= n; i++)
	{
		int x = qry[i].x, y = qry[i].y;
		if(qry[i].type & 1)
		{
			num++;
			fa[num] = num;
			le[num] = x, ri[num] = y;
			merge(x, num);
			merge(y, num);
			insert(le[num], ri[num], num);
		}
		else
		{
			x = getanc(x);
			y = getanc(y);
			if(le[x] >= le[y] && ri[x] <= ri[y])
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}