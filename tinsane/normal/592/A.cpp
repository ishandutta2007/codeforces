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

const int N = 8;
string field[N];

void solve()
{
	int mif = INF, mis = INF;
	for (int i = 0; i < N; ++i)
		cin >> field[i];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (field[i][j] == 'W')
			{
				bool good = true;
				for (int k = 0; k < i; ++k)
					good &= field[k][j] == '.';
				if (good)
					mif = min(mif, i);
			}
			else if (field[i][j] == 'B')
			{
				bool good = true;
				for (int k = i + 1; k < N; ++k)
					good &= field[k][j] == '.';
				if (good)
					mis = min(mis, N - i - 1);
			}
		}
	if (mis < mif)
		cout << 'B';
	else
		cout << 'A';
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