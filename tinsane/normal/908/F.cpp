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
#include <random>
#include <complex>
#include <regex>
#include <numeric>
#include <typeinfo>
#include <type_traits>
#include <fstream>
#pragma comment(linker, "/STACK:167772160")

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using namespace std;

using ll = long long;

const int INF = 1e9 + 10;
const int N = 3e5 + 10;
int n;
int x[N];
char c[N];
char buf[10];
int mins[256];
int maxs[256];
char ALP[] = { 'G', 'B', 'R' };

int find_mi(char col)
{
	for (int i = 0; i < n; ++i)
		if (c[i] == col)
			return x[i];
	return 0;
}

int find_ma(char col)
{
	for (int i = n - 1; i >= 0; --i)
		if (c[i] == col)
			return x[i];
	return 0;
}

vector<int> extract(int l, int r, int col)
{
	vector<int> res;
	res.push_back(x[l]);
	for (int i = l + 1; i < r; ++i)
		if (c[i] == col)
			res.push_back(x[i]);
	res.push_back(x[r]);
	return res;
}

void solve()
{
	scanf("%d", &n);
	int gcnt = 0;
	int rcnt = 0;
	int bcnt = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x[i]);
		scanf("%s", buf);
		c[i] = buf[0];
		gcnt += c[i] == 'G';
		bcnt += c[i] == 'B';
		rcnt += c[i] == 'R';
	}
	ll cost = 0;
	for (auto c : ALP)
	{
		mins[c] = find_mi(c);
		maxs[c] = find_ma(c);
	}
	if (gcnt == 0)
	{
		cost += maxs['R'] - mins['R'];
		cost += maxs['B'] - mins['B'];
		printf("%lld\n", cost);
		return;
	}
	if (bcnt > 0 && mins['B'] < mins['G'])
		cost += mins['G'] - mins['B'];
	if (rcnt > 0 && mins['R'] < mins['G'])
		cost += mins['G'] - mins['R'];
	if (rcnt > 0 && maxs['R'] > maxs['G'])
		cost += maxs['R'] - maxs['G'];
	if (bcnt > 0 && maxs['B'] > maxs['G'])
		cost += maxs['B'] - maxs['G'];
	int prv = -1;
	for (int i = 0; i < n; ++i)
	{
		if (c[i] != 'G')
			continue;
		if (prv != -1)
		{
			if (i == prv + 1)
			{
				cost += x[i] - x[prv];
				prv = i;
				continue;
			}
			auto r = extract(prv, i, 'R');
			auto b = extract(prv, i, 'B');
			for (int i = 0; i + 1 < r.size(); ++i)
				r[i] = r[i + 1] - r[i];
			for (int i = 0; i + 1 < b.size(); ++i)
				b[i] = b[i + 1] - b[i];
			r.pop_back();
			b.pop_back();
			auto f = ll(3) * (x[i] - x[prv]) - *max_element(r.begin(), r.end()) - *max_element(b.begin(), b.end());
			auto s = ll(2) * (x[i] - x[prv]);
			cost += min(f, s);
		}
		prv = i;
	}
	printf("%lld\n", cost);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

	solve();
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
	return 0;
}