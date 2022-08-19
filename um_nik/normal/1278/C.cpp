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

const int N = 100100;
const int M = 2 * N;
int n;
int a[N];
int b[N];
int ansForBal[M];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	reverse(b, b + n);
	for (int i = 0; i <= 2 * n; i++)
		ansForBal[i] = -1;
	int bal = n;
	for (int i = 0; i <= n; i++) {
		ansForBal[bal] = i;
		if (i == n) break;
		bal += (b[i] == 1 ? 1 : -1);
	}
	int ans = 0;
	bal = -n;
	for (int i = 0; i <= n; i++) {
		int cur = ansForBal[-bal];
		if (cur != -1) ans = max(ans, i + cur);
		if (i == n) break;
		bal += (a[i] == 1 ? 1 : -1);
	}
	printf("%d\n", 2 * n - ans);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}