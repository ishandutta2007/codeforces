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

#define mp make_pair

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

const int N = 2e5 + 10;
int n, k;
vector<int> edges[N];
int cnt[N];
int u[N];
ll ans;

void dfs(int v, int p)
{
	for(auto e : edges[v])
		if (e != p)
		{
			dfs(e, v);
			cnt[v] += cnt[e];
		}
}

int find_center()
{
	int v = 0;
	int p = -1;
	while (true)
	{
		bool ok = true;
		for (auto e : edges[v])
			if (e != p && cnt[e] > k)
			{
				p = v;
				v = e;
				ok = false;
				break;
			}
		if (ok)
			return v;
	}
}

void link(int v, int p, int h)
{
	if (cnt[v] == 1)
		ans += h;
	for (auto e : edges[v])
		if (e != p)
			link(e, v, h + 1);
}

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < 2 * k; ++i)
	{
		scanf("%d", &u[i]);
		--u[i];
		++cnt[u[i]];
	}
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(0, -1);
	int c = find_center();
	fill(cnt, cnt + n, 0);
	for (int i = 0; i < 2 * k; ++i)
		cnt[u[i]] = 1;
	link(c, -1, 0);
	printf("%I64d", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("editor.in", "r", stdin);
	//freopen("intersection.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}