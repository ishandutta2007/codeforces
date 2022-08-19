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

const int K = 30;
const int N = (int)3e6 + 55;
int go[N][2];
int n, m;
int ans = 1 << K;

void dfs(int v, int cur, int k) {
	k--;
	if (k < 0) {
		ans = min(ans, cur);
		return;
	}
	for (int i = 0; i < 2; i++) {
		if (go[v][i] == -1) continue;
		dfs(go[v][i], cur + (go[v][i ^ 1] == -1 ? 0 : (1 << k)), k);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		go[i][0] = go[i][1] = -1;
	m = 1;

	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		int v = 0;
		for (int k = K - 1; k >= 0; k--) {
			int c = (x >> k) & 1;
			if (go[v][c] == -1) go[v][c] = m++;
			v = go[v][c];
		}
	}

	dfs(0, 0, K);
	printf("%d\n", ans);

	return 0;
}