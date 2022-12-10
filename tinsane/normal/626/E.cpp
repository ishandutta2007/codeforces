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
int n, best_pos, best_k;
ll best_sum(0), psum[N], elems[N];

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> elems[i];
	sort(elems, elems + n);
	for (int i = 0; i < n; ++i)
		psum[i + 1] = psum[i] + elems[i];
	for (int mid = 0; mid < n; ++mid)
	{
		int l = 0;
		int r = min(n - 1 - mid, mid);

		if (r == 0 || (elems[n - 1] + elems[mid - 1]) < elems[mid] * 2)
			continue;

		while (r - l > 1)
		{
			int m = (l + r) / 2;
			if ((psum[mid + 1] - psum[mid - m] + psum[n] - psum[n - m]) * (2 * m + 3) <
				(psum[mid + 1] - psum[mid - m - 1] + psum[n] - psum[n - m - 1]) * (2 * m + 1))
				l = m;
			else
				r = m;
		}
		if ((psum[mid + 1] - psum[mid - r] + psum[n] - psum[n - r]) * (2 * best_k + 1) - 
			elems[mid] * (2 * best_k + 1) * (2 * r + 1) >
			best_sum * (2 * r + 1) - elems[best_pos] * (2 * best_k + 1) * (2 * r + 1))
		{
			best_sum = (psum[mid + 1] - psum[mid - r] + psum[n] - psum[n - r]);
			best_pos = mid;
			best_k = r;
		}
	}
	cout << best_k * 2 + 1 << '\n';
	for (int i = 0; i < best_k; ++i)
		cout << elems[n - 1 - i] << ' ';
	for (int i = 0; i <= best_k; ++i)
		cout << elems[best_pos - i] << ' ';
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