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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int Q = 1010;
int q;
int type;
ll u, v, w;
unordered_map<ll, ll> costs;

int bit_cnt(ll x)
{
	int res = 0;
	for (; x > 0; x >>= 1, ++res);
	return res;
}

void solve()
{
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%I64d%I64d", &type, &u, &v);
		int b1 = bit_cnt(u);
		int b2 = bit_cnt(v);
		if (b1 > b2)
		{
			swap(b1, b2);
			swap(u, v);
		}
		if (type == 1)
		{
			scanf("%I64d", &w);
			for (int i = 0; i < b2 - b1; ++i)
			{
				costs[v] += w;
				v >>= 1;
			}
			while (u != v)
			{
				costs[v] += w;
				costs[u] += w;
				v >>= 1;
				u >>= 1;
			}
			continue;
		}
		ll ans = 0;
		for (int i = 0; i < b2 - b1; ++i)
		{
			if (costs.count(v))
				ans += costs[v];
			v >>= 1;
		}
		while (u != v)
		{
			if (costs.count(v))
				ans += costs[v];
			if (costs.count(u))
				ans += costs[u];
			v >>= 1;
			u >>= 1;
		}
		printf("%I64d\n", ans);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("bandits.in", "r", stdin);
	//freopen("bandits.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}