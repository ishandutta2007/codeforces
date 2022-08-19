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

const int N = 1010;
int n, m;
char a[N];
char b[N];

void solve() {
	scanf("%d%d", &n, &m);
	scanf("%s", a);
	b[n] = '\0';
	m = min(n, m);
	while(m--) {
		for (int i = 0; i < n; i++) {
			if (a[i] == '1') {
				b[i] = '1';
			} else {
				int cnt = 0;
				if (i > 0 && a[i - 1] == '1') cnt++;
				if (i + 1 < n && a[i + 1] == '1') cnt++;
				if (cnt == 1)
					b[i] = '1';
				else
					b[i] = '0';
			}
		}
		for (int i = 0; i < n; i++)
			a[i] = b[i];
	}
	printf("%s\n", a);
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