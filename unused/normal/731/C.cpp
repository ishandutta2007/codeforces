#include "bits/stdc++.h"
using namespace std;

int cnow[200005];
vector<int> initial[200005];
int parent[200005];
list<int> group[200005];

int getp(int t)
{
	return t==parent[t] ? t : (parent[t] = getp(parent[t]));
}

void merge(int a, int b)
{
	int pa = getp(a);
	int pb = getp(b);
	if (pa == pb) return;

	parent[pb] = pa;
	group[pa].splice(group[pa].end(), group[pb]);
}

int main()
{
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&cnow[i]);
		parent[i] = i;
		group[i].push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a; --b;
		merge(a, b);
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (i != getp(i)) continue;
		unordered_map<int,int> cnt;
		for (int j : group[i])
		{
			cnt[cnow[j]]++;
		}

		int maxval = 0;
		for (auto &&e : cnt) maxval = max(maxval, e.second);

		ans += group[i].size() - maxval;
	}

	printf("%d", ans);
}