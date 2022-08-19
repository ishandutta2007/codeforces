#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 5050;
int n, m;
vector<int> g[N];
int dist[N];
int q[N];
int topQ;

struct Shop
{
	int v;
	ll cost, cnt;

	Shop() : v(), cost(), cnt() {}

	void scan()
	{
		scanf("%d%lld%lld", &v, &cnt, &cost);
		v--;
	}

	bool operator < (const Shop &I) const
	{
		return cost < I.cost;
	}
};

Shop a[N];

void read()
{
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		a[i].scan();
	sort(a, a + m);
	return;
}

void BFS(int v)
{
	for (int i = 0; i < n; i++)
		dist[i] = N;
	topQ = 0;
	q[topQ++] = v;
	dist[v] = 0;
	for (int k = 0; k < topQ; k++)
	{
		v = q[k];
		for (int u : g[v])
		{
			if (dist[u] <= dist[v] + 1) continue;
			dist[u] = dist[v] + 1;
			q[topQ++] = u;
		}
	}
	return;
}

bool solve(int tm, ll cnt, ll A)
{
	for (int i = 0; i < m; i++)
	{
		if (dist[a[i].v] > tm) continue;
		ll x = min(cnt, a[i].cnt);
		cnt -= x;
		A -= x * a[i].cost;
	}
	return cnt == 0 && A >= 0;
}

int query()
{
	int v;
	ll cnt, A;
	scanf("%d%lld%lld", &v, &cnt, &A);
	v--;
	BFS(v);
	int l = -1, r = N;
	while(r - l > 1)
	{
		int mid = (l + r) / 2;
		if (solve(mid, cnt, A))
			r = mid;
		else
			l = mid;
	}
	if (r == N) return -1;
	return r;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	int q;
	scanf("%d", &q);
	while(q--)
		printf("%d\n", query());

	return 0;
}