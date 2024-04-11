#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100005
#define M 2000005
#define inf 0x3f3f3f3f
int A[M], B[M], C[M];
int n, m, dis[N], now[N];
int tar[M], cap[M], nex[M], fir[N], cnt = 1;
void Read(int &p)
{
	p = 0;
	int f = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar())f |= (c == '0');
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
	if (f)p = -p;
}
void add(int a, int b, int c)
{
	++cnt;
	tar[cnt] = b;
	cap[cnt] = c;
	nex[cnt] = fir[a];
	fir[a] = cnt;
}
void Add(int a, int b, int c){add(a, b, c), add(b, a, 0);}
int Bfs(int s, int t)
{
	for (int i = 1; i <= 2 * n + 2; i++)
		dis[i] = inf, now[i] = fir[i];
	queue<int>q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = fir[x]; i; i = nex[i])
		{
			int v = tar[i];
			if (cap[i] && dis[v] == inf)
			{
				q.push(v);
				dis[v] = dis[x] + 1;
				if (v == t)
					return 1;
			}
		}
	}
	return 0;
}
int Dfs(int x, int t, int sum)
{
	if (x == t)
		return sum;
	int k, res = 0;
	for (int &i = now[x]; i && sum; i = nex[i])
	{
		int v = tar[i];
		if (cap[i] && dis[v] == dis[x] + 1)
		{
			k = Dfs(v, t, min(sum, cap[i]));
			if (!k)
				dis[v] = inf;
			cap[i] -= k;
			cap[i ^ 1] += k;
			res += k, sum -= k;
		}
	}
	return res;
}
int Flow(int s, int t, int g)
{
	int ans = 0;
	while (Bfs(s, t))
		ans += Dfs(s, t, inf);
	return ans;
}
bool Check(int x)
{
	cnt = 1;
	for (int i = 1; i <= 2 * n + 2; i++)
		fir[i] = 0;
	for (int i = 1; i <= n; i++)
		Add(2 * n + 1, i, 1), Add(i + n, 2 * n + 2, 1);
	for (int i = 1; i <= m; i++)
		if (C[i] <= x)
			Add(A[i], B[i] + n, 1);
	return Flow(2 * n + 1, 2 * n + 2, 2 * n + 2) == n;
}
int main()
{
	Read(n), Read(m);
	int mx = 0;
	for (int i = 1; i <= m; i++)
	{
		Read(A[i]), Read(B[i]), Read(C[i]);
		mx = max(mx, C[i]);
	}
	int l = 1, r = mx + 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (Check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	if (l == mx + 1)
		puts("-1");
	else
		printf("%d\n", l);
}