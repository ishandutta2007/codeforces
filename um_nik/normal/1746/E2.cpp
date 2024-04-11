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

const int M = 100100;
int b[M];
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

const int N = 103;
int dp[N][N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int t = 0; t < N; t++)
		for (int i = 0; i < N; i++)
			dp[t][i] = -1;
	dp[0][0] = 2;
	dp[0][1] = 1;
	dp[0][2] = 0;
	for (int t = 1; t < N; t++) {
		for (int x = 0; x < N; x++) {
			int l = dp[t - 1][x], r = N;
			while(r - l > 1) {
				int y = (l + r) / 2;
				bool ok = false;
				for (int xx = 0; !ok && xx <= x; xx++) {
					for (int yy = 0; !ok && yy <= y; yy++) {
						int p, q;
						p = xx + yy; q = x - xx;
						if (p >= N || q > dp[t - 1][p]) continue;
						p = x - xx + y - yy; q = xx;
						if (p >= N || q > dp[t - 1][p]) continue;
						ok = true;
					}
				}
				if (ok)
					l = y;
				else
					r = y;
			}
			dp[t][x] = l;
		}
	}

	int n, m;
	scanf("%d", &n);
	vector<int> A, B;
	for (int i = 0; i < n; i++)
		A.push_back(i + 1);
	int t = 53;
	while(true) {
		n = (int)A.size();
		m = (int)B.size();
		if (n + m <= 2) {
			for (int x : B) A.push_back(x);
			break;
		}
		int X = -1, Y = -1;
		if (n < N / 2) {
			assert(dp[t][n] >= m);
			//while(t > 0 && dp[t - 1][n] >= m) t--;
			int x = n, y = m;
			for (int xx = 0; X == -1 && xx <= x; xx++) {
				for (int yy = 0; X == -1 && yy <= y; yy++) {
					int p, q;
					p = xx + yy; q = x - xx;
					if (p >= N || q > dp[t - 1][p]) continue;
					p = x - xx + y - yy; q = xx;
					if (p >= N || q > dp[t - 1][p]) continue;
					X = xx; Y = yy;
				}
			}
			assert(X != -1);
		} else {
			X = (int)A.size();
			Y = (int)B.size();
			if (X % 2 == 1 && Y % 2 == 1) {
				X /= 2;
				X++;
			} else {
				X /= 2;
			}
			Y /= 2;
		}
		t--;
		int sz = 0;
		for (int i = 0; i < X; i++)
			b[sz++] = A[i];
		for (int i = 0; i < Y; i++)
			b[sz++] = B[i];
		vector<int> nA, nB;
		if (query(sz) == 1) {
			for (int i = 0; i < X; i++)
				nA.push_back(A[i]);
			for (int i = X; i < n; i++)
				nB.push_back(A[i]);
			for (int i = 0; i < Y; i++)
				nA.push_back(B[i]);
		} else {
			for (int i = 0; i < X; i++)
				nB.push_back(A[i]);
			for (int i = X; i < n; i++)
				nA.push_back(A[i]);
			for (int i = Y; i < m; i++)
				nA.push_back(B[i]);
		}
		A = nA;
		B = nB;
	}
	for (int x : A) {
		printf("! %d\n", x);
		fflush(stdout);
		scanf("%s", s);
		if (s[1] == ')') exit(0);
	}
	assert(false);

	return 0;
}