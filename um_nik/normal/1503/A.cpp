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

const int N = 400400;
int n;
char a[N], b[N], c[N];

void solve() {
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < n; i++)
		b[i] = c[i] = '(';
	b[n] = c[n] = '\0';
	if (a[0] == '0' || a[n - 1] == '0') {
		printf("NO\n");
		return;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == '1')
			cnt++;
	if (cnt & 1) {
		printf("NO\n");
		return;
	}
	cnt /= 2;
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') {
			if (cnt > 0) {
				b[i] = c[i] = '(';
			} else {
				b[i] = c[i] = ')';
			}
			cnt--;
		} else {
			if (t == 0) {
				b[i] = '(';
				c[i] = ')';
			} else {
				b[i] = ')';
				c[i] = '(';
			}
			t ^= 1;
		}
	}
	printf("YES\n%s\n%s\n", b, c);
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