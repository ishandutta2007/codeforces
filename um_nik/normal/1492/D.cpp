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

const int N = 400400;
int n, a, b, k;
char s[N], p[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &a, &b, &k);
	n = a + b;
	for (int i = 0; i < n; i++)
		s[i] = p[i] = '0';
	s[n] = p[n] = '\0';
	if (k == 0) {
		for (int i = 0; i < b; i++)
			s[i] = p[i] = '1';
		printf("Yes\n%s\n%s\n", s, p);
		return 0;
	}
	if (a == 0 || b == 1) {
		printf("No\n");
		return 0;
	}
	if (k >= n - 1) {
		printf("No\n");
		return 0;
	}
	s[0] = p[0] = '1';
	s[1] = p[1 + k] = '1';
	b -= 2;
	for (int i = 2; b > 0 && i < n; i++) {
		if (i == 1 + k) continue;
		s[i] = p[i] = '1';
		b--;
	}
	printf("Yes\n%s\n%s\n", s, p);

	return 0;
}