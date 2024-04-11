#include <stdio.h>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int parent[200005];
int cidx[200005];
vector<pair<int, int>> edge;
vector<pair<int, int>> used;

int getparent(int t)
{
	return t != parent[t] ? parent[t] = getparent(parent[t]) : t;
}

bool merge(int a, int b)
{
	int pa = getparent(a), pb = getparent(b);
	if (pa == pb) return false;
	parent[pa] = pb;
	return true;
}

vector<int> center;
vector<pair<int, int>> eidx;
bool direct;

bool edgecomp(int s1, int e1, int s2, int e2)
{
	return min(s1, e1) == min(s2, e2) &&
		max(s1, e1) == max(s2, e2);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a,&b);
		edge.emplace_back(a, b);
	}

	int s, t, ds, dt;
	scanf("%d%d%d%d", &s, &t, &ds, &dt);

	for (int i = 0; i < edge.size(); i++)
	{
		if (edge[i].first == s || edge[i].first == t ||
			edge[i].second == s || edge[i].second == t) continue;

		if (merge(edge[i].first, edge[i].second))
		{
			used.push_back(edge[i]);
			swap(edge[i], edge.back());
			edge.pop_back();
			i--;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i == s || i == t) continue;
		if (i == getparent(i))
		{
			cidx[i] = center.size();
			center.push_back(i);
		}
	}

	eidx.resize(center.size(), { -1, -1 });

	for (int i = 0; i < edge.size(); i++)
	{
		if (edgecomp(edge[i].first, edge[i].second, s, t))
		{
			direct = true;
			continue;
		}
		if (edge[i].first == s || edge[i].second == s)
		{
			int x = edge[i].first + edge[i].second - s;
			eidx[cidx[getparent(x)]].first = i;
		}
		else if (edge[i].second == t || edge[i].first == t)
		{
			int x = edge[i].first + edge[i].second - t;
			eidx[cidx[getparent(x)]].second = i;
		}
	}

	int conn = -1;

	for (int i = 0; i < center.size(); i++)
	{
		if (eidx[i].first == -1 && eidx[i].second == -1)
		{
			printf("No");
			return 0;
		}

		if (eidx[i].first == -1)
		{
			used.push_back(edge[eidx[i].second]);
			if (--dt < 0)
			{
				printf("No");
				return 0;
			}
		}
		else if (eidx[i].second == -1)
		{
			used.push_back(edge[eidx[i].first]);
			if (--ds < 0)
			{
				printf("No");
				return 0;
			}
		}
		else if (conn == -1)
		{
			used.push_back(edge[eidx[i].first]);
			used.push_back(edge[eidx[i].second]);
			if (--dt < 0 || --ds < 0)
			{
				printf("No");
				return 0;
			}
			conn = i;
		}
	}

	if (conn == -1)
	{
		used.emplace_back(s, t);
		if (direct == false || --dt < 0 || --ds < 0)
		{
			printf("No");
			return 0;
		}
	}

	for (int i = 0; i < center.size(); i++)
	{
		if (eidx[i].first == -1 || eidx[i].second == -1 || i == conn) continue;
		if (ds > 0)
		{
			used.push_back(edge[eidx[i].first]);
			ds--;
		}
		else if (dt > 0)
		{
			used.push_back(edge[eidx[i].second]);
			dt--;
		}
		else
		{
			printf("No");
			return 0;
		}
	}

	printf("Yes\n");
	for (int i = 0; i < used.size(); i++)
	{
		printf("%d %d\n", used[i].first, used[i].second);
	}
}