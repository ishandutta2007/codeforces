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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll X, S;
	scanf("%lld%lld", &X, &S);
	if (X > S || (S - X) % 2 == 1) {
		printf("-1\n");
		return 0;
	}
	if (S == 0) {
		printf("0\n");
		return 0;
	}
	if (X == S) {
		printf("1\n");
		printf("%lld\n", X);
		return 0;
	}
	ll A = (S - X) / 2;
	if ((A & X) == 0) {
		printf("2\n");
		printf("%lld %lld\n", A, X + A);
		return 0;
	}
	printf("3\n");
	printf("%lld %lld %lld", X, A, A);

	return 0;
}