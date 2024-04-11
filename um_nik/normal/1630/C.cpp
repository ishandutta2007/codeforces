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
int a[N];
int b[N][2];
int ans;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		b[i][0] = b[i][1] = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (b[a[i]][0] == -1) b[a[i]][0] = i;
		b[a[i]][1] = i;
	}
	ans = n;
	int l = 0, r = -1;
	while(l < n) {
		eprintf("[%d %d]\n", l, r);
		if (r == -1) {
			int p = b[a[l]][1];
			if (p > l) {
				ans--;
				l++;
				r = p;
			} else {
				l++;
				ans--;
			}
		} else {
			int mx = r;
			while(l < r) {
				mx = max(mx, b[a[l]][1]);
				l++;
			}
			if (mx == r) {
				ans--;
				l = r + 1;
				r = -1;
			} else {
				ans--;
				l = r + 1;
				r = mx;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}