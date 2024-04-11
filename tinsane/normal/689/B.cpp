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

const int N = 1e6 + 10;
int n;
int a[N];
int dist[N];
int wave[N], wsi = 1;

void upd(int x, int d)
{
	if (x < 0 || x >= n || dist[x] != -1)
		return;
	dist[x] = d;
	wave[wsi++] = x;
}

void relax(int v)
{
	upd(v - 1, dist[v] + 1);
	upd(v + 1, dist[v] + 1);
	upd(a[v], dist[v] + 1);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), --a[i];
	fill(dist + 1, dist + n, -1);
	for (int i = 0; i < wsi; ++i)
	{
		int v = wave[i];
		relax(v);
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", dist[i]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("tiling.in", "r", stdin);
	//freopen("tiling.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}