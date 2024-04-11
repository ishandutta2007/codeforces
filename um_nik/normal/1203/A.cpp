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

const int N = 222;
int n;
int a[N];

bool check() {
	for (int i = 0; i < n; i++)
		if (a[i] != i + 1)
			return false;
	return true;
}

bool solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int it = 0; it < n; it++) {
		if (check()) return true;
		reverse(a, a + n);
		if (check()) return true;
		reverse(a, a + n);
		rotate(a, a + 1, a + n);
	}
	return false;
}

bool solve_fast() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int pos = 0;
	while(a[pos] != 1) pos++;
	rotate(a, a + pos, a + n);
	if (check()) return true;
	reverse(a, a + n);
	pos = 0;
	while(a[pos] != 1) pos++;
	rotate(a, a + pos, a + n);
	if (check()) return true;
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve_fast())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}