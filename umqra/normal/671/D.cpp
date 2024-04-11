#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)4e5 + 10;

struct Repair
{
	int to, cost;
	Repair () : to(), cost() {}
	Repair (int _t, int _c) : to(_t), cost(_c) {}
};

vector <int> g[N];
vector <Repair> rep[N];
int n, m;

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		a--, b--;
		if (a == b)
			continue;
		rep[a].push_back(Repair(b, cost));
	}
}

const ll INF = (ll)1e18;

struct MySet
{
	set <pair<int, ll>> valueByH;
	set <pair<ll, int>> hByValue;
	ll Added;
	MySet()
	{
		valueByH = set<pair<int, ll>>();
		hByValue = set<pair<ll, int>>();
		Added = 0;
	}
	ll getHValue(int h)
	{
		auto it = valueByH.lower_bound(mp(h, -INF));
		if (it == valueByH.end() || it -> X != h)
			return INF;
		return (it -> Y) + Added;
	}
	ll getMin()
	{
		return (hByValue.begin() -> X) + Added;
	}
	void relax(int h, ll value)
	{
		ll old = getHValue(h);
		if (old > value)
		{
			valueByH.erase(mp(h, old - Added));
			hByValue.erase(mp(old - Added, h));

			valueByH.insert(mp(h, value - Added));
			hByValue.insert(mp(value - Added, h));
		}
	}
	int size()
	{
		return (int)valueByH.size();
	}
	void eraseH(int h)
	{
		auto it = *valueByH.lower_bound(mp(h, -INF));

		if (it.X == h)
		{
			valueByH.erase(it);
			hByValue.erase(mp(it.Y, it.X));
		}
	}
};

int h[N], used[N];
MySet* vertexSet[N];

void fail()
{
	puts("-1");
	exit(0);
}

void solve(int v, int p)
{
	int childs = 0;
	for (int to : g[v])
	{
		if (to == p)
			continue;
		childs++;
		h[to] = h[v] + 1;
		solve(to, v);
	}
	if (childs == 0)
	{
		vertexSet[v] = new MySet();
		for (auto r : rep[v])
			vertexSet[v] -> relax(h[r.to], r.cost);
		return;
	}
	ll sumMin = 0;
	int pivot = -1;
	for (int to : g[v])
	{
		if (to == p)
			continue;
		if (pivot == -1 || (vertexSet[to] -> size() > vertexSet[pivot] -> size()))
			pivot = to;
		if (vertexSet[to] -> size() == 0)
			fail();

		ll curMin = vertexSet[to] -> getMin();
		sumMin += curMin;
	}
	vertexSet[v] = vertexSet[pivot];
	ll pivotMin = (vertexSet[v] -> getMin());
	vertexSet[v] -> Added += sumMin - pivotMin;

	for (int to : g[v])
	{
		if (to == p || to == pivot)
			continue;
		ll curMin = vertexSet[to] -> getMin();
		for (auto value : vertexSet[to] -> valueByH)
		{
			ll result = sumMin - curMin + value.Y + vertexSet[to] -> Added;
			vertexSet[v] -> relax(value.X, result);
		}
	}
	for (auto r : rep[v])
		vertexSet[v] -> relax(h[r.to], r.cost + sumMin);
	if (v != 0)
	{
		vertexSet[v] -> eraseH(h[v]);
	}
}

void solve()
{
	solve(0, -1);
	printf("%lld\n", vertexSet[0] -> getMin());
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif
	read();
	solve();
	return 0;
}