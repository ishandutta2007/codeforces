#include <bits/stdc++.h>
using namespace std;

constexpr unsigned P1 = 1000003, P2 = 1000033;
constexpr unsigned M1 = 1000000007, M2 = 1000000009;

int n;
vector<int> graph[100005];
unsigned long long hashes[100005];
map<unsigned long long, int> hcnt;
int cnt[100005];
int cent;

void cdfs(int t, int p)
{
	cnt[t] = 1;
	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		cdfs(nxt, t);
		cnt[t] += cnt[nxt];
	}

	for (int nxt : graph[t])
	{
		if (cnt[nxt] >= (n + 1) / 2) return;
	}

	if (cnt[t] >= (n + 1) / 2) cent = t;
}

void dfs1(int t, int p)
{
	unsigned h1 = 1, h2 = 1;

	vector<unsigned> child1, child2;

	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		dfs1(nxt, t);
		child1.push_back(hashes[nxt] >> 32);
		child2.push_back(hashes[nxt]);
	}

	sort(child1.begin(), child1.end());
	sort(child2.begin(), child2.end());

	for (int i = 0; i < child1.size(); i++)
	{
		h1 = (h1 * 1ull * P1 + child1[i] * (i + 1ull)) % M1;
		h2 = (h2 * 1ull * P2 + child2[i] * 1ull * (child1.size() - i)) % M2;
	}

	hashes[t] = (unsigned long long)h1 << 32 | h2;
	hcnt[hashes[t]]++;
}

int ans1, ans2;

void dfs2(int t, int p, int d)
{
	if (ans2 < d)
	{
		ans2 = d;
		ans1 = t;
	}

	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		if (hcnt[hashes[nxt]] >= 2) dfs2(nxt, t, d + 1);
		else dfs2(nxt, t, d);
	}
}

int main()
{
	scanf("%d", &n);
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cdfs(1, -1);
	dfs1(cent, -1);
	dfs2(cent, -1, 1);

	printf("%d\n", ans1);
}