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
int n, k;
int a[N];
bool isMax[N];

bool solve(int l, int r) {
	//eprintf("solve %d %d\n", l, r);
	int x = a[l], y = a[r];
	while(l + 1 < r) {
		if (x >= y) {
			int xx = max(a[l + 1], x - k + 1);
			if (xx >= a[l + 1] + k) return false;
			x = xx;
			l++;
		} else {
			int yy = max(a[r - 1], y - k + 1);
			if (yy >= a[r - 1] + k) return false;
			y = yy;
			r--;
		}
		//eprintf("l = %d, x = %d, r = %d, y = %d\n", l, x, r, y);
	}
	return abs(x - y) < k;
}

bool solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		isMax[i] = 0;
	}
	isMax[0] = isMax[n - 1] = 1;
	for (int i = 1; i < n - 1; i++) {
		isMax[i] = (a[i] >= a[i - 1] && a[i] >= a[i + 1]);
	}
	int l = 0;
	while(l < n - 1) {
		for (int i = l + 1; i < n; i++) {
			if (isMax[i]) {
				if (!solve(l, i)) return false;
				l = i;
				break;
			}
		}
	}
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