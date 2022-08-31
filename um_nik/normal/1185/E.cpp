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

const int N = 2020;
const int A = 26;
char s[N][N];
int n, m, k;
int pos[A][4];
int ans[A + 2][4];

bool solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < A; i++) {
		pos[i][0] = pos[i][2] = N;
		pos[i][1] = pos[i][3] = -1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') continue;
			int c = (int)(s[i][j] - 'a');
			pos[c][0] = min(pos[c][0], i);
			pos[c][1] = max(pos[c][1], i);
			pos[c][2] = min(pos[c][2], j);
			pos[c][3] = max(pos[c][3], j);
		}
	}
	k = A;
	while(k > 0 && pos[k - 1][1] == -1) k--;
	if (k == 0) {
		printf("YES\n0\n");
		return true;
	}
	for (int c = k - 1; c >= 0; c--) {
//		cerr << c << endl;
		if (pos[c][1] == -1) {
			if (c == k - 1) throw;
			for (int i = 0; i < 4; i++)
				ans[c][i] = ans[k - 1][i];
			continue;
		}
		if (pos[c][0] != pos[c][1] && pos[c][2] != pos[c][3]) return false;
		for (int x = pos[c][0]; x <= pos[c][1]; x++)
			for (int y = pos[c][2]; y <= pos[c][3]; y++) {
				if (s[x][y] != (char)('a' + c) && s[x][y] != '?') return false;
				s[x][y] = '?';
			}
		for (int i = 0; i < 4; i++)
			ans[c][i] = pos[c][i];
	}
	printf("YES\n");
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%d %d %d %d\n", 1 + ans[i][0], 1 + ans[i][2], 1 + ans[i][1], 1 + ans[i][3]);
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (!solve())
			printf("NO\n");
	}

	return 0;
}