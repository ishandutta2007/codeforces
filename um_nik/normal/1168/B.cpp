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

/*
int a[30];
int n;

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; i + 2 * j < n; j++) {
			if (a[i] == a[i + j] && a[i] == a[i + 2 * j])
				return true;
		}
	}
	return false;
}
*/

const int N = 300300;
int n;
char s[N];
ll ans;

bool check(int l, int r) {
	for (int i = l; i < r; i++)
		for (int j = 1; i + 2 * j < r; j++) {
			if (s[i] == s[i + j] && s[i] == s[i + 2 * j])
				return true;
		}
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

/*
	n = 10;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++)
			a[i] = (mask >> i) & 1;
		if (!check())
			printf("%d\n", mask);
	}
*/

	scanf("%s", s);
	n = strlen(s);
	ans = (ll)n * (n + 1) / 2;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			if (j - i == 9) break;
			if (!check(i, j + 1))
				ans--;
		}
	printf("%lld\n", ans);

	return 0;
}