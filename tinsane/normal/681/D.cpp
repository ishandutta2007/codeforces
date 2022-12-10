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
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

#pragma endregion

const int N = 1e5 + 10;
int n, m;
vector<int> edges[N];
bool fath[N];
int pres[N];
vector<int> ans;

bool dfs(int v, int anc)
{
	if (pres[v] == v)
		anc = v;
	if (pres[v] != anc)
		return false;
	for (auto e : edges[v])
		if (!dfs(e, anc))
			return false;
	if (v == anc)
		ans.push_back(v);
	return true;
}

void solve()
{
	scanf("%d%d", &n, &m);
	fill(fath, fath + n, true);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		fath[b] = false;
		edges[a].push_back(b);
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", &pres[i]), --pres[i];
	for (int i = 0; i < n; ++i)
		if (fath[i] && !dfs(i, i))
		{
			printf("-1");
			return;
		}
	printf("%d\n", ans.size());
	for (auto e : ans)
		printf("%d\n", e + 1);
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