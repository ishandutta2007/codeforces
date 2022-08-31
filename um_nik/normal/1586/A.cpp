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

const int N = 101010;
bool p[N];
int n;
int a[N];

void printAns(int p) {
	printf("%d\n", n - (p != -1));
	for (int i = 0; i < n; i++)
		if (i != p)
			printf("%d ", i + 1);
	printf("\n");
}

void solve() {
	scanf("%d", &n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	if (!p[s]) {
		printAns(-1);
		return;
	}
	for (int i = 0; i < n; i++)
		if (!p[s - a[i]]) {
			printAns(i);
			return;
		}
	assert(false);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p[i] = 1;
	for (int i = 2; i < N; i++) {
		if (!p[i]) continue;
		for (int j = 2 * i; j < N; j += i)
			p[j] = 0;
	}

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}