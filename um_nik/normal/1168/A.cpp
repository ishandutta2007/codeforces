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

const int N = 300300;
int n, m;
int a[N];

bool solve(int x) {
	int y = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= y && y <= a[i] + x) {

		} else if (y + m <= a[i] + x) {

		} else if (a[i] <= y) {
			return false;
		} else {
			y = a[i];
		}
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int l = -1, r = m;
	while(r - l > 1) {
		int x;
		x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	printf("%d\n", r);

	return 0;
}