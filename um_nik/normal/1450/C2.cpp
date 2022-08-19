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

const int N = 333;
int n;
char s[N][N];
int a[3][2];

void solve() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'X')
				a[(i + j) % 3][0]++;
			if (s[i][j] == 'O')
				a[(i + j) % 3][1]++;
		}
	}
	int bst = -1;
	int val = N * N;
	for (int t = 0; t < 3; t++) {
		int cur = a[t][0] + a[(t + 1) % 3][1];
		if (cur < val) {
			val = cur;
			bst = t;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int t = (i + j) % 3;
			if (s[i][j] == '.') continue;
			if (s[i][j] == 'O') t = (t + 2) % 3;
			if (t == bst) {
				s[i][j] ^= 'X' ^ 'O';
			}
		}
	for (int i = 0; i < n; i++)
		printf("%s\n", s[i]);
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