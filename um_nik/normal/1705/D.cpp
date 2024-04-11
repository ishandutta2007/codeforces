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

const int N = 500500;
char s[N], t[N];
vector<int> a, b;
int n;

void solve() {
	scanf("%d", &n);
	scanf("%s %s", s, t);
	a.clear();
	b.clear();
	if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
		printf("-1\n");
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) a.push_back(i);
		if (t[i] != t[i + 1]) b.push_back(i);
	}
	if ((int)a.size() != (int)b.size()) {
		printf("-1\n");
		return;
	}
	ll ans = 0;
	for (int i = 0; i < (int)a.size(); i++)
		ans += abs(a[i] - b[i]);
	printf("%lld\n", ans);
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