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

/*
	x = p1^a1 * p2^a2 * p3^a3 * ... * pk^ak
	d(x) = (a1 + 1) * (a2 + 1) * (a3 + 1) * ... * (ak + 1) <= 7

	x = 1
	x = p^a (a <= 6)
	x = p * q
	x = p^2 * q

*/

const int C = (int)1e6 + 7;
const int N = 200200;
int d[C];
int pr[N];
int n;
int cntForP[N];
vector<int> g[N];
int ANS = C;
int Q[N];
int topQ;
int dist[N][2];

void BFS(int ban) {
	for (int i = 0; i < topQ; i++) {
		int v = Q[i];
		for (int u : g[v]) {
			if (u == ban) continue;
			if (dist[u][1] == -1) {
				dist[u][0] = dist[v][0] + 1;
				dist[u][1] = dist[v][1];
				Q[topQ++] = u;
			} else if (dist[u][1] != dist[v][1]) {
				ANS = min(ANS, dist[v][0] + dist[u][0] + 3);
			}
		}
	}
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < C; i++)
		d[i] = -1;
	for (int i = 2; i < C; i++) {
		if (d[i] != -1) continue;
		pr[n] = i;
		for (int j = i; j < C; j += i)
			if (d[j] == -1)
				d[j] = n;
		n++;
	}
	
	int m;
	scanf("%d", &m);
	while(m--) {
		int x;
		scanf("%d", &x);
		vector<int> a;
		while(x > 1) {
			int id = d[x];
			int t = 0;
			while(x % pr[id] == 0) {
				t ^= 1;
				x /= pr[id];
			}
			if (t == 1) a.push_back(id);
		}
		if ((int)a.size() == 0) {
			ANS = 1;
		} else if ((int)a.size() == 1) {
			cntForP[a[0]]++;
		} else if ((int)a.size() == 2) {
			g[a[0]].push_back(a[1]);
			g[a[1]].push_back(a[0]);
		} else throw;
	}
	if (ANS == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (cntForP[i] >= 2) {
			printf("2\n");
			return 0;
		}
	}
	
	topQ = 0;
	for (int i = 0; i < n; i++) {
		dist[i][0] = N;
		dist[i][1] = -1;
		if (cntForP[i] > 0) {
			dist[i][0] = 0;
			dist[i][1] = i;
			Q[topQ++] = i;
		}
	}
	BFS(-1);

	for (int id = 0; id < n; id++) {
		if (pr[id] * pr[id] > C) break;
		topQ = 0;
		for (int i = 0; i < n; i++) {
			dist[i][0] = N;
			dist[i][1] = -1;
		}
		for (int v : g[id]) {
			if (dist[v][0] != N) {
				ANS = min(ANS, 2);
				continue;
			}
			dist[v][0] = 0;
			dist[v][1] = v;
			Q[topQ++] = v;
		}
		BFS(id);
	}

	if (ANS == C) ANS = -1;
	printf("%d\n", ANS);

	return 0;
}