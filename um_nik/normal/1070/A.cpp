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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int S = 5002;
const int D = 502;
const int N = S * D;
const int INF = N + 7;
int dist[S][D];
pii q[N];
int topQ;
int s, d;
int p10[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &d, &s);
	p10[0] = 1 % d;
	for (int i = 1; i < N; i++)
		p10[i] = (p10[i - 1] * 10) % d;
	for (int i = 0; i < d; i++)
		for (int j = 0; j <= s; j++)
			dist[j][i] = INF;
	dist[0][0] = 0;
	q[topQ++] = mp(0, 0);
	for (int i = 0; i < topQ; i++) {
		int x = q[i].first, y = q[i].second;
		for (int p = 0; p < 10; p++) {
			int xx = x + p, yy = (y * 10 + p) % d;
			if (xx > s) continue;
			if (dist[xx][yy] <= dist[x][y] + 1) continue;
			dist[xx][yy] = dist[x][y] + 1;
			q[topQ++] = mp(xx, yy);
		}
	}
	int x = s, y = 0;
//	cerr << dist[x][y] << endl;
	if (dist[x][y] == INF) {
		printf("-1\n");
		return 0;
	}
	while(dist[x][y] > 0) {
		for (int p = 1; p < 10; p++) {
			int xx = x - p, yy = (y - p * p10[dist[x][y] - 1]) % d;
			if (yy < 0) yy += d;
			if (xx < 0) continue;
			if (dist[xx][yy] >= dist[x][y]) continue;
			printf("%d", p);
			for (int i = dist[xx][yy] + 1; i < dist[x][y]; i++)
				printf("0");
			x = xx;
			y = yy;
			break;
		}
	}
	printf("\n");

	return 0;
}