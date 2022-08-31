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

const int N = 66;
char s[N][N];
int n, m;

bool check(int t, int x) {
	if (t == 0) {
		for (int i = 0; i < m; i++)
			if (s[x][i] != 'A')
				return false;
	} else {
		for (int i = 0; i < n; i++)
			if (s[i][x] != 'A')
				return false;
	}
	return true;
}
int solve() {
	scanf("%d%d", &n, &m);
	int A = 0, P = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'A')
				A++;
			else
				P++;
		}
	}
	if (A == 0) return -1;
	if (P == 0) return 0;
	if (check(0, 0) || check(0, n - 1) || check(1, 0) || check(1, m - 1)) return 1;
	if (s[0][0] == 'A' || s[0][m - 1] == 'A' || s[n - 1][0] == 'A' || s[n - 1][m - 1] == 'A') return 2;
	for (int i = 0; i < n; i++)
		if (check(0, i))
			return 2;
	for (int i = 0; i < m; i++)
		if (check(1, i))
			return 2;
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < m - 1; j++)
			if (s[i][j] == 'A')
				A--;
	if (A > 0)
		return 3;
	return 4;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		int ans = solve();
		if (ans == -1) {
			printf("MORTAL\n");
		} else {
			printf("%d\n", ans);
		}
	}

	return 0;
}