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

const int A = 26;
const int N = 100100;
const int M = 255;
char s[N];
int n, q;
int nxt[N][A];
int dp[M][M][M];
int p[3][M];
int sz[3];

int getPos(int pos, int c) {
	if (pos >= n || nxt[pos][c] == n) return N;
	return nxt[pos][c] + 1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	scanf("%s", s);
	for (int c = 0; c < A; c++)
		nxt[n][c] = N;
	for (int i = n - 1; i >= 0; i--) {
		for (int c = 0; c < A; c++)
			nxt[i][c] = nxt[i + 1][c];
		nxt[i][(int)(s[i] - 'a')] = i;
	}
	for (int x = 0; x < M; x++)
		for (int y = 0; y < M; y++)
			for (int z = 0; z < M; z++)
				dp[x][y][z] = N;
	dp[0][0][0] = 0;
	while(q--) {
		char t;
		int w;
		scanf(" %c %d", &t, &w);
		w--;
		if (t == '+') {
			int c;
			scanf(" %c", &t);
			c = (int)(t - 'a');
			p[w][sz[w]++] = c;
			if (w == 0) {
				for (int y = 0; y <= sz[1]; y++)
					for (int z = 0; z <= sz[2]; z++) {
						dp[sz[0]][y][z] = N;
					}
				for (int y = 0; y <= sz[1]; y++)
					for (int z = 0; z <= sz[2]; z++) {
						dp[sz[0]][y][z] = min(dp[sz[0]][y][z], getPos(dp[sz[0] - 1][y][z], c));
						if (y < sz[1])
							dp[sz[0]][y + 1][z] = min(dp[sz[0]][y + 1][z], getPos(dp[sz[0]][y][z], p[1][y]));
						if (z < sz[2])
							dp[sz[0]][y][z + 1] = min(dp[sz[0]][y][z + 1], getPos(dp[sz[0]][y][z], p[2][z]));
					}
			} else if (w == 1) {
				for (int x = 0; x <= sz[0]; x++)
					for (int z = 0; z <= sz[2]; z++) {
						dp[x][sz[1]][z] = N;
					}
				for (int x = 0; x <= sz[0]; x++)
					for (int z = 0; z <= sz[2]; z++) {
						dp[x][sz[1]][z] = min(dp[x][sz[1]][z], getPos(dp[x][sz[1] - 1][z], c));
						if (x < sz[0])
							dp[x + 1][sz[1]][z] = min(dp[x + 1][sz[1]][z], getPos(dp[x][sz[1]][z], p[0][x]));
						if (z < sz[2])
							dp[x][sz[1]][z + 1] = min(dp[x][sz[1]][z + 1], getPos(dp[x][sz[1]][z], p[2][z]));
					}

			} else {
				for (int y = 0; y <= sz[1]; y++)
					for (int x = 0; x <= sz[0]; x++) {
						dp[x][y][sz[2]] = N;
					}
				for (int y = 0; y <= sz[1]; y++)
					for (int x = 0; x <= sz[0]; x++) {
						dp[x][y][sz[2]] = min(dp[x][y][sz[2]], getPos(dp[x][y][sz[2] - 1], c));
						if (y < sz[1])
							dp[x][y + 1][sz[2]] = min(dp[x][y + 1][sz[2]], getPos(dp[x][y][sz[2]], p[1][y]));
						if (x < sz[0])
							dp[x + 1][y][sz[2]] = min(dp[x + 1][y][sz[2]], getPos(dp[x][y][sz[2]], p[0][x]));
					}

			}
		} else {
			sz[w]--;
		}
		if (dp[sz[0]][sz[1]][sz[2]] <= n)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}