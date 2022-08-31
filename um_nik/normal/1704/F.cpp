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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = 400;
int g[N];
bool mex[N];

const int M = 500500;
char s[M];
int n;

void solve() {
	scanf("%d %s", &n, s);
	int B = 0, X = 0;
	int l = 0;
	while(l < n) {
		int r = l + 1;
		while(r < n && s[r] != s[r - 1]) r++;
		if ((r - l) & 1) {
			if (s[l] == 'R')
				B++;
			else
				B--;
		}
		int z = (r - l);
		if (z >= 340) z = 340 + (z % 34);
		X ^= g[z];
		l = r;
	}
	eprintf("B = %d, X = %d\n", B, X);
	if (B != 0) {
		if (B > 0) {
			printf("Alice\n");
		} else {
			printf("Bob\n");
		}
	} else {
		if (X > 0) {
			printf("Alice\n");
		} else {
			printf("Bob\n");
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int n = 2; n < N; n++) {
		for (int i = 0; i < N; i++)
			mex[i] = 0;
		for (int i = 0; i <= n - 2; i++)
			mex[g[i] ^ g[n - 2 - i]] = 1;
		g[n] = 0;
		while(mex[g[n]]) g[n]++;
	}

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}