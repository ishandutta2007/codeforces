#include "bits/stdc++.h"
using namespace std;

int centroid;
vector<int> cents;
int childcnt[400005];
vector<int> graph[400005];
bool yes[400005];
int n;

void cdfs(int t, int p)
{
	childcnt[t] = 1;
	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		cdfs(nxt, t);
		childcnt[t] += childcnt[nxt];
	}
}

void dfs(int t, int p)
{
	if (n - childcnt[t] > n / 2) return;

	bool wrong = false;
	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		dfs(nxt, t);
		if (childcnt[nxt] > n / 2)
		{
			wrong = true;
		}
	}
	if (wrong == false) cents.push_back(t);
}

void adfs(int t, int p, int cut)
{
	if (n - childcnt[t] - cut <= n / 2)
	{
		yes[t] = true;
		for (int nxt : graph[t])
		{
			if (nxt == p) continue;
			adfs(nxt, t, cut);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cdfs(1, -1);
	dfs(1, -1);

	if (cents.size() >= 2)
	{
		for (int i = 1; i <= n; i++) printf("1 ");
		printf("\n");
		return 0;
	}

	centroid = cents[0];

	cdfs(centroid, -1);
	yes[centroid] = true;
	int maxchild = -1;
	for (int t : graph[centroid])
	{
		if (maxchild == -1 || childcnt[maxchild] < childcnt[t])
			maxchild = t;
	}

	for (int t : graph[centroid])
	{
		if (t == maxchild) continue;
		adfs(t, centroid, childcnt[maxchild]);
	}

	int secmax = -1;
	for (int t : graph[centroid])
	{
		if (t == maxchild) continue;
		if (secmax == -1 || childcnt[secmax] < childcnt[t])
			secmax = t;
	}

	adfs(maxchild, centroid, secmax >= 0 ? childcnt[secmax] : 0);

	for (int i = 1; i <= n; i++) printf("%d ", yes[i]);
	printf("\n");
}