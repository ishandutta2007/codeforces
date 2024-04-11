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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const int P = (int) 1e9 + 7;
const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double pi = 2 * atan2(1, 0);
const ld PI = 2 * atan2l(1, 0);
const double eps = 1e-8;
const ld EPS = 1e-12;
void debugOutput();

const int N = 2e5 + 10;


int n, k, q, bef, aft;
struct SegTree
{
	int sum[N * 4];
	int gre_bef[N * 4];
	void set(int pos, int val)
	{
		set(1, 0, n - 1, pos, val);
	}
	void set(int ind, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			sum[ind] = min(aft, val + sum[ind]);
			gre_bef[ind] = max(0, sum[ind] - bef);
			return;
		}
		int m = (l + r) / 2;
		if (pos <= m)
			set(ind * 2, l, m, pos, val);
		else
			set(ind * 2 + 1, m + 1, r, pos, val);
		sum[ind] = sum[ind * 2] + sum[ind * 2 + 1];
		gre_bef[ind] = gre_bef[ind * 2] + gre_bef[ind * 2 + 1];
	}
	int get(int l, int r, bool repaired)
	{
		auto res = get(1, 0, n - 1, l, r);
		if (repaired)
			return res.first;
		else
			return res.first - res.second;
	}
	pii get(int ind, int l, int r, int L, int R)
	{
		if (r < L || l > R)
			return make_pair(0, 0);
		if (L <= l && r <= R)
			return make_pair(sum[ind], gre_bef[ind]);
		int m = (l + r) / 2;
		return ssum(get(ind * 2, l, m, L, R),
				   get(ind * 2 + 1, m + 1, r, L, R));
	}
	pii ssum(pii f, pii s)
	{
		return make_pair(f.first + s.first, f.second + s.second);
	}
} segt;

void solve()
{
	cin >> n >> k >> aft >> bef >> q;
	for (int i = 0; i < q; ++i)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int d, a;
			cin >> d >> a;
			--d;
			segt.set(d, a);
		}
		else
		{
			int p;
			cin >> p;
			cout << segt.get(0, p - 2, false) + segt.get(p + k - 1, n - 1, true) << '\n';
		}
	}
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
	fprintf(stderr, "\n\nTime: %.3f", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{}