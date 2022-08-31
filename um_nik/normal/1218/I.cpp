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

const int N = 2020;
bool a[N][N];
bool aa[N][N];
bool b[N];
char s[N];
int n;
int ans[2 * N][2];
int ansSz;
int d;

void addAns(int x, int y) {
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ansSz++;
}

void printAns() {
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++) {
		if (ans[i][0] == 0)
			printf("row %d\n", ans[i][1]);
		else
			printf("col %d\n", ans[i][1]);
	}
	exit(0);
}

bool checkCorrect() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j])
				return false;
	return true;
}

void apply(int x, int y) {
	addAns(x, y);
	if (x == 0) {
		for (int i = 0; i < n; i++)
			a[y][i] ^= b[i];
	} else {
		for (int i = 0; i < n; i++)
			a[i][y] ^= b[i];
	}
}

void solve(int X) {
	ansSz = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = aa[i][j];
	if (X) {
		apply(0, d);
	}
	for (int i = 0; i < n; i++) {
		if (a[d][i]) {
			apply(1, i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i][d]) {
			apply(0, i);
		}
	}
	if (checkCorrect()) {
		printAns();
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			for (int j = 0; j < n; j++)
				if (s[j] == '1')
					a[i][j] ^= 1;
		}
	}
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		if (s[i] == '1')
			b[i] = 1;
/*	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			eprintf("%d", (int)a[i][j]);
		eprintf("\n");
	}
*/	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			aa[i][j] = a[i][j];
	if (checkCorrect()) {
		printAns();
	}
	d = -1;
	for (int i = 0; d == -1 && i < n; i++)
		if (b[i])
			d = i;

	if (d == -1) {
		printf("-1\n");
		return 0;
	}

	for (int k = 0; k < 2; k++)
		solve(k);

	printf("-1\n");

	return 0;
}