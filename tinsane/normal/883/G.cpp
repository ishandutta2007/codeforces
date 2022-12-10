#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

const int N = (int)5e5 + 10;

struct Edge
{
	int to, type;
	char sign;
	int id;
	Edge() : to(), type(), sign(), id() {}
	Edge(int _to, int _type, char _s, int _id) : 
	to(_to), type(_type), sign(_s), id(_id) {}
};

vector <Edge> g[N];

int n, m, start;
char result[N];
bool used[N];
int e_id = 0;

int maximize(int v)
{
	used[v] = 1;
	int sz = 1;
	for (auto &e : g[v])
	{
		if (!used[e.to])
		{
			if (e.type == 2)
				result[e.id] = e.sign;
			sz += maximize(e.to);
		}
	}
	return sz;
}

int minimize(int v)
{
	used[v] = 1;
	int sz = 1;
	for (auto &e : g[v])
	{
		if (!used[e.to] && e.type == 1)
			sz += minimize(e.to);
	}
	return sz;
}

void maximize()
{
	fill(used, used + n, 0);
	fill(result, result + e_id, '+');
	int cnt = maximize(start);
	printf("%d\n", cnt);
	for (int i = 0; i < e_id; i++)
		putchar(result[i]);
	puts("");
}

void minimize()
{
	fill(used, used + n, 0);
	fill(result, result + e_id, '+');
	int cnt = minimize(start);
	for (int i = 0; i < n; i++)
	{
		for (auto &e : g[i])
		{
			if (used[i] && !used[e.to])
				continue;
			if (e.type == 2)
				result[e.id] = e.sign;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < e_id; i++)
		putchar(result[i]);
	puts("");
}

void solve()
{
	scanf("%d%d%d", &n, &m, &start);
	start--;
	for (int i = 0; i < m; i++)
	{
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		a--, b--;
		if (t == 1)
			g[a].push_back(Edge(b, 1, '+', 0));
		else
		{
			g[a].push_back(Edge(b, 2, '+', e_id));
			g[b].push_back(Edge(a, 2, '-', e_id));
			e_id++;
		}
	}
	maximize();
	minimize();
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}