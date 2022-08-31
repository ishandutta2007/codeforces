#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
#define mp make_pair
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y)
{
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}

const int N = 200200;
const int K = 60;
int n;
vector<pil> g[N];
int h[N];
ll a[N];
int dim;
ll orAll;
ll b[K];
int cntBit[K][2];

void read()
{
	int m;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int v, u;
		ll w;
		scanf("%d%d%lld", &v, &u, &w);
		v--;u--;
		g[v].push_back(mp(u, w));
		g[u].push_back(mp(v, w));
	}
	for (int i = 0; i < n; i++)
		h[i] = -1;
	return;
}

void addNum(ll x)
{
	for (int i = 0; i < K; i++)
		cntBit[i][(x >> i) & 1LL]++;
	return;
}

void addCycle(ll x)
{
	orAll |= x;
	for (int i = 0; i < K; i++)
	{
		if ((x >> i) & 1)
		{
			if (b[i] == -1)
			{
				b[i] = x;
				dim++;
				return;
			}
			x ^= b[i];
		}
	}
	return;
}

void dfs(int v)
{
	addNum(a[v]);
	for (pil e : g[v])
	{
		int u = e.first;
		if (h[u] == -1)
		{
			h[u] = h[v] + 1;
			a[u] = a[v] ^ e.second;
			dfs(u);
			continue;
		}
		if (h[u] > h[v]) continue;
		if (h[u] == h[v] - 1) continue;
		addCycle(a[v] ^ a[u] ^ e.second);
	}
	return;
}

ll solve(int v)
{
	h[v] = 0;
	dim = 0;
	a[v] = 0;
	for (int i = 0; i < K; i++)
	{
		b[i] = -1;
		cntBit[i][0] = cntBit[i][1] = 0;
	}
	orAll = 0;
	dfs(v);
	ll p = 1;
	for (int i = 0; i < dim - 1; i++)
		p = add(p, p);
	ll p2 = add(p, p);
	if (dim == 0) p2 = 1;
	ll ans = 0;
	ll q = 1;
	for (int i = 0; i < K; i++)
	{
		if ((orAll >> i) & 1LL)
		{
			ll nn = cntBit[i][0] + cntBit[i][1];
			ll C = ((nn * (nn - 1)) / 2) % MOD;
			ans = add(ans, mult(q, mult(C, p)));
		}
		else
		{
			ans = add(ans, mult(mult(q, p2), mult(cntBit[i][0], cntBit[i][1])));
		}
		q = add(q, q);
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	ll ans = 0;
	for (int v = 0; v < n; v++)
	{
		if (h[v] != -1) continue;
		ans = add(ans, solve(v));
	}
	printf("%lld\n", ans);

	return 0;
}