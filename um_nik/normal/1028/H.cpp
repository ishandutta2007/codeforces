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

const int C = (int)6e6;
//const int C = 1000;
const int N = 200200;
//const int N = 300;
const int K = 17;
const int LOG = 18;
int p[C];
int d[C];
vector<int> a[C];
int b[N];
int cur[K];
int st[K];
int stSz;
int sparse[K][LOG][N];
int p2[N];

void relax(int l, int r, int x) {
	int val = d[b[l]] + d[b[r]] - 2 * d[x];
	sparse[val][0][r] = max(sparse[val][0][r], l);
}

int getMax(int id, int l, int r) {
	int k = p2[r - l];
	return max(sparse[id][k][l], sparse[id][k][r - (1 << k)]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	for (int x = 2; x < C; x++) {
		if (p[x] != 0) continue;
		for (int y = x; y < C; y += x)
			if (p[y] == 0)
				p[y] = x;
	}
	for (int x = 2; x < C; x++) {
		int y = x;
		int sz = 0;
		while(y > 1) {
			int qq = p[y];
			int z = 0;
			while(y % qq == 0) {
				y /= qq;
				z ^= 1;
			}
			if (z)
				sz++;
		}
		d[x] = sz;
	}

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int y = x;
		int sz = 0;
		while(y > 1) {
			int qq = p[y];
			int z = 0;
			while(y % qq == 0) {
				y /= qq;
				z ^= 1;
			}
			if (z)
				cur[sz++] = qq;
		}
		for (int mask = 0; mask < (1 << sz); mask++) {
			y = 1;
			for (int j = 0; j < sz; j++)
				if ((mask >> j) & 1)
					y *= cur[j];
			a[y].push_back(i);
		}
		b[i] = y;
	}
	for (int i = 0; i < K; i++)
		for (int j = 0; j < n; j++)
			sparse[i][0][j] = -1;
	for (int x = 1; x < C; x++) {
		if (a[x].empty()) continue;
		stSz = 0;
		for (int w : a[x]) {
			for (int i = 0; i < stSz; i++)
				relax(st[i], w, x);
			while(stSz > 0 && d[b[w]] <= d[b[st[stSz - 1]]]) stSz--;
			st[stSz++] = w;
		}
	}

	for (int id = 0; id < K; id++)
		for (int k = 0; k < LOG - 1; k++)
			for (int i = 0; i + (1 << (k + 1)) <= n; i++)
				sparse[id][k + 1][i] = max(sparse[id][k][i], sparse[id][k][i + (1 << k)]);

	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		for (int id = 0; id < K; id++)
			if (getMax(id, l, r) >= l) {
				printf("%d\n", id);
				break;
			}
	}

	return 0;
}