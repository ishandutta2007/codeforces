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

const int N = (int)1e6 + 77;
int g[N];
int a[N];
bool used[N];
int n;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		g[n - i] = a[i] + (n - i);
	}
	for (int i = 1; i <= n; i++)
		used[i] = false;
	int x = 1;
	for (int i = 0; i < n; i++)
		x = g[x];
	int cnt = 0;
	while(!used[x]) {
		used[x] = 1;
		cnt++;
		x = g[x];
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		if (used[n - i])
			printf("%d ", i + 1);
	printf("\n");
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