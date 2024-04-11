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
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cerr << #x << " : " << (x) << endl
#define print_array(arr, len) {cerr << #arr << " : "; for(int i = 0; i < len; ++i) cerr << arr[i] << ' '; cerr << endl;}
#define print_2d_array(arr, len1, len2) {cerr << #arr << endl; for(int i = 0; i < len1; ++i, cerr << endl) for(int j = 0; j < len2; ++j) cerr << arr[i][j] << ' ';}
#define print_iterable(i) {cerr << #i << " : "; for(auto e : i) cerr << e << ' '; cerr << endl;}
#define print_new_line() cerr << endl
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) {}
#define print_2d_array(arr, len1, len2) {}
#define print_iterable(i) {}
#define print_new_line() (void)0
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-11;
#pragma endregion

typedef pair<int, ll> pil;

const int S = 61;
int n;
map<pil, int> mex;

int get(int x, ll mask)
{
	auto state = mp(x, mask);
	if (!mex.count(state))
	{
		vector<char> pos(S, true);
		for (int i = 1; i <= x; ++i)
			if (!(mask & (1LL << i)))
				pos[get(x - i, mask | (1LL << i))] = false;
		for (int i = 0; i < S; ++i)
			if (pos[i])
			{
				mex[state] = i;
				break;
			}
	}
	return mex[state];
}

int arr[S];
void init()
{
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	arr[4] = 2;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 3;
	arr[8] = 3;
	arr[9] = 3;
	arr[10] = 4;
	arr[11] = 4;
	arr[12] = 4;
	arr[13] = 4;
	arr[14] = 4;
	arr[15] = 5;
	arr[16] = 5;
	arr[17] = 5;
	arr[18] = 5;
	arr[19] = 5;
	arr[20] = 5;
	arr[21] = 6;
	arr[22] = 6;
	arr[23] = 6;
	arr[24] = 6;
	arr[25] = 6;
	arr[26] = 6;
	arr[27] = 6;
	arr[28] = 7;
	arr[29] = 7;
	arr[30] = 7;
	arr[31] = 7;
	arr[32] = 7;
	arr[33] = 7;
	arr[34] = 7;
	arr[35] = 7;
	arr[36] = 8;
	arr[37] = 8;
	arr[38] = 8;
	arr[39] = 8;
	arr[40] = 8;
	arr[41] = 8;
	arr[42] = 8;
	arr[43] = 8;
	arr[44] = 8;
	arr[45] = 9;
	arr[46] = 9;
	arr[47] = 9;
	arr[48] = 9;
	arr[49] = 9;
	arr[50] = 9;
	arr[51] = 9;
	arr[52] = 9;
	arr[53] = 9;
	arr[54] = 9;
	arr[55] = 10;
	arr[56] = 10;
	arr[57] = 10;
	arr[58] = 10;
	arr[59] = 10;
	arr[60] = 10;

}

void solve()
{
	init();
	scanf("%d", &n);
	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		int s;
		scanf("%d", &s);
		x ^= arr[s];
		//x ^= get(s, 0);
	}
	//for (int i = 1; i <= 60; ++i)
	//	printf("arr[%d] = %d;\n", i, get(i, 0));
	//printf("%d\n", mex.size());
	puts(x ? "NO" : "YES");
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
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef ST
	while(true)
		solve();
#endif
#ifdef CASES
#define MULTITEST
#endif
#ifdef MULTITEST
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
#ifdef CASES
		printf("Case #%d: ", i + 1);
#endif
		solve();
#ifdef CASES
		//eprintf("Passed case #%d:\n", i + 1);
#endif
	}
#else
		solve();
#endif

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}