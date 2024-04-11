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

const int N = 5003;
const int M = 1001;
int d[N];
int pr[M];
int m;
int a[N][M];
int b[N][M];
int cnt[N];
ll curAns;

void precalc() {
	m = 1;
	for (int x = 2; x < N; x++) {
		if (d[x] != 0) continue;
		pr[m] = x;
		for (int y = x; y < N; y += x)
			d[y] = m;
		m++;
	}
	for (int x = 2; x < N; x++) {
		int z = x;
		while(z > 1) {
			a[x][d[z]]++;
			z /= pr[d[z]];
		}
		for (int i = 0; i <= m; i++)
			a[x][i] += a[x - 1][i];
	}
	for (int x = 1; x < N; x++) {
		b[x][m] = 0;
		for (int i = m - 1; i >= 0; i--)
			b[x][i] = b[x][i + 1] + a[x][i];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	precalc();
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) x = 1;
		cnt[x]++;
	}

	curAns = 0;
	for (int x = 1; x < N; x++)
		curAns += (ll)b[x][0] * cnt[x];

	int curP = m - 1;
	int curH = 0;
	int sumH = 0;
	while(curP >= 0) {
		int tot = 0;
		int nextH = (int)1e9;
		for (int x = 1; x < N; x++) {
			if (cnt[x] == 0) continue;
			if (b[x][curP + 1] != sumH || a[x][curP] <= curH) continue;
			tot += cnt[x];
			nextH = min(nextH, a[x][curP]);
		}
		if (2 * tot > n) {
			curAns -= (ll)(2 * tot - n) * (nextH - curH);
			curH = nextH;
		} else {
			sumH += curH;
			curH = 0;
			curP--;
		}
	}
	printf("%lld\n", curAns);

	return 0;
}