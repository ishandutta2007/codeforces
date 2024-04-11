#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101010, MAXD = 300;
int n, a[MAXN], ans[MAXN];
int visit[MAXN], vn = 0;
int b[MAXD][MAXN];
int bn[MAXD], pos[MAXD];
void getans(int v)
{
	vn++;
	int now = 0;
	int nowans = 0;
	for(int i = 1; i <= n; i++)
		if(visit[a[i]] != vn)
		{
			if(++now > v)
			{
				nowans++;
				vn++;
				now = 1;
			}
			visit[a[i]] = vn;
		}
	if(now)
		nowans++;
	ans[v] = nowans;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(visit, 0, sizeof(visit));
	int now = 1;
	while(now <= n)
	{
		getans(now);
		if(ans[now] < MAXD - 1 && ans[now] < now)
			break;
		now++;
	}
	if(++now <= n)
	{
		memset(b, 0, sizeof(b));
		memset(bn, 0, sizeof(bn));
		int tmp = 1;
		for(int i = 1; i <= n; i++)
		{
			if(!b[tmp][a[i]] && bn[tmp] == now)
			{
				pos[tmp] = i;
				tmp++;
			}
			if(!b[tmp][a[i]]++)
				bn[tmp]++;
		}
		pos[tmp] = n + 1;
		ans[now] = tmp;
		while(++now <= n)
		{
			for(int i = 1; i <= tmp; i++)
			{
				while(pos[i] <= n)
				{
					if(!b[i][a[pos[i]]] && bn[i] == now)
						break;
					if(!--b[i + 1][a[pos[i]]])
						bn[i + 1]--;
					if(!b[i][a[pos[i]++]]++)
						bn[i]++;
				}
			}
			while(tmp > 1 && pos[tmp - 1] > n)
				tmp--;
			ans[now] = tmp;
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}