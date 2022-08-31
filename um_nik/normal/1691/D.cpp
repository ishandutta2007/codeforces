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

const int N = 200200;
int n;
ll a[N];
ll pref[N];
int st1[N], st2[N];
int sz1, sz2;

bool check() {
	pref[0] = 0;
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + a[i];
	sz1 = sz2 = -1;
	for (int i = 0; i < n; i++) {
		while(sz1 >= 0 && a[i] >= a[st1[sz1]]) sz1--;
		while(sz2 >= 0 && pref[i] <= pref[st2[sz2]]) sz2--;
		if (sz2 >= 0 && (sz1 < 0 || st2[sz2] > st1[sz1])) return false;
		st1[++sz1] = i;
		st2[++sz2] = i;
	}
	return true;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	if (!check()) {
		printf("No\n");
		return;
	}
	reverse(a, a + n);
	if (!check()) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
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