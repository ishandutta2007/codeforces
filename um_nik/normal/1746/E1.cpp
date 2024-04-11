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

const int N = 100100;
int b[N];
char s[10];

int query(int sz) {
	printf("? %d ", sz);
	for (int i = 0; i < sz; i++)
		printf("%d ", b[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s", s);
	if (s[0] == 'Y')
		return 1;
	else
		return 0;
}

void solve(vector<int> a) {
	int n = (int)a.size();
	if (n <= 2) {
		for (int x : a) {
			printf("! %d\n", x);
			fflush(stdout);
			scanf("%s", s);
			if (s[1] == ')') exit(0);
		}
		assert(false);
	}
	vector<int> res;
	for (int k = 0;; k++) {
		if ((1 << k) >= n) {
			res.push_back(false);
			break;
		}
		int sz = 0;
		for (int i = 0; i < n; i++)
			if ((i >> k) & 1)
				b[sz++] = a[i];
		int x = query(sz);
		int y = query(sz);
		res.push_back(x);
		if (x == y) {
			break;
		}
	}
	vector<int> na;
	int m = (int)res.size();
	int U = (1 << m) - 1;
	for (int k = 0; k < m; k++) {
		int mask = 0;
		for (int i = 0; i < m; i++) {
			int z = res[i];
			if (i < k) z ^= 1;
			mask ^= z << i;
		}
		for (int i = 0; i < n; i++) if ((i & U) == mask)
			na.push_back(a[i]);
	}
	solve(na);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	solve(a);

	return 0;
}