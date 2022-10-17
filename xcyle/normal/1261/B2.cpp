#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define maxn 200005
using namespace std;
int n, m, T, a[maxn], tmp[maxn];
struct node
{
	int pos, id;
}temp;
vector<int> b[maxn];
vector<node> q[maxn];
int ans[maxn];
int t[maxn];
void add(int x, int data)
{
	for (; x <= n; x += (x & (-x)))
	{
		t[x] += data;
	}
}
int que(int x)
{
	int now = 0;
	for (int i = 20; i >= 0; i--)
	{
		if(now + (1 << i) > n || t[now + (1 << i)] >= x) continue;
		now += (1 << i); 
		x -= t[now];
	}
	return now + 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		tmp[i] = a[i];
	}
	sort(tmp + 1, tmp + n + 1);
	int len = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= n; i++) 
	{
		a[i] = lower_bound(tmp + 1, tmp + len + 1, a[i]) - tmp;
		b[a[i]].push_back(i);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &T, &temp.pos);
		temp.id = i;
		q[T].push_back(temp);
	}
	int now = 0;
	for (int i = len; i >= 1; i--)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			now++;
			add(b[i][j], 1);
			for (int k = 0; k < q[now].size(); k++)
			{
				ans[q[now][k].id] = que(q[now][k].pos);
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
//		printf("%d\n", ans[i]);
		printf("%d\n", tmp[a[ans[i]]]);
	}
	return 0;
}