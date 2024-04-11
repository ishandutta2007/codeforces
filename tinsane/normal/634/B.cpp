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

const int N = 64;
ll s, x, ans = 1;
int r, used;
bool bits[N], bitx[N], nex[N];

void solve()
{
	cin >> s >> x;
	if (x > s)
	{
		cout << 0;
		return;
	}
	ll tmp = s;
	for (r = 0; tmp > 0; ++r, tmp >>= 1)
		bits[r] = (tmp & 1);
	tmp = x;
	for (int i = 0; tmp > 0; ++i, tmp >>= 1)
		bitx[i] = (tmp & 1);
	reverse(bits, bits + r);
	reverse(bitx, bitx + r);
	ans = (1LL << r);
	for (int i = 0; i < r; ++i)
	{
		if (bits[i] == 1 && bitx[i] == 0)
		{
			nex[i + 1] = true;
			ans >>= 1;
		}
		else if (bits[i] == 1 && bitx[i] == 1)
		{
			if (nex[i])
			{
				cout << 0;
				return;
			}
		}
		else if (bits[i] == 0 && bitx[i] == 1)
		{
			if (nex[i])
				nex[i + 1] = true;
			else
			{
				cout << 0;
				return;
			}
		}
		else
			ans >>= 1;
	}
	if (nex[r])
		cout << 0;
	else if (x != s)
		cout << ans;
	else
		cout << ans - 2;
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