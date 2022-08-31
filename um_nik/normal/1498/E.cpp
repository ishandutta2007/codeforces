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

const int N = 505;
int n, m;
int a[N];
pair<int, pii> ord[N * N];
char s[10];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ord[m++] = mp(abs(a[i] - a[j]), mp(i, j));
	sort(ord, ord + m);
	reverse(ord, ord + m);
	for (int i = 0; i < m; i++) {
		int v = ord[i].second.first, u = ord[i].second.second;
		if (a[v] < a[u]) swap(v, u);
		v++;
		u++;
		printf("? %d %d\n", v, u);
		fflush(stdout);
		scanf("%s", s);
		if (s[0] == 'Y') {
			printf("! %d %d\n", v, u);
			fflush(stdout);
			return 0;
		}
	}
	printf("! 0 0\n");
	fflush(stdout);

	return 0;
}