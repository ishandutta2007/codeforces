#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 303030;
int n, N;
class Edge
{
public:
	int to, next;
}e[MAXN * 2];
int head[MAXN], en = 1;
int deg[MAXN], depth[MAXN];
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
	deg[u]++;
	deg[v]++;
}
void gg()
{
	printf("0\n");
	exit(0);
}
int cntn[20];
void solve1(int p)
{
	for(int i = 1; i <= N; i++)
		if(deg[i] == 1)
		{
			depth[i] = 1;
			if(e[head[i]].to != p)
				depth[e[head[i]].to] = 2;
			else
				depth[e[head[i]].to] = 3;
		}
	for(int d = 2; d < n; d++)
		for(int i = 1; i <= N; i++)
			if(depth[i] == d)
			{
//				printf("%d: %d\n", i, d);
				int cnt1 = 0, cnt2 = 0, cntp = 0;
				for(int j = head[i]; j > 0; j = e[j].next)
					if(depth[e[j].to])
					{
						if(depth[e[j].to] == d - 1)
							cnt1++;
						else if(depth[e[j].to] == d - 2)
							cnt2++;
						else if(depth[e[j].to] == d + 1)
							cntp++;
						else if(depth[e[j].to] == d + 2 && e[j].to == p)
							cntp++;
						else
						{
//							printf("b %d\n", i);
							gg();
						}
					}
					else
					{
						cntp++;
						if(e[j].to == p)
							depth[e[j].to] = d + 2;
						else
							depth[e[j].to] = d + 1;
//						printf("%d: %d\n", e[j].to, depth[e[j].to]);
					}
				if(!((i == p && cnt1 == 1 && cnt2 == 2 && cntp == 1) || (i != p && cnt1 == 2 && cnt2 == 0 && cntp == 1)))
				{
//					printf("a %d\n", i);
					gg();
				}
			}
	for(int i = 1; i <= N; i++)
	{
		if(!depth[i])
			gg();
		cntn[depth[i]]++;
	}
	cntn[depth[p] - 1]++;
	for(int i = 1; i <= n; i++)
		if(cntn[i] != (1 << (n - i)))
			gg();
	printf("1\n%d\n", p);
}
bool solve2()
{
	int p = -1;
	for(int i = 1; i <= N; i++)
		if(deg[i] == 1)
		{
			depth[i] = 1;
			depth[e[head[i]].to] = 2;
			if(deg[e[head[i]].to] == 2)
			{
				if(p != -1)
					gg();
				p = e[head[i]].to;
			}
		}
	if(p == -1)
		return false;
	for(int d = 2; d < n; d++)
		for(int i = 1; i <= N; i++)
			if(depth[i] == d)
			{
				int cnt1 = 0, cntp = 0;
				for(int j = head[i]; j > 0; j = e[j].next)
					if(depth[e[j].to])
					{
						if(depth[e[j].to] == d - 1)
							cnt1++;
						else if(depth[e[j].to] == d + 1)
							cntp++;
						else
							gg();
					}
					else
					{
						cntp++;
						depth[e[j].to] = d + 1;
					}
				if(!((i == p && cnt1 == 1 && cntp == 1) || (i != p && cnt1 == 2 && cntp == 1)))
					gg();
			}
	for(int i = 1; i <= N; i++)
	{
		if(!depth[i])
			gg();
		cntn[depth[i]]++;
	}
	cntn[depth[p] - 1]++;
	for(int i = 1; i <= n; i++)
		if(cntn[i] != (1 << (n - i)))
			gg();
	printf("1\n%d\n", p);
	return true;
}
void solve3()
{
	for(int d = 2; d < n - 1; d++)
		for(int i = 1; i <= N; i++)
			if(depth[i] == d)
			{
				int cnt1 = 0, cntp = 0;
				for(int j = head[i]; j > 0; j = e[j].next)
					if(depth[e[j].to])
					{
						if(depth[e[j].to] == d - 1)
							cnt1++;
						else if(depth[e[j].to] == d + 1)
							cntp++;
						else
							gg();
					}
					else
					{
						cntp++;
						depth[e[j].to] = d + 1;
					}
				if(!(cnt1 == 2 && cntp == 1))
					gg();
			}
	int p[2] = {-1, -1};
	for(int i = 1; i <= N; i++)
		if(depth[i] == n - 1)
		{
			if(p[0] == -1)
				p[0] = i;
			else if(p[1] == -1)
				p[1] = i;
			else
				gg();
			if(deg[i] != 3)
				gg();
		}
	if(p[1] == -1)
		gg();
	bool ok = false;
	for(int i = head[p[0]]; i > 0; i = e[i].next)
		if(e[i].to == p[1])
			ok = true;
	if(!ok)
		gg();
	for(int i = 1; i <= N; i++)
	{
		if(!depth[i])
			gg();
		cntn[depth[i]]++;
	}
	for(int i = 1; i < n; i++)
		if(cntn[i] != (1 << (n - i)))
			gg();
	printf("2\n%d %d\n", p[0], p[1]);
}
//bool check3()
//{
//	if(n != 3)
//		return false;
//	int p[2] = {-1, -1};
//	for(int i = 1; i <= N; i++)
//		if(deg[i] == 3)
//		{
//			if(p[0] == -1)
//				p[0] = i;
//			else if(p[1] == -1)
//				p[1] = i;
//			else
//				return false;
//		}
//		else if(deg[i] != 1)
//			return false;
//	if(p[1] == -1)
//		return false;
//	printf("2\n%d %d\n", p[0], p[1]);
//	return true;
//}
int main()
{
//	freopen("F.in", "r", stdin);
	scanf("%d", &n);
	N = (1 << n) - 2;
	memset(head, -1, sizeof(head));
	memset(deg, 0, sizeof(deg));
	for(int i = 1; i < N; i++)
		insert();
	memset(depth, 0, sizeof(depth));
	memset(cntn, 0, sizeof(cntn));
	for(int i = 1; i <= N; i++)
		if(deg[i] < 1 || deg[i] > 4)
			gg();
//		else if(deg[i] == 1)
//			depth[i] = 1;
	if(n == 2)
	{
		printf("2\n1 2\n");
		return 0;
	}
	for(int i = 1; i <= N; i++)
		if(deg[i] == 4)
		{
			solve1(i);
			return 0;
		}
	if(solve2())
		return 0;
	solve3();
	return 0;
}