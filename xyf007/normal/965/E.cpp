#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int n, trie[100001][26], dep[100001], tot, ans;
bool f[100001];
priority_queue<int> a[100001];
void insert(string s)
{
	int root = 0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		int id = s[i] - 'a';
		if (!trie[root][id])
		{
			trie[root][id] = ++tot;
			dep[tot] = dep[root] + 1;
		}
		root = trie[root][id];
	}
	f[root] = 1;
}
void merge_heap(int x, int y)
{
	if (a[x].size() < a[y].size())
	{
		a[x].swap(a[y]);
	}
	while (!a[y].empty())
	{
		a[x].push(a[y].top());
		a[y].pop();
	}
}
void dfs(int u)
{
	for (int i = 0; i < 26; i++)
	{
		if (trie[u][i])
		{
			dfs(trie[u][i]);
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (trie[u][i])
		{
			merge_heap(u, trie[u][i]);
		}
	}
	if (!u)
	{
		return;
	}
	if (f[u])
	{
		ans += dep[u];
		a[u].push(dep[u]);
		return;
	}
	ans -= a[u].top() - dep[u];
	a[u].pop();
	a[u].push(dep[u]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		insert(s);
	}
	dfs(0);
	printf("%d", ans);
	return 0;
}//