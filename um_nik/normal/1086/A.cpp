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

const int N = 1002;
int ans = (int)1e7;
int a[3][2];
int X, Y;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++) {
			int cur = 0;
			for (int i = 0; i < 3; i++)
				cur += abs(x - a[i][0]) + abs(y - a[i][1]);
			if (cur < ans) {
				ans = cur;
				X = x;
				Y = y;
			}
		}
	printf("%d\n", ans + 1);
	printf("%d %d\n", X, Y);
	for (int i = 0; i < 3; i++) {
		int x = a[i][0], y = a[i][1];
		while(x > X) {
			printf("%d %d\n", x, y);
			x--;
		}
		while(x < X) {
			printf("%d %d\n", x, y);
			x++;
		}
		while(y > Y) {
			printf("%d %d\n", x, y);
			y--;
		}
		while(y < Y) {
			printf("%d %d\n", x, y);
			y++;
		}
	}

	return 0;
}