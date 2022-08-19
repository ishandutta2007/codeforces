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

using ull = unsigned long long;

const int K = 2020;
const int N = 3030;
const int B = 64;
const int S = N / B + 1;
ull g[K][S];
int n, m, q;
int a[N][4];
int b[N];
char s[10];
int myVar[K];
int ans[N];

void setBit(int p, int x) {
	int y = x % B;
	x /= B;
	g[p][x] ^= ((ull)1) << y;
}
int getBit(int p, int x) {
	int y = x % B;
	x /= B;
	return (g[p][x] >> y) & 1;
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			a[i][j + 1] = 3 * i + j;
	while(q--) {
		scanf("%s", s);
		int sz;
		scanf("%d", &sz);
		for (int i = 0; i < sz; i++) {
			scanf("%d", &b[i]);
			b[i]--;
		}
		if (strcmp(s, "mix") == 0) {
			for (int i = 0; i < sz; i++) {
				int v = b[i];
				for (int x = 1; x <= 3; x++){
					for (int j = 0; j < 2; j++)
						if ((x >> j) & 1)
							setBit(m + j, a[v][x]);
				}
			}
			scanf("%s", s);
			int x = 0;
			if (s[0] == 'W') {
				x = 0;
			} else if (s[0] == 'R') {
				x = 1;
			} else if (s[0] == 'Y') {
				x = 2;
			} else if (s[0] == 'B') {
				x = 3;
			} else throw;
			for (int j = 0; j < 2; j++)
				if ((x >> j) & 1)
					setBit(m + j, 3 * n);
			m += 2;
		} else if (strcmp(s, "RY") == 0) {
			for (int i = 0; i < sz; i++) {
				int v = b[i];
				swap(a[v][1], a[v][2]);
			}
		} else if (strcmp(s, "RB") == 0) {
			for (int i = 0; i < sz; i++) {
				int v = b[i];
				swap(a[v][1], a[v][3]);
			}
		} else if (strcmp(s, "YB") == 0) {
			for (int i = 0; i < sz; i++) {
				int v = b[i];
				swap(a[v][2], a[v][3]);
			}
		} else throw;
	}
/*
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= 3 * n; j++)
			printf("%d ", getBit(i, j));
		printf("\n");
	}
*/
	int L = (3 * n) / B + 1;
	int k = 0;
	for (int i = 0; i < 3 * n; i++) {
		int v = -1;
		for (int j = k; v == -1 && j < m; j++) {
			if (getBit(j, i))
				v = j;
		}
		if (v == -1) continue;
		if (v != k) {
			for (int j = 0; j < L; j++)
				swap(g[v][j], g[k][j]);
		}
		myVar[k] = i;
		for (int j = k + 1; j < m; j++) {
			if (!getBit(j, i)) continue;
			for (int p = i / B; p < L; p++)
				g[j][p] ^= g[k][p];
		}
		k++;
	}
/*
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= 3 * n; j++)
			printf("%d ", getBit(i, j));
		printf("\n");
	}
*/
	for (int i = k; i < m; i++)
		if (getBit(i, 3 * n)) {
			printf("NO\n");
			return 0;
		}
	for (int i = k - 1; i >= 0; i--) {
		ans[myVar[i]] = getBit(i, 3 * n);
		if (ans[myVar[i]] == 0) continue;
		for (int j = i - 1; j >= 0; j--)
			if (getBit(j, myVar[i]))
				g[j][L - 1] ^= g[i][L - 1];
	}

	printf("YES\n");
	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = 0; j < 3; j++)
			res ^= (ans[3 * i + j] << j);
		if (res != 0 && res != 1 && res != 2 && res != 4) res ^= 7;
		if (res == 0)
			printf(".");
		else if (res == 1)
			printf("R");
		else if (res == 2)
			printf("Y");
		else if (res == 4)
			printf("B");
		else throw;
	}
	printf("\n");

	return 0;
}