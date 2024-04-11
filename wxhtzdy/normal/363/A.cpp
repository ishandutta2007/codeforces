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
#include <iomanip>
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

char s[10];

int main()
{
	startTime = clock();

	scanf("%s", s);
	int n = strlen(s);
	reverse(s, s + n);
	for (int i = 0; i < n; i++) {
		int c = s[i] - '0';
		string t = "O-|-OOOO";
		if (c >= 5) {
			swap(t[0], t[1]);
			c -= 5;
		}
		if (c > 0) {
			swap(t[3], t[4]);
			c--;
		}
		if (c > 0) {
			swap(t[4], t[5]);
			c--;
		}
		if (c > 0) {
			swap(t[5], t[6]);
			c--;
		}
		if (c > 0) {
			swap(t[6], t[7]);
			c--;
		}
		printf("%s\n", t.c_str());
	}
	return 0;
}