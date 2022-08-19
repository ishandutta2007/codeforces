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

struct Item {
	int L, floor, mask;

	Item() : L(), floor(), mask() {}
	Item(int _L, int _floor, int _mask) : L(_L), floor(_floor), mask(_mask) {}
};

const int INF = (int)4e8;
const int N = 2010;
const int S = (int)2e6;
const int T = 750;
const int K = 9;
const int MD = N * K * 3;
int pw[K + 1];
int maskToId[S];
int maskSz[S];
int idToMask[T];
int addOne[T][K];
int subOne[T][K];
int ID;
int dist[N][K][T];
vector<Item> q[MD];
int n;
int a[N][2];

void brute(int pos, int mask, int sz) {
	if (pos == K) {
		maskToId[mask] = ID;
		idToMask[ID] = mask;
		maskSz[mask] = sz;
		ID++;
		return;
	}
	if (sz < 4) brute(pos, mask + pw[pos], sz + 1);
	brute(pos + 1, mask, sz);
}

void genMasks() {
	pw[0] = 1;
	for (int i = 1; i <= K; i++)
		pw[i] = pw[i - 1] * 5;
	for (int i = 0; i < S; i++)
		maskToId[i] = -1;
	brute(0, 0, 0);
	for (int id = 0; id < ID; id++) {
		int mask = idToMask[id];
		for (int k = 0; k < K; k++) {
			addOne[id][k] = -1;
			if (maskSz[mask] == 4) continue;
			addOne[id][k] = maskToId[mask + pw[k]];
		}
		for (int k = 0; k < K; k++) {
			int x = mask / pw[k];
			x %= 5;
			if (x == 0)
				subOne[id][k] = -1;
			else
				subOne[id][k] = maskToId[mask - pw[k]];
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	genMasks();

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
		a[i][0]--;
		a[i][1]--;
	}
	
	for (int i = 0; i <= n; i++)
		for (int k = 0; k < K; k++)
			for (int mask = 0; mask < ID; mask++)
				dist[i][k][mask] = INF;
	dist[0][0][maskToId[0]] = 0;
	q[0].push_back(Item(0, 0, maskToId[0]));

	for (int d = 0; d < MD; d++) {
		while(!q[d].empty()) {
			Item I = q[d].back();
			q[d].pop_back();
			int p = I.L, floor = I.floor, mask = I.mask;
			if (dist[p][floor][mask] != d) continue;

			for (int df = -1; df <= 1; df++) {
				int w = dist[p][floor][mask] + abs(df);
				int np = p, nf = floor + df, nmask = mask;
				if (nf < 0 || nf >= K) continue;
				if (df == 0) {
					while(subOne[nmask][nf] != -1) nmask = subOne[nmask][nf];
					while(np < n && a[np][0] == nf && maskSz[idToMask[nmask]] < 4) {
						nmask = addOne[nmask][a[np][1]];
						np++;
					}
				}
				if (dist[np][nf][nmask] <= w) continue;
				dist[np][nf][nmask] = w;
				q[w].push_back(Item(np, nf, nmask));
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < K; i++)
		ans = min(ans, dist[n][i][maskToId[0]]);
	printf("%d\n", ans + 2 * n);

	return 0;
}