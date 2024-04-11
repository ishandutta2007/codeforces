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
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int N = 3e3 + 10;
const int NINF = INF + N;
int n;
int delta[N];
int a[N];
ll ans;

void solve()
{
	scanf("%d", &n);
	++n;
	for (int i = 1; i < n; ++i)
		scanf("%d", &a[i]);
	a[n] = NINF;
	a[0] = -NINF;
	for (int i = 1; i < n; ++i)
		if (a[i] <= a[i - 1])
		{
			delta[i] = a[i - 1] + 1 - a[i];
			a[i] = a[i - 1] + 1;
		}
	int it = 0;
	for (; ; ++it)
	{
		bool change = false;
		for (int i = 1; i < n;)
		{
			int bal = 0;
			int b = i;
			int d = a[i] - a[i - 1] - 1;
			for (; bal <= 0 && b < n && a[b] - a[i] == b - i; ++b)
				if (delta[b] > 0)
					++bal, d = min(d, delta[b]);
				else
					--bal;
			if (bal > 0)
			{
				for (int j = i; j < b; ++j)
				{
					delta[j] -= d;
					a[j] -= d;
				}
				change = true;
			}
			i = b;
		}
		for (int i = n - 1; i > 0; --i)
		{
			int bal = 0;
			int b = i;
			int d = a[i + 1] - a[i] - 1;
			for (; bal <= 0 && b > 0 && a[i] - a[b] == i - b; --b)
				if (delta[b] < 0)
					++bal, d = min(d, -delta[b]);
				else
					--bal;
			if (bal > 0)
			{
				for (int j = b + 1; j <= i; ++j)
				{
					delta[j] += d;
					a[j] += d;
				}
				change = true;
			}
			i = b;
		}
		if (!change)
			break;
	}
	//cout << it << endl;
	for (int i = 0; i < n; ++i)
		ans += abs(delta[i]);
	printf("%I64d\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef STRESS
	while (true)
#endif
#ifdef MULTITEST
		int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
#endif
}