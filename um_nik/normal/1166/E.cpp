#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
7 7
1 2 5
3 4 5
1 3 6
2 4 6
1 4 7
2 3 7
5 6 7
*/

const int M = 52;
const int N = (int)1e4 + 3;
int m, n;
int a[M][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
		int z;
		scanf("%d", &z);
		while(z--) {
			int x;
			scanf("%d", &x);
			x--;
			a[i][x] = 1;
		}
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j <= i; j++) {
			bool ok = false;
			for (int k = 0; k < n; k++)
				ok |= a[i][k] == 1 && a[j][k] == 1;
			if (!ok) {
				printf("impossible\n");
				return 0;
			}
		}
	printf("possible\n");

	return 0;
}