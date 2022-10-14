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

const int N = 200050;
int n;
int a[N];
int b[N];
int cnt[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	int i = n - 1, j = n - 1;
	while(i >= 0 || j >= 0) {
		if (j > 0 && b[j] == b[j - 1]) {
			cnt[b[j]]++;
			j--;
			continue;
		}
		if (i >= 0 && j >= 0 && a[i] == b[j]) {
			i--; 
			j--;
			continue;
		}
		if (cnt[a[i]] == 0) {
			printf("NO\n");
			return;
		}
		cnt[a[i]]--;
		i--;
	}
	printf("YES\n");
}

int main() 
{
	startTime = clock();

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}