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

const int N = 1111;
int n;
char s[N];
int query(int l, int r) {
	for (int i = 0; i < n; i++)
		s[i] = '0';
	for (int i = l; i < r; i++)
		s[i] = '1';
	s[n] = '\0';
	printf("? %s\n", s);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int ans0 = -1, ans1 = -1;
int Z;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	Z = query(0, 0);
	int l = 0, r = n;
	while(ans0 == -1 && ans1 == -1) {
		assert(l + 1 < r);
		int mid = (l + r) / 2;
		int X = query(l, mid);
		X = X - Z;
		if (abs(X) == mid - l) {
			if (X < 0) {
				ans1 = l;
				l = mid;
			} else {
				ans0 = l;
				l = mid;
			}
		} else {
			r = mid;
		}
	}
	while(r - l > 1) {
		int mid = (l + r) / 2;
		int X = query(l, mid);
		X = X - Z;
		if (ans0 == -1) {
			if (X == -(mid - l))
				l = mid;
			else
				r = mid;
		} else {
			if (X == (mid - l))
				l = mid;
			else
				r = mid;
		}
	}
	if (ans0 == -1)
		ans0 = l;
	else
		ans1 = l;
	printf("! %d %d\n", ans0 + 1, ans1 + 1);

	return 0;
}