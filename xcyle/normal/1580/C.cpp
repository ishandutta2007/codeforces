#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, x[maxn], y[maxn];
int beg[maxn];
int tmp[505][505];
int cf[maxn];
int main()
{ 
//	freopen("data.in", "r", stdin);
//	freopen("std.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		int op, k;
		scanf("%d%d", &op, &k);
		if(op == 1)
		{
			beg[k] = i;
			if(x[k] + y[k] <= 500) 
			{
				int l = (i + x[k]) % (x[k] + y[k]);
				int r = (i + x[k] + y[k] - 1) % (x[k] + y[k]);
				if(l > r)
				{
					for (int j = l; j < x[k] + y[k]; j++)
					{
						tmp[x[k] + y[k]][j]++;
					}
					for (int j = 0; j <= r; j++)
					{
						tmp[x[k] + y[k]][j]++;
					}
				}
				else 
				{
					for (int j = l; j <= r; j++)
					{
						tmp[x[k] + y[k]][j]++;
					}
				}
			}
			else
			{
				for (int now = i + x[k]; now <= m; now += x[k] + y[k])
				{
					cf[now]++;
					cf[min(m + 1, now + y[k])]--;
				}
			}
		}
		else
		{
			if(x[k] + y[k] <= 500) 
			{
				int l = (beg[k] + x[k]) % (x[k] + y[k]);
				int r = (beg[k] + x[k] + y[k] - 1) % (x[k] + y[k]);
				if(l > r)
				{
					for (int j = l; j < x[k] + y[k]; j++)
					{
						tmp[x[k] + y[k]][j]--;
					}
					for (int j = 0; j <= r; j++)
					{
						tmp[x[k] + y[k]][j]--;
					}
				}
				else 
				{
					for (int j = l; j <= r; j++)
					{
						tmp[x[k] + y[k]][j]--;
					}
				}
			}
			else
			{
				for (int now = beg[k] + x[k]; now <= m; now += x[k] + y[k])
				{
					cf[now]--;
					cf[min(m + 1, now + y[k])]++;
					if(now < i) sum--;
					if(min(m + 1, now + y[k]) < i) sum++;
				}
			}
		}
		sum += cf[i];
		int cnt = 0;
		for (int j = 1; j <= 500; j++)
		{
			cnt += tmp[j][i % j];
//			if(tmp[j][i % j]) printf("!!! %d %d\n", j, tmp[j][i % j]);
		}
		printf("%d\n", cnt + sum);
	}
	return 0;
}