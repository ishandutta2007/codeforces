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

const int N = 400200;
const int K = 18;
char s[N];
int a[N];
int pref[K][N];
int n, q;

int getSum(int k, int l, int r) {
	return pref[k][r] - pref[k][l];
}

void solve() {
	int l, r;
	scanf("%d%d", &l, &r);
	r++;
	int ans = 0;
	for (int k = 0; (1 << k) < (r - l); k++) {
		int x =  getSum(k + 1, l + (1 << k), r + (1 << k));
		int z = (r - l) >> (k + 1);
		ans += min(x, z - x);
	}
	printf("%d\n", (ans + 1) / 2);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 1; i < n; i++) {
		a[i] = (int)(s[i - 1] - '0') ^ (int)(s[i] - '0');
	}
	for (int k = 0; k < K; k++)
		for (int i = 0; i <= n; i++)
			pref[k][i + (1 << k)] = pref[k][i] + a[i];

	scanf("%d", &q);
	while(q--) solve();

	return 0;
}