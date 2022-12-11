#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#include <valarray>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

const int _K = (int)1e6 + 100;
const int N = (int)1e5 + 10;
const int LOG = 18;
const int mod = (int)1e9 + 7;

int add(int a, int b)
{
	a += b;
	if (a < 0)
		return a + mod;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return ((long long)a * b) % mod;
}

int myPow(int a, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return mult(a, myPow(a, k - 1));
	int t = myPow(a, k / 2);
	return mult(t, t);
}

struct Edge
{
	int to, type;
	Edge () : to(), type() {}
	Edge (int _to, int _type) : to(_to), type(_type) {}
};

vector <Edge> g[N];
int order[_K];
int jump[LOG][N];
int allowed[N];
int h[N];
bool used[N];
int up[N], down[N];

void dfs(int v)
{
	for (int i = 1; i < LOG; i++)
		jump[i][v] = jump[i - 1][jump[i - 1][v]];
	used[v] = 1;
	for (auto e : g[v])
	{
		int to = e.to;
		if (!used[to])
		{
			jump[0][to] = v;
			allowed[to] = e.type;
			h[to] = h[v] + 1;
			dfs(to);
		}
	}
}

int go(int v, int d)
{
	for (int i = 0; i < LOG; i++)
	{
		if (d & (1 << i))
			v = jump[i][v];
	}
	return v;
}

int getLca(int a, int b)
{
	if (h[a] > h[b])
		a = go(a, h[a] - h[b]);
	else
		b = go(b, h[b] - h[a]);
	if (a == b)
		return a;
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (jump[i][a] != jump[i][b])
		{
			a = jump[i][a];
			b = jump[i][b];
		}
	}
	return jump[0][a];
}

void addQueryInfo(int a, int b)
{
	int c = getLca(a, b);
	up[a]++;
	up[c]--;
	down[b]++;
	down[c]--;
}

int ans = 0;
void calcInfo(int v)
{
	used[v] = 1;
	for (auto e : g[v])
	{
		int to = e.to;
		if (used[to])
			continue;
		calcInfo(to);
		up[v] += up[to];
		down[v] += down[to];
	}
	//eprintf("v - par : %d - %d, allowed = %d, down = %d, up = %d\n", v, jump[0][v], allowed[v], down[v], up[v]);
	if (!(allowed[v] & 1))
		ans = add(ans, add(myPow(2, down[v]), -1));
	if (!(allowed[v] & 2))
		ans = add(ans, add(myPow(2, up[v]), -1));
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		a--, b--;
		if (t == 0)
		{
			g[a].push_back(Edge(b, 3));
			g[b].push_back(Edge(a, 3));
		}
		else
		{
			g[a].push_back(Edge(b, 1));
			g[b].push_back(Edge(a, 2));
		}
	}

	dfs(0);
	int k;
	scanf("%d", &k);
	k++;
	order[0] = 0;
	for (int i = 1; i < k; i++)
	{
		scanf("%d", &order[i]);
		order[i]--;
	}

	for (int i = 0; i < k - 1; i++)
		addQueryInfo(order[i], order[i + 1]);

	memset(used, 0, sizeof(used));
	calcInfo(0);
	printf("%d\n", ans);

	return 0;
}