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

const int N = 300300;
char s[N];
int a[N];
int n, k;

bool solve() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < k; i++)
		a[i] = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') continue;
		int x = (int)(s[i] - '0');
		int p = i % k;
		if (a[p] == -1) a[p] = x;
		if (a[p] != x) return false;
	}
	int s1 = 0, s2 = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] == 0)
			s1++;
		if (a[i] == 1)
			s2++;
	}
	return s1 <= k / 2 && s2 <= k / 2;
} 

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}