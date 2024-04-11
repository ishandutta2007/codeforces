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
int n;
int a[N];

void printAns(int x) {
	if (x == 0) {
		printf("sjfnb\n");
	} else {
		printf("cslnb\n");
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int m = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] == a[i + 1])
			m++;
	if (m > 1) {
		printAns(1);
		return 0;
	}
	if (m == 1) {
		int p = 0;
		while(a[p] != a[p + 1]) p++;
		if (a[p] == 0 || (p > 0 && a[p - 1] == a[p] - 1)) {
			printAns(1);
			return 0;
		}
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		s ^= (a[i] & 1);
		s ^= i & 1;
	}
	printAns(s ^ 1);

	return 0;
}