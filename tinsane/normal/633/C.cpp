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

bool is_prime(int x)
{
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int get_prime(int x)
{
	x += rand() % x;
	for (; !is_prime(x); ++x);
	return x;
}

const int N = 1e4 + 10;
const int W = 1e3 + 10;
int base;
int n, m;
int anc[N];
string s;
map<int, string> exists[W];

int sum(int a, int b)
{
	a += b;
	if (a >= P)
		return a - P;
	return a;
}

int mul(int a, int b)
{
	return (ll)a * b % P;
}

int get_hash(const string& s)
{
	int res = 0;
	for (auto letter : s)
		if ('a' <= letter && letter <= 'z')
			res = sum(mul(res, base), letter - 'a');
		else
			res = sum(mul(res, base), letter - 'A');

	return res;
}

void solve()
{
	srand(time(NULL));
	base = get_prime('z' - 'a' + 1);
	cin >> n >> s;
	reverse(s.begin(), s.end());
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string t;
		cin >> t;
		exists[t.size()][get_hash(t)] = t;
	}
	fill(anc, anc + n + 1, -1);
	anc[0] = 0;
	for (int i = 0; i < n; ++i)
	if (anc[i] != -1)
	{
		int phash = 0;
		for (int j = 0; i + j < n && j < W - 1; ++j)
		{
			phash = sum(mul(phash, base), s[i + j] - 'a');
			if (anc[i + j + 1] == -1 && exists[j + 1].count(phash))
				anc[i + j + 1] = i;
		}
	}
	vector<string> ans;
	for (int beg = anc[n], end = n; end > 0; end = beg, beg = anc[beg])
	{
		int phash = 0;
		for (int i = beg; i < end; ++i)
			phash = sum(mul(phash, base), s[i] - 'a');
		ans.push_back(exists[end - beg][phash]);
	}
	for (auto i : ans)
		cout << i << ' ';
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