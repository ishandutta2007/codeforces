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
typedef pair<int, int> pii;
typedef vector<vector<int>> vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

const int N = 1e5 + 10;
int n;

struct Segt
{
	int tree[N * 4];
	void put(int pos, int val)
	{
		put(1, 0, n - 1, pos, val);
	}
	void put(int ind, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			tree[ind] = val;
			return;
		}
		int m = (l + r) / 2;
		if (m < pos)
			put(ind * 2 + 1, m + 1, r, pos, val);
		else
			put(ind * 2, l, m, pos, val);
		tree[ind] = min(tree[ind * 2], tree[ind * 2 + 1]);
	}
	int get(int l, int r)
	{
		return get(1, 0, n - 1, l, r);
	}
	int get(int ind, int l, int r, int L, int R)
	{
		if (l > R || r < L)
			return INF;
		if (L <= l && r <= R)
			return tree[ind];
		int m = (l + r) / 2;
		return min(get(ind * 2, l, m, L, R), 
				   get(ind * 2 + 1, m+1, r, L, R));
	}
} segt;

int b[N];
int ans[N];
pii a[N];

void solve(int l, int r, int anc)
{
	if (l > r)
		return;
	int mi = segt.get(l, r);
	int val = b[mi];
	ans[mi] = anc;
	int p = lower_bound(a, a + n, make_pair(val, mi)) - a;
	solve(l, p - 1, val);
	solve(p + 1, r, val);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i].first);
		b[i] = a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		segt.put(i, a[i].second);
	solve(0, n - 1, -1);
	for (int i = 1; i < n; ++i)
		printf("%d ", ans[i]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}