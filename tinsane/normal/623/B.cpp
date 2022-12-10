#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <cassert>
#include <ctime>
#include <valarray>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const double PI = 3.1415926535897932384626433;
const int P = (int) 1e9 + 7;
const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double eps = 1e-8;
void debugOutput();

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}


vector<int> fact(int x)
{
	vector<int> res;
	for (int i(2); i * i <= x; ++i)
	if (x % i == 0)
	{
		res.push_back(i);
		for (; x % i == 0; x /= i);
	}
	if (x > 1)
		res.push_back(x);
	return res;
}

const int N = 1e6 + 10;
ll a, b;
int n;
int mas[N];
bool can[N];

vector<int> make()
{
	vector<int> res, t;
	t = fact(mas[0]);
	for (auto e : t)
		res.push_back(e);
	t = fact(mas[0] - 1);
	for (auto e : t)
		res.push_back(e);
	t = fact(mas[0] + 1);
	for (auto e : t)
		res.push_back(e);
	t = fact(mas[n - 1] - 1);
	for (auto e : t)
		res.push_back(e);
	t = fact(mas[n - 1]);
	for (auto e : t)
		res.push_back(e);
	t = fact(mas[n - 1] + 1);
	for (auto e : t)
		res.push_back(e);
	sort(res.begin(), res.end());
	res.resize(unique(res.begin(), res.end()) - res.begin());
	return res;
}

void solve()
{
	cin >> n >> a >> b;
	for (int i(0); i < n; ++i)
		cin >> mas[i];
	if (n == 1)
	{
		cout << 0;
		return;
	}
	vector<int> v = make();
	ll best = LINF;
	for (auto i : v)
	{
		fill(can, can + n, false);
		for (int j(0); j < n; ++j)
			can[j] = (mas[j] % i == 0 || (mas[j] - 1) % i == 0 || (mas[j] + 1) % i == 0);
		int l(-1), r(-1);
		for (int j(0); j < n; ++j)
			if (!can[j])
				r = j;
		for (int j(n - 1); j >= 0; --j)
			if (!can[j])
				l = j;
		for (int j(0); j < n; ++j)
			can[j] = (mas[j] % i == 0);
		if (l == -1)
		{
			int cnt = 0;
			for (int j(0); j < n; ++j)
				cnt += !can[j];
			ll bd = 0, d = 0;
			for (int j(0); j < n; ++j)
			{
				d -= a;
				if (!can[j])
					d += b;
				if (d < 0)
					d = 0;
				bd = max(bd, d);
			}
			best = min(best, cnt * b - bd);
		}
		else
		{
			int bad = 0;
			ll ta1 = LINF;
			for (int j(0); j <= l; ++j)
			{
				ta1 = min(ta1, a * (l - j) + bad * b);
				bad += !can[j];
			}
			bad = 0;
			ll ta2 = LINF;
			for (int j(n - 1); j >= r; --j)
			{
				ta2 = min(ta2, a * (j - r) + bad * b);
				bad += !can[j];
			}
			best = min(best, ta1 + ta2 + a * (r - l + 1));
		}
	}
	cout << best;
}



int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("teleports.in", "r", stdin);
	//freopen("teleports.out", "w", stdout);
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