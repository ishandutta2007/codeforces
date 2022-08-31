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
bool p[N];
vector<int> a;

void solve() {
	int n;
	scanf("%d", &n);
	if (n <= a[0] + a[1] + a[2]) {
		printf("NO\n");
		return;
	}
	for (int i = 0; a[i] < n; i++)
		for (int j = i + 1; a[i] + a[j] < n; j++)
			for (int k = j + 1; a[i] + a[j] + a[k] < n; k++) {
				int x = n - a[i] - a[j] - a[k];
				if (x == a[i] || x == a[j] || x == a[k]) continue;
				printf("YES\n");
				printf("%d %d %d %d\n", a[i], a[j], a[k], x);
				return;
			}
	printf("NO\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++) {
		p[i] = true;
	}
	for (int i = 2; i < N; i++) {
		if (!p[i]) continue;
		for (int j = 2 * i; j < N; j += i)
			p[j] = false;
	}
	for (int x = 2; x * x < N; x++) {
		if (!p[x]) continue;
		for (int y = x + 1; x * y < N; y++)
			if (p[y])
				a.push_back(x * y);
	}
	sort(all(a));

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}