#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
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


const int N = 52;
int n;
int perm[N];
int a[N][N];

void solve()
{
	cin >> n;
	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			cin >> a[i][j];
	for (int i(1); i < n; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			bool f = true;
			for (int k(0); k < n; ++k)
				f &= (a[j][k] <= i);
			if (f)
			{
				perm[j] = i;
				for (int k(0); k < n; ++k)
					a[j][k] = INF;
				break;
			}
		}
	}
	for (int i(0); i < n; ++i)
		if (perm[i] == 0)
			perm[i] = n;
	for (int i(0); i < n; ++i)
		cout << perm[i] << ' ';
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
	ios_base::sync_with_stdio(0); cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{
}