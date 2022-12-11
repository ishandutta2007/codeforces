#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool color[200005];
int cnt[200005];
vector<int> tree[200005];
int parent[200005];

vector<int> path;

void dfs(int s)
{
	cnt[s] = !color[s];
	for (int next : tree[s])
	{
		if (next == parent[s]) continue;
		parent[next] = s;
		dfs(next);
		cnt[s] += cnt[next];
	}
}

void dfs2(int s)
{
	for (int next : tree[s])
	{
		if (next == parent[s]) continue;
		if (cnt[next]==0) continue;
		color[next] ^= 1;
		path.push_back(next);
		dfs2(next);
		color[s] ^= 1;
		path.push_back(s);

		if (color[next]==false)
		{
			path.push_back(next);
			color[s] ^= 1;
			path.push_back(s);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);

	bool all = true;
	for (int i = 0; i < n; i++)
	{
		int tmp; scanf("%d",&tmp);
		if (tmp == 1) color[i] = true;
		else all = false;
	}

	if (all)
	{
		printf("1");
		return 0;
	}

	for (int i = 1; i < n; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b); a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(0);
	dfs2(0);
	printf("1 ");
	for (int t : path) printf("%d ", t + 1);
	if (color[0]==false)
	{
		printf("%d 1 %d", tree[0][0] + 1, tree[0][0] + 1);
	}
}