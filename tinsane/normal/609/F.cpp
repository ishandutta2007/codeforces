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

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double pi = 2 * atan2(1, 0);
const ld PI = 2 * atan2l(1, 0);
const double eps = 1e-8;
const ld EPS = 1e-12;
void debugOutput();

const int N = 2e5 + 10;
int n, m;

struct SegTree
{
	int seg_tree[4 * N];
	int size;
	SegTree()
	{
		fill(seg_tree, seg_tree + 4 * N, -1);
	}
	void set(int pos, int val)
	{
		set(1, 0, size - 1, pos, val);
	}
	int get(int l, int r)
	{
		return get(1, 0, size - 1, l, r);
	}
	void set(int ind, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			seg_tree[ind] = val;
			return;
		}
		int m = (l + r) / 2;
		if (pos <= m)
			set(ind * 2, l, m, pos, val);
		else
			set(ind * 2 + 1, m + 1, r, pos, val);
		seg_tree[ind] = max(seg_tree[ind * 2], seg_tree[ind * 2 + 1]);
	}
	int get(int ind, int l, int r, int L, int R)
	{
		if (L <= l && r <= R)
			return seg_tree[ind];
		if (r < L || R < l)
			return -1;
		int m = (l + r) / 2;
		return max(get(ind * 2, l, m, L, R), get(ind * 2 + 1, m + 1, r, L, R));
	}
	int find(int pos)
	{
		return find(1, 0, size - 1, pos);
	}
	int find(int ind, int l, int r, int pos)
	{
		if (l == r)
			return l;
		int m = (l + r) / 2;
		if (seg_tree[ind * 2] < pos)
			return find(ind * 2 + 1, m + 1, r, pos);
		else
			return find(ind * 2, l, m, pos);
	}
} frogs_tree, mosquitos_tree;

struct Frog
{
	int pos, num, cnt;
	ll len;
	void init(int _num)
	{
		cin >> pos >> len;
		num = _num;
		cnt = 0;
	}
	bool operator< (const Frog& f) const
	{
		return pos < f.pos;
	}
} frogs[N];

struct Mosquito
{
	int pos, size, num;
	Mosquito() {}
	Mosquito(ll _pos) : pos(min(INF * 1LL, _pos)) {}
	void init(int _num)
	{
		cin >> pos >> size;
		num = _num;
	}
	bool operator< (const Mosquito& m) const
	{
		return pos < m.pos;
	}
} mosquitos[N];
int ans_cnt[N], mosquitos_order[N];
ll ans_len[N];

void eat(int frog)
{
	int first = lower_bound(mosquitos, mosquitos + m, Mosquito(frogs[frog].pos)) - mosquitos;
	while (true)
	{
		int last = upper_bound(mosquitos, mosquitos + m, Mosquito(frogs[frog].pos + frogs[frog].len)) - mosquitos - 1;
		int mosquito = mosquitos_tree.get(first, last);
		if (mosquito == -1)
			break;
		mosquitos_tree.set(mosquito, -1);
		frogs[frog].len += mosquitos[mosquito].size;
		++frogs[frog].cnt;
	}
	frogs_tree.set(frog, min(INF * 1LL, frogs[frog].pos + frogs[frog].len));
}

void solve()
{
	cin >> n >> m;
	frogs_tree.size = n;
	mosquitos_tree.size = m;
	for (int i = 0; i < n; ++i)
		frogs[i].init(i);
	sort(frogs, frogs + n);
	for (int i = 0; i < n; ++i)
		frogs_tree.set(i, min(INF * 1LL, frogs[i].pos + frogs[i].len));
	for (int i = 0; i < m; ++i)
		mosquitos[i].init(i);
	sort(mosquitos, mosquitos + m);
	for (int i = 0; i < m; ++i)
		mosquitos_order[mosquitos[i].num] = i;
	for (int i = 0; i < m; ++i)
	{
		int mosquito = mosquitos_order[i];
		mosquitos_tree.set(mosquito, mosquito);
		if (frogs_tree.get(0, n - 1) < mosquitos[mosquito].pos)
			continue;
		eat(frogs_tree.find(mosquitos[mosquito].pos));
	}
	for (int i = 0; i < n; ++i)
	{
		ans_cnt[frogs[i].num] = frogs[i].cnt;
		ans_len[frogs[i].num] = frogs[i].len;
	}
	for (int i = 0; i < n; ++i)
		cout << ans_cnt[i] << ' ' << ans_len[i] << '\n';
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