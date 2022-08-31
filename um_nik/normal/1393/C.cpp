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

bool solve(vector<int> a, int n, int d) {
	if ((int)a.size() < d) return false;
	for (int i = 0; i < d; i++) {
		int x = n / d;
		if (i < n % d) x++;
		if (x < a[i]) return false;
	}
	return true;
}

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(all(a));
	vector<int> b;
	int l = 0;
	while(l < n) {
		int r = l + 1;
		while(r < n && a[r] == a[l]) r++;
		b.push_back(r - l);
		l = r;
	}
	sort(all(b));
	reverse(all(b));
	l = 1;
	int r = n;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(b, n, x))
			l = x;
		else
			r = x;
	}
	printf("%d\n", l - 1);
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