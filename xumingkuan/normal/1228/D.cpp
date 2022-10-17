#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int MAXN = 101010;
int n, m;
class Edge
{
public:
	int to, next;
}e[MAXN * 6];
int head[MAXN], en = 1;
//set<int> e2[MAXN];
void insert()
{
	int u, v;
	scanf("%d%d", &u, &v);
	e[++en].to = v;
	e[en].next = head[u];
	head[u] = en;
	e[++en].to = u;
	e[en].next = head[v];
	head[v] = en;
//	e2[u].insert(v);
//	e2[v].insert(u);
}
set<int> s;
int ans[MAXN];
int cnt[10];
int main()
{
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= m; i++)
		insert();
	if(head[1] == -1)
	{
		printf("-1\n");
		return 0;
	}
	int x = e[head[1]].to; // 1, x, y
	int y = -1;
	for(int i = head[x]; i > 0; i = e[i].next)
		s.insert(e[i].to);
	for(int i = e[head[1]].next; i > 0; i = e[i].next)
	{
		if(s.find(e[i].to) != s.end())
		{
			y = e[i].to;
			break;
		}
	}
	if(y == -1)
	{
		printf("-1\n");
		return 0;
	}
	memset(ans, 0, sizeof(ans));
	for(int i = head[1]; i > 0; i = e[i].next)
		ans[e[i].to] |= 1;
	for(int i = head[x]; i > 0; i = e[i].next)
		ans[e[i].to] |= 2;
	for(int i = head[y]; i > 0; i = e[i].next)
		ans[e[i].to] |= 4;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
	{
		if(ans[i] != 3 && ans[i] != 5 && ans[i] != 6)
		{
			printf("-1\n");
			return 0;
		}
		cnt[ans[i]]++;
		for(int j = head[i]; j > 0; j = e[j].next)
			if(ans[i] == ans[e[j].to])
			{
				printf("-1\n");
				return 0;
			}
	}
	if(!cnt[3] || !cnt[5] || !cnt[6] || (long long)cnt[3] * cnt[5] + (long long)cnt[5] * cnt[6] + (long long)cnt[6] * cnt[3] != m)
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i] / 2);
	return 0;
}