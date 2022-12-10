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
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

#pragma endregion

ll n, m;
ll ans;

void solve()
{
	cin >> n >> m;
	--n, --m;
	int l1 = 0;
	int l2 = 0;
	for (ll tmp = n; tmp > 0; tmp /= 7, ++l1);
	for (ll tmp = m; tmp > 0; tmp /= 7, ++l2);
	if (l1 == 0)
		++l1;
	if (l2 == 0)
		++l2;
	if (l1 + l2 > 7)
	{
		cout << 0;
		return;
	}
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
		{
			int mask = 0;
			bool good = true;
			for (int tmp = i, k = 0; k < l1 && good; tmp /= 7, ++k)
			{
				int t = tmp % 7;
				good &= ((mask & (1 << t)) == 0);
				mask |= (1 << t);
			}
			for (int tmp = j, k = 0; k < l2 && good; tmp /= 7, ++k)
			{
				int t = tmp % 7;
				good &= ((mask & (1 << t)) == 0);
				mask |= (1 << t);
			}
			ans += good;
		}
	cout << ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}