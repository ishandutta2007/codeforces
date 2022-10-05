#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, m, maxi[Maxn][2];
struct edg
{
	int u, v, l, r;
	bool operator < (const edg &tmp) const
	{
		return l > tmp.l;
	}
};
vector <edg> Ve[Maxn][2];
priority_queue <edg> Pr;
void bfs(edg now)
{
	bool s = now.l & 1;
	if (maxi[now.u][s] >= now.l)
	{
		if (now.v == n)
		{
			printf("%d", now.l + 1);
			exit(0);
		}
		if (maxi[now.v][!s] < now.r + 1)
		{
			maxi[now.v][!s] = now.r + 1;
			for (auto e : Ve[now.v][!s])
				Pr.push((edg){e.u, e.v, now.l + 1, e.r});
			Ve[now.v][!s].clear();
		}
	}
	else Ve[now.u][s].push_back(now);
}
int main()
{
	scanf("%d%d", &n, &m);
	if (n == 1)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, l, r;
		scanf("%d%d%d%d", &u, &v, &l, &r);
		r--;
		int s = (r - l) & 1;
		Pr.push((edg){u, v, l, r - s});
		Pr.push((edg){v, u, l, r - s});
		Pr.push((edg){u, v, l + 1, r - !s});
		Pr.push((edg){v, u, l + 1, r - !s});
	}
	memset(maxi, -0x3f, sizeof(maxi));
	maxi[1][0] = 0;
	while (!Pr.empty())
	{
		edg u = Pr.top();
		Pr.pop();
		if (u.l > u.r) continue;
		bfs(u);
	}
	puts("-1");
	return 0;
}