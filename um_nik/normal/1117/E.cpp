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

const int N = 10101;
const int A = 26;
int n;
char s[N];
char a[3][N];
char b[3][N];
int p[N];


int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	for (int it = 0; it < 3; it++) {
		for (int i = 0; i < n; i++) {
			int x = i;
			for (int j = 0; j < it; j++)
				x /= A;
			x %= A;
			a[it][i] = 'a' + x;
		}
		a[it][n] = '\0';
		printf("? %s\n", a[it]);
		fflush(stdout);
		scanf("%s", b[it]);
	}

	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 2; j >= 0; j--) {
			x = A * x + (int)(b[j][i] - 'a');
		}
		assert(x < n);
		p[x] = i;
	}
	printf("! ");
	for (int i = 0; i < n; i++)
		printf("%c", s[p[i]]);
	printf("\n");
	fflush(stdout);

	return 0;
}