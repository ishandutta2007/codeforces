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

const int N = 10100;
int n, m;
int t;
int q[N];
int a[N];

int query(int l, int r) {
	printf("? %d %d\n", l + 1, r + 1);
	fflush(stdout);
	int tt;
	scanf("%d", &tt);
	return tt;
}

void apply(int l, int r) {
	for (int i = l; i < r; i++) {
		q[i] ^= 1;
		if (a[i] != -1)
			a[i] ^= 1;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++) {
		q[i] = 0;
		a[i] = -1;
	}
	int L = 0, R = n - 1;
	while(L < R) {
		while(true) {
			int nt = query(L, R - 1);
			if (((t ^ nt ^ R) & 1) == 0) { // pref
				apply(0, R);
				int sum = R;
				for (int i = R + 1; i < n; i++)
					sum += 2 * a[i];
				if (sum == t + nt) {
					a[R] = 0;
				} else if (sum + 2 == t + nt) {
					a[R] = 1;
				} else throw;
				t = nt;
				break;
			} else {
				apply(L, n);
				t = nt;
			}
		}
		while(true) {
			int nt = query(L + 1, R);
			if (((t ^ nt ^ (n - L - 1)) & 1) == 0) { // pref
				apply(L + 1, n);
				int sum = n - L - 1;
				for (int i = 0; i < L; i++)
					sum += 2 * a[i];
				if (sum == t + nt) {
					a[L] = 0;
				} else if (sum + 2 == t + nt) {
					a[L] = 1;
				} else throw;
				t = nt;
				break;
			} else {
				apply(0, R + 1);
				t = nt;
			}
		}
		L++;
		R--;
	}
	if (L == R) {
		for (int i = 0; i < n; i++) {
			if (i == L) continue;
			t -= a[i];
		}
		a[L] = t;
	}
	printf("! ");
	for (int i = 0; i < n; i++)
		printf("%d", a[i] ^ q[i]);
	printf("\n");
	fflush(stdout);

	return 0;
}