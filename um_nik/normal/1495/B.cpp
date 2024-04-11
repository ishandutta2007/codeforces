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
int n;
int a[N];
int mx = 0, mx2 = 0, cnt = 0, cnt2 = 0;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n - 1; i++) {
		if (a[i] < a[i - 1] || a[i] < a[i + 1]) continue;
		int p = i - 1, q = i + 1;
		while(p > 0 && a[p - 1] < a[p]) p--;
		while(q < n - 1 && a[q + 1] < a[q]) q++;
		int cur = max(i - p, q - i);
		if (cur > mx) {
			mx = cur;
			cnt = 0;
		}
		if (cur == mx) {
			cnt++;
			if (i - p != q - i) cnt++;
		}
	}
	int len = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			len++;
			if (len > mx2) {
				mx2 = len;
				cnt2 = 0;
			}
			if (len == mx2) {
				cnt2++;
			}
		} else {
			len = 0;
		}
	}
	len = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > a[i + 1]) {
			len++;
			if (len > mx2) {
				mx2 = len;
				cnt2 = 0;
			}
			if (len == mx2) {
				cnt2++;
			}
		} else {
			len = 0;
		}
	}
	printf("%d\n", (int)(cnt == 1 && mx % 2 == 0 && mx == mx2 && cnt2 == 2));

	return 0;
}