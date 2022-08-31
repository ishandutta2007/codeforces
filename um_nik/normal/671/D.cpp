#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
#define mp make_pair
const int N = 300300;
const ll INF = (ll)1e18;
int n, m;
vector<int> g[N];
vector<pil> vec[N];
int myVec[N];
ll add[N];
bool del[N];
int par[N];
int p[N];
int h[N];
int q[N];
int topQ;
ll ans = 0;

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		h[i] = p[i] = -1;
	h[0] = 0;
	q[topQ++] = 0;
	
	for (int k = 0; k < topQ; k++)
	{
		int v = q[k];
		for (int u : g[v])
		{
			if (h[u] != -1) continue;
			p[u] = v;
			h[u] = h[v] + 1;
			q[topQ++] = u;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int v, u;
		ll w;
		scanf("%d%d%lld", &v, &u, &w);
		v--;u--;
		if (h[v] > h[u]) swap(v, u);
		if (v == u) continue;
		vec[u].push_back(mp(v, w));
	}

	for (int i = 0; i < n; i++)
	{
		par[i] = -1;
		myVec[i] = i;
		add[i] = 0;
	}

	return;
}

int getPar(int v)
{
	return (par[v] == -1 ? v : par[v] = getPar(par[v]));
}

void merge(int v, int u)
{
	int old = u;
	v = myVec[v];
	u = myVec[u];
	if (vec[v].size() < vec[u].size()) swap(v, u);
	for (int i = 0; i < (int)vec[u].size(); i++)
	{
		pil t = vec[u][i];
		t.second += add[u] - add[v];
		vec[v].push_back(t);
	}
	myVec[old] = v;
	return;
}

void goUp(int v, int u)
{
	if (del[u])
		u = getPar(u);
	while(v != u)
	{
		if (del[v])
			v = getPar(v);
		if (v == u) break;
		del[v] = 1;
		par[v] = u;
		merge(v, u);
		v = p[v];
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int k = n - 1; k > 0; k--)
	{
		int v = q[k];
//		printf("%d\n", v);
		if (del[v]) continue;
		ll c = INF;
		int w = -1;
		for (pil t : vec[myVec[v]])
		{
			int u = t.first;
			if (h[u] >= h[v]) continue;
			if (t.second >= c) continue;
			c = t.second;
			w = u;
		}
		if (w == -1)
		{
			printf("-1\n");
			return 0;
		}
//		printf("%d %lld\n", w, c);
		ans += c + add[myVec[v]];
		add[myVec[v]] = -c;
		goUp(v, w);
	}
	printf("%lld\n", ans);

	return 0;
}