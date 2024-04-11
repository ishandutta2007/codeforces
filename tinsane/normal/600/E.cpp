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

struct Vertex
{
	bool used;
	ll ans;
	int color, max_cnt;
	map<int, int>* cnt;
	vector<int> edges;
	Vertex() : used(), ans() {}
};

const int N = 1e5 + 10;
int n;
Vertex vertices[N];

void dfs(Vertex& v)
{
	v.used = true;
	int anc = -1;
	for (auto e : v.edges)
		if (!vertices[e].used)
			dfs(vertices[e]);
		else
			anc = e;
	if ((v.edges.size() == 1 && anc != -1) || v.edges.size() == 0)
	{
		v.ans = v.color;
		v.cnt = new map<int, int>();
		v.max_cnt = 1;
		(*v.cnt)[v.color] = 1;
		return;
	}
	int best = -1;
	for (auto e : v.edges)
		if (e != anc && (best == -1 || vertices[e].cnt->size() > vertices[best].cnt->size()))
			best = e;
	v.cnt = vertices[best].cnt;
	v.max_cnt = vertices[best].max_cnt;
	v.ans = vertices[best].ans;
	int tmp = ++(*v.cnt)[v.color];
	if (tmp == v.max_cnt)
		v.ans += v.color;
	else if (tmp == v.max_cnt + 1)
	{
		v.max_cnt = tmp;
		v.ans = v.color;
	}
	for(auto e : v.edges)
		if (e != anc && e != best)
			for (auto color : *vertices[e].cnt)
			{
				int tmp = (*v.cnt)[color.first] += color.second;
				if (tmp == v.max_cnt)
					v.ans += color.first;
				else if (tmp > v.max_cnt)
				{
					v.max_cnt = tmp;
					v.ans = color.first;
				}
			}
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> vertices[i].color;
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		vertices[a].edges.push_back(b);
		vertices[b].edges.push_back(a);
	}
	dfs(vertices[0]);

	for (int i = 0; i < n; ++i)
		cout << vertices[i].ans << ' ';
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