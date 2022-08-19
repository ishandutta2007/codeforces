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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 100100;
int n;
int a[N];

bool solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x - 1] = i;
	}
	int m = n - 1;
	int l = 0;
	while(l < n) {
		int r = l + 1;
		while(r < n && a[r] == a[r - 1] + 1) r++;
		if (a[r - 1] != m) return false;
		m = a[l] - 1;
		l = r;
	}
	return true;
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("Yes\n");
		else
			printf("No\n");
	}


	return 0;
}