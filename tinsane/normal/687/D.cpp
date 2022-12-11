#pragma region Template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
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
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

struct Edge
{
	int a, b, w, ind;
	void read(int ind)
	{
		this->ind = ind;
		scanf("%d%d%d", &a, &b, &w);
		--a, --b;
	}
	bool operator< (const Edge& e) const
	{
		return w > e.w;
	}
};


const int N = 1e3 + 10;
int n, q, m;
short dsu[N], si[N];
int unit[N][N];
bool color[N];
Edge edges[N * N];

inline bool unite(int a, int b)
{
	if (dsu[a] == dsu[b])
		return color[a] != color[b];
	if (si[b] < si[a])
		swap(a, b);
	short d = dsu[a];
	short nd = dsu[b];
	auto u = unit[d];
	if (color[a] == color[b])
		for (int i = 0; i < si[d]; ++i)
			color[u[i]] = !color[u[i]];
	short s = si[dsu[b]];
	for (int i = 0; i < si[d]; ++i)
	{
		unit[nd][s + i] = u[i];
		dsu[u[i]] = nd;
	}
	si[nd] += si[d];
	return true;
}

void solve()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i)
		edges[i].read(i);
	sort(edges, edges + m);
	for (int i = 0; i < q; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		for (int j = 0; j < n; ++j)
		{
			dsu[j] = j;
			unit[j][0] = j;
		}
		fill(si, si + n, 1);
		fill(color, color + n, 0);
		bool ok = true;
		for (int j = 0; j < m; ++j)
			if (l <= edges[j].ind && edges[j].ind <= r && !unite(edges[j].a, edges[j].b))
			{
				ok = false;
				printf("%d\n", edges[j].w);
				break;
			}
		if (ok)
			puts("-1");
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}