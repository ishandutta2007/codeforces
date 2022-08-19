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

const int N = 505;
int n, m;
char s[N];
pii a[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			s[j] = '0';
		s[i] = '1';
		printf("? %s\n", s);
		fflush(stdout);
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++)
		s[i] = '0';
	int w = 0;
	for (int i = 0; i < m; i++) {
		s[a[i].second] = '1';
		printf("? %s\n", s);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x == w + a[i].first) {
			w = x;
		} else {
			s[a[i].second] = '0';
		}
	}
	printf("! %d\n", w);

	return 0;
}