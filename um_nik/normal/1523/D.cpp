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
const int K = 15;
const int M = (1 << K) + 3;
int n, m, k;
ll ANS;
int CNT_ANS;
ll a[N];
int b[M];
char s[77];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		a[i] = 0;
		for (int j = 0; j < m; j++)
			if (s[j] == '1')
				a[i] ^= 1LL << j;
	}
	shuffle(a, a + n, rng);
	for (int it = 0; it < n && it < 150; it++) {
		vector<int> pos;
		for (int i = 0; i < m; i++)
			if ((a[it] >> i) & 1)
				pos.push_back(i);
		k = (int)pos.size();
		assert(k <= K);
		for (int i = 0; i < (1 << k); i++)
			b[i] = 0;
		for (int i = 0; i < n; i++) {
			int mask = 0;
			for (int j = 0; j < k; j++)
				if ((a[i] >> pos[j]) & 1)
					mask ^= 1 << j;
			b[mask]++;
		}
		for (int i = 0; i < k; i++)
			for (int mask = 0; mask < (1 << k); mask++) {
				if ((mask >> i) & 1) continue;
				b[mask] += b[mask ^ (1 << i)];
			}
		for (int mask = 0; mask < (1 << k); mask++) {
			if (2 * b[mask] < n) continue;
			int ppc = 0;
			for (int i = 0; i < k; i++)
				ppc += (mask >> i) & 1;
			if (ppc > CNT_ANS) {
				CNT_ANS = ppc;
				ANS = 0;
				for (int i = 0; i < k; i++)
					if ((mask >> i) & 1)
						ANS ^= 1LL << pos[i];
			}
		}
	}
	for (int i = 0; i < m; i++)
		printf("%lld", (ANS >> i) & 1);
	printf("\n");

	return 0;
}