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

const int N = 1010;
int a[N];
int n, s;

bool solve() {
	if ((a[0] & 1) == 0) return false;
	if (a[s] & 1) return true;
	if (a[s] == 0) return false;
	for (int i = s + 1; i < n; i++)
		if (a[i] == 3)
			return true;
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &s);
	s--;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[i] |= x;
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[i] |= (x << 1);
	}
	if (solve())
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}