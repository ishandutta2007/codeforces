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
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define mp make_pair

const int BB = 6;
const int B = (1 << BB) - 1;
const int N = 100020;
const int K = 12;
const int LOG = 4;
const int SZ = (int)5e7;
int S;
ull a[SZ];
int st[N];
int n, k, q;
int Q[N][3];
int ID;
int qID;
int query[N][5];
int xs[N][K];
int xsSz[N];
int init[K][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &init[i][j]);
			xs[j][i] = init[i][j];
		}
	for (int i = 0; i < n; i++) {
		sort(xs[i], xs[i] + k);
		xsSz[i] = unique(xs[i], xs[i] + k) - xs[i];
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &Q[i][0], &Q[i][1], &Q[i][2]);
		Q[i][1]--;
		Q[i][2]--;
		if (Q[i][0] == 3) {
			query[qID][0] = Q[i][1];
			query[qID][1] = Q[i][2];
			query[qID][2] = 0;
			query[qID][3] = xsSz[Q[i][2]];
			qID++;
		}
	}
	S = (qID + B) / (B + 1);
	if (S * (k + q - qID) > SZ) throw;
	for (int i = 0; i < k + q - qID; i++)
		st[i] = i * S;

	for (int it = 0; it < LOG; it++) {
		for (int i = 0; i < k * S; i++)
			a[i] = 0;
		for (int i = 0; i < qID; i++) {
			query[i][4] = (query[i][2] + query[i][3]) / 2;
			for (int j = 0; j < k; j++) {
				if (init[j][query[i][1]] >= xs[query[i][1]][query[i][4]])
					a[st[j] + (i >> BB)] ^= (ull)1 << (i & B);
			}
		}
		ID = k;
		for (int i = 0; i < q; i++) {
			if (Q[i][0] == 3) continue;
			int x = st[Q[i][1]], y = st[Q[i][2]];
			if (Q[i][0] == 1) {
				for (int j = 0; j < S; j++)
					a[st[ID] + j] = a[x + j] | a[y + j];
			} else {
				for (int j = 0; j < S; j++)
					a[st[ID] + j] = a[x + j] & a[y + j];
			}
			ID++;
		}
		for (int i = 0; i < qID; i++) {
			if ((a[st[query[i][0]] + (i >> BB)] >> (i & B)) & 1)
				query[i][2] = query[i][4];
			else
				query[i][3] = query[i][4];
		}
	}
	for (int i = 0; i < qID; i++)
		printf("%d\n", xs[query[i][1]][query[i][2]]);

	return 0;
}