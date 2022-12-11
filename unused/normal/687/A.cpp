#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> group[100005];
int parent[100005];
bool color[100005];

int getparent(int a)
{
	return a == parent[a] ? a : parent[a] = getparent(parent[a]);
}

bool merge(int a, int b)
{
	int pa = getparent(a);
	int pb = getparent(b);

	if (pa == pb)
	{
		return (color[a] != color[b]);
	}

	if (group[pa].size() < group[pb].size())
		swap(pa, pb);

	parent[pb] = pa;

	if (color[a] == color[b])
	{
		for (int t : group[pb])
		{
			color[t] ^= true;
		}
	}

	group[pa].insert(group[pa].end(), group[pb].begin(), group[pb].end());
	vector<int>().swap(group[pb]);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		group[i].push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (merge(a, b)==false) {
			printf("-1"); return 0;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) if (color[i]) cnt++;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) if (color[i]) printf("%d ", i);
	printf("\n%d\n", n - cnt);
	for (int i = 1; i <= n; i++) if (!color[i]) printf("%d ", i);
}