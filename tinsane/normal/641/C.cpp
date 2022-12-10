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


const int N = 1e6 + 10;
int n, q, pos = 0, ri = 1;
int ans[N], ans2[N];

void add(int& pos, int x)
{
	pos += x;
	if (pos < 0)
		pos += n;
	if (pos >= n)
		pos -= n;
}

void change()
{
	if (pos % 2 == 0)
		add(ri, 2);
	else
		add(ri, -2);
	pos ^= 1;
}

void solve()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; ++i)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int x;
			scanf("%d", &x);
			add(pos, x);
		}
		else
			change();
	}
	for (int i = 0; i < n; i += 2)
	{
		ans[i] = pos;
		add(pos, 2);
	}
	add(pos, 1);
	for (int i = ri; i < n + ri; i += 2)
	{
		ans[i % n] = pos;
		add(pos, 2);
	}
	for (int i = 0; i < n; ++i)
		ans2[ans[i]] = i;
	for (int i = 0; i < n; ++i)
		printf("%d ", ans2[i] + 1);
}
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}