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
char s[3][N];
char ans[N];
int m;

void solve() {
	scanf("%d", &n);
	int cntZ = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%s", s[i]);
		int z = 0;
		for (int j = 0; j < 2 * n; j++)
			z += (int)(s[i][j] == '0');
		if (z >= n) cntZ++;
	}
	bool REV = false;
	if (cntZ <= 1) {
		REV = true;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 2 * n; j++)
				s[i][j] ^= '0' ^ '1';
	}
	m = 0;
	int p = -1, q = -1, pp = -1, qq = -1;
	for (int i = 0; i < 3; i++) {
		int z = 0;
		for (int j = 0; j < 2 * n; j++)
			z += (int)(s[i][j] == '0');
		if (z > pp) {
			q = p;
			qq = pp;
			p = i;
			pp = z;
		} else if (z > qq) {
			q = i;
			qq = z;
		}
	}
	int ptr = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (s[p][i] == '0') {
			while(ptr < 2 * n && s[q][ptr] == '1') {
				ans[m++] = '1';
				ptr++;
			}
			if (ptr < 2 * n) ptr++;
			ans[m++] = '0';
		} else {
			ans[m++] = '1';
		}
	}
	while(ptr < 2 * n) {
		ans[m++] = s[q][ptr++];
	}
	assert(m <= 3 * n);
	ans[m] = '\0';
	if (REV) {
		for (int i = 0; i < m; i++)
			ans[i] ^= '0' ^ '1';
	}
	printf("%s\n", ans);
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