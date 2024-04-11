#pragma region Template
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
#pragma comment(linker, "/STACK:167772160")

using namespace std;

#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

int n, k;
double l, v1, v2;

void solve()
{
	cin >> n >> l >> v1 >> v2 >> k;
	double lb = 0;
	double rb = l / v2;
	for (int i = 0; i < 60; ++i)
	{
		double t = (lb + rb) / 2;
		int lost = n;
		double now = 0;
		double pos = 0;
		bool ok = true;
		while(lost > 0)
		{
			if (pos != now * v1)
			{
				double dt = (pos - now * v1) / (v1 + v2);
				now += dt;
				pos = now * v1;
				continue;
			}
			if (now * v1 + v2 * t >= l)
			{
				ok = false;
				break;
			}
			lost -= k;
			pos = now * v1 + v2 * t;
			now += t;
		}
		if (ok)
			lb = t;
		else
			rb = t;
	}
	cout << setprecision(9) << fixed << lb + (l - lb * v2) / v1 << endl;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("editor.in", "r", stdin);
	//freopen("intersection.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}