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

const int M = (1 << 18);
int cnt[M];
int n;
char buf[10], x[20];

void solve()
{
	scanf("%d", &n);
	for (int it = 0; it < n; ++it)
	{
		scanf("%s%s", buf, x);
		int len = strlen(x);
		reverse(x, x + len);
		int s = 0;
		switch (buf[0])
		{
		case '+':
			for (int i = 0; i < len; ++i)
				if ((x[i] - '0') % 2 == 1)
					s |= (1 << i);
			++cnt[s];
			break;
		case '-':
			for (int i = 0; i < len; ++i)
				if ((x[i] - '0') % 2 == 1)
					s |= (1 << i);
			--cnt[s];
			break;
		case '?':
			for (int i = 0; i < len; ++i)
				if (x[i] == '1')
					s |= (1 << i);
			printf("%d\n", cnt[s]);
			break;
		default:
			throw;
		}
	}
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