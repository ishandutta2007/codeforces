#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double pi = 2 * atan2(1, 0);
const ld PI = 2 * atan2l(1, 0);
const double eps = 1e-8;
const ld EPS = 1e-12;
void debugOutput();

struct Edge
{
	int to, weight;
	Edge() : to(), weight() {}
	Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

int cnt;
struct FullEdge
{
	int b, a, weight, num;
	void read()
	{
		cin >> b >> a >> weight;
		--b, --a;
		num = cnt++;
	}
	bool operator< (const FullEdge& f) const
	{
		return weight < f.weight;
	}
};

const int LOGN = 19;
struct Vertex
{
	bool used;
	int par, rank, tin, tout;
	vector<Edge> edges;
	int up_weights[LOGN];
	int up[LOGN];
	Vertex() : used() {};
};

const int N = 2e5 + 10;
int n, m;
ll ans[N], tree;
Vertex vertices[N];
FullEdge fullEdges[N];

int get(int v)
{
	return v == vertices[v].par ? v : vertices[v].par = get(vertices[v].par);
}

bool merge(int a, int b)
{
	a = get(a);
	b = get(b);
	if (a == b)
		return false;
	if (vertices[a].rank < vertices[b].rank)
		swap(a, b);
	if (vertices[a].rank == vertices[b].rank)
		++vertices[a].rank;
	vertices[b].par = a;
	return true;
}

int cur_time;
void dfs(int v)
{
	vertices[v].used = true;
	vertices[v].tin = cur_time++;
	fill(vertices[v].up, vertices[v].up + LOGN, 0);
	fill(vertices[v].up_weights, vertices[v].up_weights + LOGN, 0);
	for (auto e : vertices[v].edges)
		if (vertices[e.to].used)
		{
			vertices[v].up[0] = e.to;
			vertices[v].up_weights[0] = e.weight;
			tree += e.weight;
		}
	for (int i = 1; i < LOGN; ++i)
	{
		int anc = vertices[vertices[v].up[i - 1]].up[i - 1];
		vertices[v].up[i] = anc;
		vertices[v].up_weights[i] = max(vertices[v].up_weights[i - 1],
										vertices[vertices[v].up[i - 1]].up_weights[i - 1]);
	}
	for (auto e : vertices[v].edges)
		if (!vertices[e.to].used)
			dfs(e.to);
	vertices[v].tout = cur_time++;
}

bool is_anc(int a, int b)
{
	return (vertices[a].tin <= vertices[b].tin && vertices[b].tout <= vertices[a].tout);
}

int get_lca(int a, int b)
{
	int ma = 0;
	if (is_anc(a, b))
		return a;
	for (; !is_anc(vertices[a].up[ma], b); ++ma);
	int anc = a;
	for (--ma; ma >= 0; --ma)
		if (!is_anc(vertices[anc].up[ma], b))
			anc = vertices[anc].up[ma];
	return vertices[anc].up[0];
}

int calc_hardest(int v, int lca)
{
	if (v == lca)
		return 0;
	int ma = 0;
	for (; !is_anc(vertices[v].up[ma], lca); ++ma);
	int hardest = 0;
	int anc = v;
	for (--ma; ma >= 0; --ma)
		if (!is_anc(vertices[anc].up[ma], lca))
		{
			hardest = max(hardest, vertices[anc].up_weights[ma]);
			anc = vertices[anc].up[ma];
		}
	return max(hardest, vertices[anc].up_weights[0]);
}

void solve(const FullEdge& fedge)
{
	int lca = get_lca(fedge.a, fedge.b);
	ans[fedge.num] = tree + fedge.weight - max(calc_hardest(fedge.a, lca), calc_hardest(fedge.b, lca));
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		vertices[i].par = i;
		vertices[i].rank = 0;
	}
	for (int i = 0; i < m; ++i)
		fullEdges[i].read();
	sort(fullEdges, fullEdges + m);
	for (int i = 0; i < m; ++i)
		if (merge(fullEdges[i].b, fullEdges[i].a))
		{
			vertices[fullEdges[i].b].edges.emplace_back(fullEdges[i].a, fullEdges[i].weight);
			vertices[fullEdges[i].a].edges.emplace_back(fullEdges[i].b, fullEdges[i].weight);
		}
	dfs(0);

	for (int i = 0; i < m; ++i)
		solve(fullEdges[i]);
	for (int i = 0; i < m; ++i)
		cout << ans[i] << '\n';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{}