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

const int N = 500200;
const int A = 26;
int n;
char a[N], b[N];
ll c[A], d[A];
double ans;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			ans += (ll)(i + 1) * (n - i);
		}
		int x = (int)(a[i] - 'A'), y = (int)(b[i] - 'A');
		ans += c[y] * (n - i);
		ans += d[x] * (n - i);
		c[x] += i + 1;
		d[y] += i + 1;
	}
	ll Q = 0;
	for (int i = 1; i <= n; i++)
		Q += (ll)i * i;
	printf("%.14lf\n", (double)ans / Q);

	return 0;
}