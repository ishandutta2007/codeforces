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

const int N = 555;
int n, m;
int a[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int x;
				scanf("%d", &x);
				a[i][j] ^= x;
			}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			if (a[i][j]) {
				a[0][0] ^= 1;
				a[i][0] ^= 1;
				a[0][j] ^= 1;
				a[i][j] ^= 1;
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				printf("No\n");
				return 0;
			}
		}
	printf("Yes\n");

	return 0;
}