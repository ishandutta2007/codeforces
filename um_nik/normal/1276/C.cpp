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

const int N = 400400;
int a[N];
pii b[N];
int suff[N];
int n, m;

void printAns(int W, int H) {
	vector< vector<int> > t;
	t.resize(W);
	for (int i = 0; i < W; i++) {
		t[i].resize(H);
	}
	int sh = 0;
	int y = 0;
	for (int i = 0; i < m; i++) {
		int val = b[i].second;
		for (int it = 0; it < min(W, b[i].first); it++) {
			t[y][(y + sh) % H] = val;
			y++;
			if (y == W) {
				y = 0;
				sh++;
			}
		}
	}
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++)
			printf("%d ", t[i][j]);
		printf("\n");
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (m == 0 || b[m - 1].second != a[i]) {
			b[m++] = mp(1, a[i]);
		} else {
			b[m - 1].first++;
		}
	}
	sort(b, b + m);
	reverse(b, b + m);
	for (int i = m - 1; i >= 0; i--)
		suff[i] = suff[i + 1] + b[i].first;
	int pos = 0;
	int bestVal = 0, bestD = 0;
	for (int d = 1000; d > 0; d--) {
		while(pos < m && b[pos].first > d) pos++;
		int sum = pos * d + suff[pos];
		if (sum >= d * d) {
			int x = sum / d;
			if (x * d > bestVal) {
				bestVal = x * d;
				bestD = d;
			}
		}
	}
	if (bestVal == 0) throw;
	printf("%d\n", bestVal);
	printf("%d %d\n", bestD, bestVal / bestD);
	printAns(bestD, bestVal / bestD);

	return 0;
}