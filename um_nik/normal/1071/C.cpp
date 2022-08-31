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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 12;
const int N = 100100;
const int M = 100;
int n;
int a[N];
int ans[N][3];
int ansSz;
int g[M][M];
int tr[M][3];
int b[M];

void addAns(int x, int y, int z) {
	if (2 * y != x + z) throw;
	a[x] ^= 1;
	a[y] ^= 1;
	a[z] ^= 1;
	ans[ansSz][0] = x + 1;
	ans[ansSz][1] = y + 1;
	ans[ansSz][2] = z + 1;
	ansSz++;
}

bool doLeft(int L) {
	if (!a[L]) throw;
	if (a[L + 1] && a[L + 2]) {
		addAns(L, L + 1, L + 2);
	} else if (a[L + 1] && !a[L + 2]) {
		return false;
	} else if (!a[L + 1] && a[L + 2]) {
		addAns(L, L + 2, L + 4);
	} else if (!a[L + 1] && !a[L + 2]) {
		addAns(L, L + 3, L + 6);
	} else throw;
	return true;
}
bool doRight(int R) {
	if (!a[R]) throw;
	if (a[R - 1] && a[R - 2]) {
		addAns(R - 2, R - 1, R);
	} else if (a[R - 1] && !a[R - 2]) {
		return false;
	} else if (!a[R - 1] && a[R - 2]) {
		addAns(R - 4, R - 2, R);
	} else if (!a[R - 1] && !a[R - 2]) {
		addAns(R - 6, R - 3, R);
	} else throw;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int L = 0, R = n - 1;
	while(R - L > K) {
		if (!a[L]) {
			L++;
			continue;
		}
		if (!a[R]) {
			R--;
			continue;
		}
		if (doLeft(L)) {
			L += 3;
			continue;
		}
		if (doRight(R)) {
			R -= 3;
			continue;
		}
		if ((L + R) % 2 == 0) {
			addAns(L, (L + R) / 2, R);
			addAns(L + 1, (L + R) / 2, R - 1);
		} else {
			addAns(L, (L + R - 1) / 2, R - 1);
			addAns(L + 1, (L + 1 + R) / 2, R);
		}
		L += 3;
		R -= 3;
	}
	while(R - L < K && L > 0) L--;
	while(R - L < K && R < n - 1) R++;
	R++;

	int m = R - L;
	int s = 0;
	for (int d = 1; d < m; d++)
		for (int i = 0; i + 2 * d < m; i++) {
			tr[s][0] = L + i;
			tr[s][1] = L + i + d;
			tr[s][2] = L + i + 2 * d;
			for (int j = 0; j < 3; j++)
				g[tr[s][j] - L][s] = 1;
			s++;
		}
	for (int i = 0; i < m; i++)
		g[i][s] = a[L + i];
	for (int i = 0; i < s; i++)
		b[i] = -1;
	int k = 0;
	for (int i = 0; i < s; i++) {
		int v = -1;
		for (int j = k; j < m; j++) {
			if (g[j][i]) {
				v = j;
				break;
			}
		}
		if (v == -1) continue;
		swap(g[v], g[k]);
		b[i] = k;
		for (int j = 0; j < m; j++) {
			if (j == k) continue;
			if (!g[j][i]) continue;
			for (int h = 0; h <= s; h++)
				g[j][h] ^= g[k][h];
		}
		k++;
	}
	for (int i = k; i < m; i++)
		if (g[i][s]) {
			printf("NO\n");
			return 0;
		}
	for (int i = 0; i < s; i++) {
		if (b[i] == -1 || !g[b[i]][s]) continue;
		addAns(tr[i][0], tr[i][1], tr[i][2]);
	}
	printf("YES\n");
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);

	return 0;
}