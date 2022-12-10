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
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

string p[2][2];

void move(int num)
{
	if (p[num][1][1] == 'X')
		swap(p[num][1][1], p[num][1][0]);
	if (p[num][0][1] == 'X')
		swap(p[num][0][0], p[num][0][1]);
	if (p[num][1][0] == 'X')
		swap(p[num][0][0], p[num][1][0]);
}

void solve()
{
	for (size_t i = 0; i < 2; i++)
		for (int j = 0; j < 2; ++j)
			cin >> p[i][j];
	move(0);
	move(1);
	for (int i = 0; i < 4; ++i)
	{
		bool good = true;
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				good &= p[0][j][k] == p[1][j][k];
		if (good)
		{
			cout << "YES";
			return;
		}
		swap(p[1][0][1], p[1][1][1]);
		swap(p[1][1][1], p[1][1][0]);
	}
	cout << "NO";
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
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}