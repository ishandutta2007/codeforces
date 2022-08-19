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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 20100;
int a[4][N];
int ans[N][3];
int ansSz;
int n, k;

pii getPos(int id) {
	if (id < n)
		return mp(1, id);
	else
		return mp(2, 2 * n - 1 - id);
}

void addAns(int x, int y, int z) {
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ans[ansSz][2] = z;
	ansSz++;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < 4; i += 3)
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) continue;
			if (a[i][j] == a[i ^ 1][j]) {
				addAns(a[i][j], i, j);
				k--;
				a[i ^ 1][j] = 0;
			}
		}

	if (k == 2 * n) {
		printf("-1\n");
		return 0;
	}

	while(k > 0) {
		for (int i = 0; i < 2 * n; i++) {
			pii s = getPos(i);
			if (a[s.first][s.second] == 0) continue;
			if (a[s.first ^ 1][s.second] == a[s.first][s.second]) {
				addAns(a[s.first][s.second], s.first ^ 1, s.second);
				k--;
				a[s.first][s.second] = 0;
				continue;
			}
			pii t = getPos((i + 2 * n - 1) % (2 * n));
			if (a[t.first][t.second] != 0) continue;
			addAns(a[s.first][s.second], t.first, t.second);
			swap(a[s.first][s.second], a[t.first][t.second]);
		}
	}

	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d %d\n", ans[i][0], ans[i][1] + 1, ans[i][2] + 1);

	return 0;
}