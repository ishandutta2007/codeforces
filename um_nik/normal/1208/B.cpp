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
int n;
int a[N];
int xs[N];
int m;
bool used[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		xs[i] = a[i];
	}
	sort(xs, xs + n);
	m = unique(xs, xs + n) - xs;
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(xs, xs + m, a[i]) - xs;
	int ans = n;
	for (int l = 0; l <= n; l++) {
		for (int i = 0; i < m; i++)
			used[i] = 0;
		bool ok = true;
		for (int i = 0; i < l; i++) {
			if (used[a[i]]) {
				ok = false;
				break;
			}
			used[a[i]] = 1;
		}
		if (!ok) break;
		int r = n - 1;
		while(r > l && !used[a[r]]) {
			used[a[r]] = 1;
			r--;
		}
		ans = min(ans, r - l + 1);
	}
	printf("%d\n", ans);

	return 0;
}