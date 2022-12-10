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
int n, m, k;
int dollars[N], funts[N], min_dollar[N], min_funt[N], dollar_day[N], funt_day[N];
int dg_cnt, fg_cnt;
pii dollar_gadgets[N], funt_gadgets[N];
ll dollar_psum[N], funt_psum[N], s;

bool try_buy(int day, bool print = false)
{
	for (int i = 0; i <= fg_cnt; ++i)
	{
		ll lost = s - funt_psum[i] * min_funt[day];
		if (lost < 0)
			break;
		int db = upper_bound(dollar_psum, dollar_psum + dg_cnt + 1, lost / min_dollar[day]) - dollar_psum - 1;
		if (db + i >= k)
		{
			if (print)
			{
				cout << day + 1 << '\n';
				if (i > k)
					i = k;
				db = k - i;
				for (int j = 0; j < i; ++j)
					cout << funt_gadgets[j].second << ' ' << funt_day[day] + 1 << '\n';
				for (int j = 0; j < db; ++j)
					cout << dollar_gadgets[j].second << ' ' << dollar_day[day] + 1 << '\n';
			}
			return true;
		}
	}
	return false;
}

void solve()
{
	cin >> n >> m >> k >> s;
	for (int i = 0; i < n; ++i)
		cin >> dollars[i];
	for (int i = 0; i < n; ++i)
		cin >> funts[i];
	for (int i = 0; i < m; ++i)
	{
		int type, cost;
		cin >> type >> cost;
		if (type == 1)
			dollar_gadgets[dg_cnt++] = make_pair(cost, i + 1);
		else
			funt_gadgets[fg_cnt++] = make_pair(cost, i + 1);
	}
	
	sort(dollar_gadgets, dollar_gadgets + dg_cnt);
	sort(funt_gadgets, funt_gadgets + fg_cnt);
	
	for (int i = 0; i < dg_cnt; ++i)
		dollar_psum[i + 1] = dollar_psum[i] + dollar_gadgets[i].first;
	for (int i = 0; i < fg_cnt; ++i)
		funt_psum[i + 1] = funt_psum[i] + funt_gadgets[i].first;
	
	min_dollar[0] = dollars[0];
	min_funt[0] = funts[0];
	for (int i = 1; i < n; ++i)
	{
		if (dollars[i] < min_dollar[i - 1])
		{
			min_dollar[i] = dollars[i];
			dollar_day[i] = i;
		}
		else
		{
			min_dollar[i] = min_dollar[i - 1];
			dollar_day[i] = dollar_day[i - 1];
		}
		if (funts[i] < min_funt[i - 1])
		{
			min_funt[i] = funts[i];
			funt_day[i] = i;
		}
		else
		{
			min_funt[i] = min_funt[i - 1];
			funt_day[i] = funt_day[i - 1];
		}
	}
	if (!try_buy(n - 1))
	{
		cout << -1;
		return;
	}
	if (try_buy(0))
	{
		try_buy(0, true);
		return;
	}
	int l = 0, r = n - 1;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (try_buy(m))
			r = m;
		else
			l = m;
	}
	try_buy(r, true);
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