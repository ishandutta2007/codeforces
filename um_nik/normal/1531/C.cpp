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

const int S = 13;
char a[S][S];
int n, m;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	if (n == 2) {
		printf("-1\n");
		return 0;
	}
	m = 1;
	while(m * m < n) m++;
	if (m * m - 2 == n) {
		m++;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++)
				a[i][j] = 'o';
			a[i][m] = '\0';
		}
		for (int i = 1; i < m; i++)
			a[0][i] = '.';
		for (int i = 1; i < m - 1; i++)
			a[i][m - 1] = '.';
		for (int i = 1; i < 3; i++)
			for (int j = m - 3; j < m - 1; j++)
				a[i][j] = '.';
		printf("%d\n", m);
		for (int i = 0; i < m; i++)
			printf("%s\n", a[i]);
	} else if (m * m == n) {
		printf("%d\n", m);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++)
				printf("o");
			printf("\n");
		}
	} else {
		n = m * m - n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++)
				a[i][j] = 'o';
			a[i][m] = '\0';
		}
		a[0][m - 1] = '.';
		n--;
		if (n & 1) {
			a[1][m - 2] = '.';
			n--;
		}
		n /= 2;
		while(n > 0) {
			a[0][m - 1 - n] = '.';
			a[n][m - 1] = '.';
			n--;
		}
		printf("%d\n", m);
		for (int i = 0; i < m; i++)
			printf("%s\n", a[i]);
	}

	return 0;
}