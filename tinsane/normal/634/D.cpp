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

struct Station
{
	ll x, cost;
	Station() : x(), cost() {}
	Station(ll _x, ll _cost) : x(_x), cost(_cost) {}
	void read()
	{
		cin >> x >> cost;
	}
	bool operator< (const Station& s) const
	{
		return x < s.x;
	}
};

const int LOGN = 20;
const int N = 2e5 + 110;
ll n, d, m, sparse_table[LOGN][N], p2[LOGN], rp2[N];
int good[N];
ll ans;
Station stations[N];

void build_st()
{
	p2[0] = 1;
	for (int i = 1; i < LOGN; ++i)
		p2[i] = p2[i - 1] * 2;
	for (int i = 1; i < N; ++i)
	{
		rp2[i] = rp2[i - 1];
		if (p2[rp2[i] + 1] <= i)
			++rp2[i];
	}
	for (int i = 0; i < m; ++i)
		sparse_table[0][i] = stations[i].cost;
	for (int i = 1; i < LOGN; ++i)
		for (int j = 0; j + p2[i] <= m; ++j)
			sparse_table[i][j] = min(sparse_table[i - 1][j], sparse_table[i - 1][j + p2[i - 1]]);
}

int get_st(int l, int r)
{
	int k = rp2[r - l + 1];
	return min(sparse_table[k][l], sparse_table[k][r + 1 - p2[k]]);
}

void bs_good(int v)
{
	int l = v + 1;
	int r = m - 1;
	if (get_st(l, r) > stations[v].cost)
	{
		good[v] = -1;
		return;
	}
	if (get_st(l, l) <= stations[v].cost)
	{
	    good[v] = l;
	    return;
	}
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (get_st(l, mid) <= stations[v].cost)
			r = mid;
		else
			l = mid;
	}
	good[v] = r;
}

void solve()
{
	cin >> n >> d >> m;
	for (int i = 0; i < m; ++i)
		stations[i].read();
	stations[m] = Station(0, 0);
	stations[m + 1] = Station(n, 0);
	m += 2;
	sort(stations, stations + m);
	for (int i = 1; i < m; ++i)
	if (stations[i].x - stations[i - 1].x > d)
	{
		cout << -1;
		return;
	}
	build_st();
	for (int i = 0; i < m - 1; ++i)
		bs_good(i);
	ll gaz = d;
	for (int now = 0; now < m - 1;)
	{
		if (good[now] == -1 || (stations[good[now]].x - stations[now].x > d))
		{
			ans += (d - gaz) * stations[now].cost;
			gaz = d - (stations[now + 1].x - stations[now].x);
			++now;
			continue;
		}
		ll need = max(0LL, (stations[good[now]].x - stations[now].x) - gaz);
		ans += need * stations[now].cost;
		gaz -= (stations[good[now]].x - stations[now].x) - need;
		assert(gaz >= 0);
		now = good[now];
	}
	cout << ans;
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