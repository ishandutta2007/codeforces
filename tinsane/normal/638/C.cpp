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
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

struct Edge
{
	int to;
	int num;
	Edge() {}
	Edge(int to, int num) : to(to), num(num) {}
};

struct Vertex
{
	vector<Edge> edges;
	bool visited;
	Vertex() : visited() {}
};

const int N = 2e5 + 10;
int n;
vector<int> ans[N];
Vertex vertices[N];

void dfs(int v, int used_day)
{
	vertices[v].visited = true;
	int now = 0;
	for(auto e : vertices[v].edges)
		if (!vertices[e.to].visited)
		{
			if (now == used_day)
				++now;
			ans[now].push_back(e.num);
			dfs(e.to, now++);
		}
}

void solve()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		vertices[a].edges.emplace_back(b, i);
		vertices[b].edges.emplace_back(a, i);
	}
	int days = 0;
	for (int i = 0; i < n; i++)
		days = max(days, (int)vertices[i].edges.size());
	cout << days << '\n';
	dfs(0, days + 1);
	for (int i = 0; i < days; ++i)
	{
		cout << ans[i].size() << ' ';
		for (auto road : ans[i])
			cout << road << ' ';
		cout << '\n';
	}
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
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}