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

const int N = 200200;
const int A = 10;
char s[N];
int a[N];
int ans;
int n;

int solveOne(int x) {
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			ans++;
	return ans;
}
int solveTwo(int x, int y) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans & 1) {
			if (a[i] == y)
				ans++;
		} else {
			if (a[i] == x)
				ans++;
		}
	}
	ans -= (ans & 1);
	return ans;
}

void solve() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[i] = (int)(s[i] - '0');
	ans = 0;
	for (int i = 0; i < A; i++)
		ans = max(ans, solveOne(i));
	for (int i = 0; i < A; i++)
		for (int j = 0; j < A; j++)
			if (i != j)
				ans = max(ans, solveTwo(i, j));
	printf("%d\n", n - ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}