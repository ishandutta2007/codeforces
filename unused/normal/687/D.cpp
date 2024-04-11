#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1005];
vector<int> group[1005];
bool color[1005];

bool merge(int a,int b)
{
	int pa = parent[a];
	int pb = parent[b];
	if (pa == pb) return color[a] ^ color[b];
	if (group[pb].size()>group[pa].size()) { swap(pa, pb); }
	bool flip = color[a] == color[b];
	for (int elem : group[pb])
	{
		parent[elem]=pa;
		if (flip) color[elem] ^= true;
	}
	group[pa].insert(group[pa].end(),group[pb].begin(),group[pb].end());
	return true;
}

struct edge
{
	int s,e,v,idx;
	bool operator<(const edge &rhs) const
	{
		return v > rhs.v;
	}
};

edge dat[500005];

int main()
{
	int n, m, q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&dat[i].s,&dat[i].e,&dat[i].v);
		dat[i].idx = i + 1;
	}
	sort(dat, dat + m);

	while (q--)
	{
		int s, e;
		scanf("%d%d",&s,&e);
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			group[i].clear();
			group[i].push_back(i);
		}

		int ans = -1;
		for (int i = 0; i < m; i++)
		{
			if (dat[i].idx < s || dat[i].idx > e) continue;
			if (merge(dat[i].s, dat[i].e) == false)
			{
				ans = dat[i].v;
				break;
			}
		}
		printf("%d\n", ans);
	}
}