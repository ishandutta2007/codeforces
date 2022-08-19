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

const int N = 200003;
const int K = 200;
int g[N];
int d[N];
bitset<N> mex[K];
bitset<N> mv;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		d[i] = -1;
	for (int i = 2; i < N; i++) {
		if (d[i] != -1) continue;
		for (int x = i; x < N; x += i)
			if (d[x] == -1)
				d[x] = i;
	}
	for (int x = 2; x < N; x++) {
		if (x == d[x] || d[x / d[x]] == x / d[x])
			mv[x] = 1;
	}

	int n, f;
	scanf("%d%d", &n, &f);
	mv[f] = 0;

	mex[0] |= mv;
	for (int i = 1; i < N; i++) {
		while(mex[g[i]][i]) {
			g[i]++;
			if (g[i] == K) {
//				cerr << i << endl;
				throw;
			}
		}
//		eprintf("%d %d\n", i, g[i]);
		mex[g[i]] |= mv << i;
	}

	int ans = 0;
	while(n--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x = y - x - 1;
		z = z - y - 1;
		ans ^= g[x] ^ g[z];
	}
	if (ans == 0) {
		printf("Bob\nAlice\n");
	} else {
		printf("Alice\nBob\n");
	}

	return 0;
}