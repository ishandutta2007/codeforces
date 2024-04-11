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

vector<int> factorize(int x) {
	vector<int> ans;
	for (int y = 2; y * y <= x; y++) {
		if (x % y) continue;
		while(x % y == 0) {
			ans.push_back(y);
			x /= y;
		}
	}
	if (x > 1) ans.push_back(x);
	return ans;
}

bool solve() {
	int n, d;
	scanf("%d%d", &n, &d);
	int k = 0;
	while(n % d == 0) {
		n /= d;
		k++;
	}
	if (k < 2) return false;
	vector<int> nf = factorize(n);
	if ((int)nf.size() >= 2) return true;
	vector<int> df = factorize(d);
	if (k == 2) return false;
	if ((int)df.size() == 1) return false;
	if (df[0] != df.back()) return true;
	if ((int)df.size() >= 3) return true;
	if (k == 3 && (int)nf.size() == 1 && nf.back() == df.back()) return false;
	return true;
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