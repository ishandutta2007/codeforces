#include <bits/stdc++.h>
using namespace std;

#pragma warning(error: 4715)

list<int> group[100005];
int parent[100005];
bool color[100005];
unordered_map<string, int> mp;

bool merge(int a, int b, bool same)
{
	int pa = parent[a];
	int pb = parent[b];

	if (pa == pb)
	{
		if ((color[a] == color[b]) != same)
		{
			return false;
		}
		return true;
	}

	if (group[pa].size() < group[pb].size())
	{
		swap(pa, pb);
		swap(a, b);
	}

	bool flip = ((color[a] == color[b]) != same);

	for (int i : group[pb])
	{
		parent[i] = pa;
		color[i] ^= flip;
	}
	group[pa].splice(group[pa].begin(), group[pb]);

	return true;
}

int main()
{
	cin.sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		group[i].push_back(i);
		string str;
		cin >> str;
		mp[move(str)] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int q; string s1, s2;
		cin >> q >> s1 >> s2;
		int idx1 = mp[s1], idx2 = mp[s2];

		if (merge(idx1, idx2, q == 1))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	for (int i = 0; i < q; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;

		int idx1 = mp[s1], idx2 = mp[s2];

		if (parent[idx1] != parent[idx2]) printf("3\n");
		else if (color[idx1] == color[idx2]) printf("1\n");
		else printf("2\n");
	}
}