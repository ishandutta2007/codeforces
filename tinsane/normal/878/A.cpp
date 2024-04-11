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
#include <random>
#include <complex>
#include <regex>
#include <numeric>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

template <typename T, typename Q>
ostream& operator<<(ostream& os, pair<T, Q> p)
{
	return (os << '(' << p.first << ", " << p.second << ')');
}

#define mp make_pair
#define rand govno_ebanoe
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) cerr << #x << " : " << (x) << endl
#define dbga(arr, len) {cerr << #arr << " : "; for(int i = 0; i < len; ++i) cerr << arr[i] << ' '; cerr << endl;}
#define dbg2da(arr, len1, len2) {cerr << #arr << endl; for(int i = 0; i < len1; ++i, cerr << endl) for(int j = 0; j < len2; ++j) cerr << arr[i][j] << ' ';}
#define dbgi(i) {cerr << #i << " : "; for(auto e : i) cerr << e << ' '; cerr << endl;}
#else
#define eprintf(...) (void)0
#define dbg(x) (void)0
#define dbga(arr, len) {}
#define dbg2da(arr, len1, len2) {}
#define dbgi(i) {}
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int INF = (int)1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
#pragma endregion

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

int n;
const int b = 10;
char state[b];
char op[10];
int x;

void solve()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s%d", op, &x);
		for (int i = 0; i < b; ++i)
		{
			if (op[0] == '^')
			{
				if (x & (1 << i))
					state[i] ^= 1;
			}
			else if (op[0] == '|')
			{
				if (x & (1 << i))
					state[i] = 3;
			}
			else
			{
				if (!(x & (1 << i)))
					state[i] = 2;
			}
		}
	}
	puts("3");
	x = 0;
	for (int i = 0; i < b; ++i)
		if (state[i] == 2)
			x |= (1 << i);
	printf("& %d\n", 1023 ^ x);
	x = 0;
	for (int i = 0; i < b; ++i)
		if (state[i] == 3)
			x |= (1 << i);
	printf("| %d\n", x);
	x = 0;
	for (int i = 0; i < b; ++i)
		if (state[i] == 1)
			x |= (1 << i);
	printf("^ %d\n", x);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef NOERR
	freopen("err.txt", "w", stderr);
#endif
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

#ifdef ERR_CATCH
	try
	{
#endif

#ifdef ST
		while (true)
			solve();
#endif

#ifdef CASES
#define MULTITEST
#endif

#ifdef MULTITEST
		int t;
		scanf("%d", &t);
		char endl1[5];
		fgets(endl1, 5, stdin);
		for (int i = 0; i < t; ++i)
		{
#ifdef CASES
			printf("Case #%d: ", i + 1);
#endif
			solve();
#ifdef CASES
			eprintf("Passed case #%d:\n", i + 1);
#endif
		}
#else
		solve();
#endif

#ifdef ERR_CATCH
	}
	catch (logic_error e)
	{
		dbg(e.what());
		puts("___________________________________________________________________________");
		exit(0);
	}
#endif
#ifdef LOCAL
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif
}