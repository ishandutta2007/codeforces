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

const int A = 10;
char dig[A][10] = {
	"1110111",
	"0010010",
	"1011101",
	"1011011",
	"0111010",
	"1101011",
	"1101111",
	"1010010",
	"1111111",
	"1111011"
};

const int N = 2020;
char s[10];
int a[N][A];
int n, k;
bool dp[N][N];


int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int c = 0; c < A; c++) {
			a[i][c] = 0;
			bool ok = true;
			for (int j = 0; j < 7; j++) {
				if (dig[c][j] == '0' && s[j] == '1') {
					ok = false;
					break;
				}
				if (dig[c][j] == '1' && s[j] == '0')
					a[i][c]++;
			}
			if (!ok) a[i][c] = -1;
		}
	}
	dp[n][0] = 1;
	for (int i = n - 1; i >= 0; i--)
		for (int x = 0; x <= k; x++) {
			if (!dp[i + 1][x]) continue;
			for (int c = 0; c < A; c++) {
				if (a[i][c] == -1) continue;
				dp[i][x + a[i][c]] = 1;
			}
		}
	if (!dp[0][k]) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		bool fnd = false;
		for (int c = A - 1; !fnd && c >= 0; c--) {
			if (a[i][c] == -1) continue;
			if (a[i][c] > k) continue;
			if (!dp[i + 1][k - a[i][c]]) continue;
			fnd = true;
			printf("%d", c);
			k -= a[i][c];
		}
		assert(fnd);
	}
	printf("\n");

	return 0;
}