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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 11;
const int N = 100100;
ll ans;
int cntForLen[N];
char s[N];
int a[N];
int L;
int dp[2][M][M][M];

int getSum(int st, int len) {
	len %= M;
	return (st * len + len * (len - 1) / 2) % M;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cntForLen[1] = 9;
	int cur = 1;
	for (int i = 1; i < N - 1; i++) {
		cntForLen[i + 1] = getSum(cur, cntForLen[i]);
		cur = (cur + cntForLen[i]) % M;
	}

	scanf("%s", s);
	L = strlen(s);
	for (int i = 0; i < L; i++)
		a[i] = (int)(s[i] - '0');

	for (int x = 0; x < M; x++)
		for (int y = 0; y < M; y++)
			for (int z = 0; z < M; z++)
				dp[0][x][y][z] = L;

	int xx, yy, zz;
	for (int pos = L - 1; pos >= 0; pos--) {
		if (a[pos] > 0) {
			xx = a[pos] - 1, yy = 1, zz = 9;
			ans += dp[0][xx][yy][zz] - pos;
		}
		for (int x = 0; x < M; x++)
			for (int y = 0; y < M; y++) {
				int m = (x + y) % M;
				if (a[pos] >= m) {
					for (int z = 0; z < M; z++) {
						dp[1][x][y][z] = pos;
					}
					continue;
				}
				for (int z = 0; z < M; z++) {
					xx = (getSum(y, x) + a[pos]) % M;
					yy = (y + z) % M;
					zz = getSum(y, z);
					dp[1][x][y][z] = dp[0][xx][yy][zz];
				}
			}
		for (int x = 0; x < M; x++)
			for (int y = 0; y < M; y++)
				for (int z = 0; z < M; z++)
					dp[0][x][y][z] = dp[1][x][y][z];
	}
/*
	for (int l = 0; l < L; l++) {
		if (s[l] == '0') continue;
		ans++;
		int startForLen = 1, cntLower = a[l] - 1;
		for (int i = l + 1; i < L; i++) {
			int m = (startForLen + cntLower) % M;
			if (a[i] >= m) break;
			cntLower = (getSum(startForLen, cntLower) + a[i]) % M;
			startForLen = (startForLen + cntForLen[i - l]) % M;
			ans++;
		}
	}
*/
	printf("%lld\n", ans);

	return 0;
}