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
int a[N];
int cnt[N];
bool used[N];
int n;
int b[N];
int m;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	m = 0;
	int pos = 0;
	for (int i = 0; i < n; i++)
		cnt[a[i]]++;
	while(pos < n) {
		int x = 0;
		while(cnt[x] > 0) x++;
		for (int i = 0; i < x; i++)
			used[i] = 0;
		b[m++] = x;
		if (x == 0) {
			pos++;
			continue;
		}
		//eprintf("x = %d\n", x);
		int w = x;
		while(w > 0) {
			cnt[a[pos]]--;
			if (a[pos] < x && !used[a[pos]]) {
				used[a[pos]] = 1;
				w--;
			}
			pos++;
		}
		//eprintf("pos = %d\n", pos);
	}
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d ", b[i]);
	printf("\n");
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