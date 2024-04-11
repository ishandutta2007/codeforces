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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

int n, m;
int a[20][2];
int b[20][2];
bool canBe[10];

int solve(int A, int B, int C, int D) {
	if (A == C && B == D) return -1;
	if (A == C) return A;
	if (A == D) return A;
	if (B == C) return B;
	if (B == D) return B;
	return -1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
		if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++)
			scanf("%d", &b[i][j]);
		if (b[i][0] > b[i][1]) swap(b[i][0], b[i][1]);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x = solve(a[i][0], a[i][1], b[j][0], b[j][1]);
			if (x != -1)
				canBe[x] = 1;
		}
	int cnt = 0;
	for (int i = 0; i < 10; i++)
		cnt += canBe[i];
	if (cnt == 0) throw;
	if (cnt == 1) {
		for (int i = 0; i < 10; i++)
			if (canBe[i])
				printf("%d\n", i);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int ans = -1;
		for (int j = 0; j < m; j++) {
			int x = solve(a[i][0], a[i][1], b[j][0], b[j][1]);
			if (x == -1) continue;
			if (ans == -1) ans = x;
			if (ans != x) ans = -2;
		}
		if (ans == -2) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int ans = -1;
		for (int j = 0; j < n; j++) {
			int x = solve(a[j][0], a[j][1], b[i][0], b[i][1]);
			if (x == -1) continue;
			if (ans == -1) ans = x;
			if (ans != x) ans = -2;
		}
		if (ans == -2) {
			printf("-1\n");
			return 0;
		}
	}
	printf("0\n");

	return 0;
}