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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const int MOD = 31607;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return (x * y) % MOD;
}
int bin_pow(int x, int p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
int rev(int x) {
	return bin_pow(x, MOD - 2);
}

bool isPrime(int x) {
	for (int y = 2; y * y <= x; y++)
		if (x % y == 0)
			return false;
	return true;
}

const int N = 21;
const int M = (1 << 21) + 3;
int R;
int a[N][N];
int ans;
int b[N][M];
int c[N];
int n;

void read() {
	/*
	n = 21;
	for (int i = 0; i < 10000; i++) {
		int x = myRand(n), y = myRand(n);
		a[x][y] = add(a[x][y], R);
	}
	*/
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			a[i][j] = mult(a[i][j], R);
		}
	}
	
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

//	printf("%d\n", (int)isPrime(MOD));

	R = rev(10000);

	read();

	for (int i = 0; i < n; i++) {
		c[i] = 1;
		for (int j = 0; j < n; j++)
			c[i] = mult(c[i], a[j][i]);
	}
	for (int i = 0; i < n; i++) {
		b[i][0] = 1;
		for (int mask = 1; mask < (1 << n); mask++) {
			int k = 0;
			while(((mask >> k) & 1) == 0) k++;
			b[i][mask] = mult(b[i][mask ^ (1 << k)], a[i][k]);
		}
		for (int mask = 0; mask < (1 << n); mask++)
			b[i][mask] = sub(1, b[i][mask]);
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		int initVal = 1;
		int ppc = 0;
		for (int i = 0; i < n; i++) {
			if (((mask >> i) & 1) == 0) continue;
			initVal = mult(initVal, c[i]);
			ppc ^= 1;
		}
		if (ppc) initVal = sub(0, initVal);
		for (int f = 0; f < 2; f++)
			for (int g = 0; g < 2; g++) {
				int curVal = initVal;
				if (f ^ g) curVal = sub(0, curVal);
				if (f + g > 0) {
					for (int i = 0; i < n; i++) {
						if ((mask >> i) & 1) continue;
						if ((n & 1) && i == n / 2) {
							curVal = mult(curVal, a[n / 2][n / 2]);
						} else {
							if (f) curVal = mult(curVal, a[i][i]);
							if (g) curVal = mult(curVal, a[n - 1 - i][i]);
						}
					}
				}
				for (int i = 0; i < n; i++) {
					int curMask = mask;
					if (f) curMask |= 1 << i;
					if (g) curMask |= 1 << (n - 1 - i);
					curMask ^= (1 << n) - 1;
					curVal = mult(curVal, b[i][curMask]);
				}
				ans = add(ans, curVal);
			}
	}
	printf("%d\n", sub(1, ans));

	return 0;
}