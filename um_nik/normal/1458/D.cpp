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


struct Fenwick {
	vector<int> fenv;

	Fenwick() : fenv() {}
	Fenwick(int n) : fenv(vector<int>(n, 0)) {}

	void add(int p, int x) {
		for(; p < (int)fenv.size(); p |= p + 1)
			fenv[p] += x;
	}
	int get(int r) {
		int res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			res += fenv[r];
		return res;
	}
	int getSum(int l, int r) {
		if (l >= r) return 0;
		return get(r - 1) - get(l - 1);
	}
} fenv;


const int N = (int)1e6 + 7;
char s[N];
int a[N];
int n;

void solve() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i <= 2 * n; i++)
		a[i] = 0;
	fenv = Fenwick(2 * n + 1);
	int bal = n;
	fenv.add(bal, 1);
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			bal--;
			a[bal]++;
			fenv.add(bal, 1);
		} else {
			a[bal]++;
			bal++;
			fenv.add(bal, 1);
		}
	}
	bal = n;
	for (int i = 0; i < n; i++) {
		fenv.add(bal, -1);
		int d = -1;
		if (bal > 0 && a[bal - 1] > 0) {
			if (a[bal - 1] == 1 && fenv.getSum(bal, 2 * n + 1) > 0)
				d = 1;
		} else d = 1;
		if (d == -1) {
			bal--;
			assert(a[bal] > 0);
			a[bal]--;
			printf("0");
		} else {
			assert(a[bal] > 0);
			a[bal]--;
			bal++;
			printf("1");
		}
	}
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