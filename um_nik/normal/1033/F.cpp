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

const int N = 13;
const int M = (1 << 12) + 7;
const int S = 550500;
int pw3[N];
int a[M];
int b[S];
int n, m, k;
char s[N];
int c[N];
int d[6][2];
int ANS = 0;

int getOp(char op) {
	if (op == 'A') return 0;
	if (op == 'O') return 1;
	if (op == 'X') return 2;
	if (op == 'a') return 3;
	if (op == 'o') return 4;
	if (op == 'x') return 5;
	throw;
}


void brute1(int pos, int mask2, int mask3, int toAdd) {
	if (pos == k) {
		b[mask3] += toAdd;
		return;
	}
	brute1(pos + 1, mask2, mask3 + ((mask2 >> pos) & 1) * pw3[pos], toAdd);
	brute1(pos + 1, mask2, mask3 + 2 * pw3[pos], toAdd);
}

void brute2(int pos, int mask2, int mask3) {
	if (pos == k) {
		ANS += a[mask2] * b[mask3];
		return;
	}
	int op = c[pos];
	for (int x = 0; x < 2; x++) {
		if (d[op][x] == 3) continue;
		brute2(pos + 1, mask2 | (x << pos), mask3 + d[op][x] * pw3[pos]);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	pw3[0] = 1;
	for (int i = 1; i < N; i++)
		pw3[i] = pw3[i - 1] * 3;

	scanf("%d%d%d", &k, &n, &m);
	while(n--) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for (int mask = 0; mask < (1 << k); mask++)
		brute1(0, mask, 0, a[mask]);

	d[0][0] = 2;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 3;
	d[2][0] = 0;
	d[2][1] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			d[3 + i][j] = d[i][j] ^ 1;

	while(m--) {
		scanf("%s", s);
		for (int i = 0; i < k; i++)
			c[i] = getOp(s[i]);
		reverse(c, c + k);
		ANS = 0;
		brute2(0, 0, 0);
		printf("%d\n", ANS);
	}

	return 0;
}