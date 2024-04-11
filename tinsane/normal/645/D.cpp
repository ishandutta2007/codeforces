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


const int N = 1e5 + 10;
int n, m, top_order[N], tops, lvl[N];
int from[N], to[N];
bool used[N];
vector<int> edges[N];

void topsort(int v)
{
	used[v] = true;
	for (auto e : edges[v])
		if (!used[e])
			topsort(e);
	top_order[tops++] = v;
}

bool good(int last)
{
	for (int i = 0; i < n; ++i)
		edges[i].clear();
	for (int i = 0; i < last; ++i)
		edges[from[i]].push_back(to[i]);
	fill(used, used + n, false);
	tops = 0;
	for (int i = 0; i < n; ++i)
		if (!used[i])
			topsort(i);
	fill(lvl, lvl + n, 0);
	for (int i = 0; i < n; ++i)
		for (auto e : edges[top_order[i]])
			lvl[top_order[i]] = max(lvl[top_order[i]], lvl[e] + 1);
	return lvl[top_order[n - 1]] == n - 1;
}

void solve()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> from[i] >> to[i];
		--from[i];
		--to[i];
	}
	if (!good(m) || m + 1 < n)
	{
		cout << -1;
		return;
	}
	int l = 0;
	int r = m;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (good(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r;
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