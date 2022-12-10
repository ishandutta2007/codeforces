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
//#include <valarray>
//#include <unordered_map>
//#include <unordered_set>
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
const ll LINF = ll(2e18) + 10;
//const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

const int N = 1e5 + 10;
int n;

struct Segt
{
	pii tree[N * 4];
	void put(int pos, int val)
	{
		put(1, 0, n - 2, pos, val);
	}
	void put(int ind, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			tree[ind] = make_pair(val, pos);
			return;
		}
		int m = (l + r) / 2;
		if (m < pos)
			put(ind * 2 + 1, m + 1, r, pos, val);
		else
			put(ind * 2, l, m, pos, val);
		tree[ind] = tree[ind * 2].first >= tree[ind * 2 + 1].first ? tree[ind * 2] : tree[ind * 2 + 1];
	}
	pii get(int l, int r)
	{
		return get(1, 0, n - 2, l, r);
	}
	pii get(int ind, int l, int r, int L, int R)
	{
		if (l > R || r < L)
			return make_pair(0, -1);
		if (L <= l && r <= R)
			return tree[ind];
		int m = (l + r) / 2;
		pii f = get(ind * 2, l, m, L, R);
		pii s = get(ind * 2 + 1, m + 1, r, L, R);
		return f.first >= s.first ? f : s;
	}
} segt;

int b[N];
ll ans[N];
ll sum_ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d", &b[i]);
		--b[i];
	}
	ans[n - 2] = 1;
	sum_ans = 1;
	segt.put(n - 2, n - 1);
	for (int i = n - 3; i >= 0; --i)
	{
		pii x = segt.get(i + 1, b[i]);
		if (b[i] == n - 1)
			ans[i] = n - i - 1;
		else
			ans[i] = ans[x.second] + (n - 1 - x.second) + (x.second - i) - (b[i] - x.second);
		sum_ans += ans[i];
		segt.put(i, b[i]);
	}
	printf("%I64d", sum_ans);
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