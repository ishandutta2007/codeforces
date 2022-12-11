#include <bits/stdc++.h>
using namespace std;

bool special[1005];
bool edge[1005][1005];
bool prime[1005];
int parent[1005];
int gsize[1005];
int getparent(int t)
{
	return t == parent[t] ? t : (parent[t] = getparent(parent[t]));
}

void merge(int a, int b)
{
	a = getparent(a);
	b = getparent(b);
	if (a == b) return;
	parent[a] = b;
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		special[tmp] = true;
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a][b] = edge[b][a] = true;
		merge(a, b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (special[i]) prime[getparent(i)] = true;
		gsize[getparent(i)]++;
	}

	vector<int> a;
	int b = 0;

	for (int i = 1; i <= n; i++)
	{
		if (getparent(i) != i) continue;
		if (prime[i]) a.push_back(gsize[i]);
		else b += gsize[i];
	}

	sort(a.begin(), a.end());
	a.back() += b;

	int ans = 0;
	for (int t : a) ans += t * (t - 1) / 2;

	printf("%d", ans - m);
}