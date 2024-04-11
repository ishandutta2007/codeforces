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

typedef unsigned long long ull;

const int N = 2010;
const int SZ = N / 64 + 2;
int n, m, k;
vector<int> alive;
ull inSet[N][SZ];
ull notInSet[N][SZ];
bool needCheck[N];
int degForSet[N];
char str[N];
bool G[N][N];
int ans[N][2];
int ansSz;

void clear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			inSet[i][j] = notInSet[i][j] = 0;
	for (int i = 0; i < n; i++)
		needCheck[i] = true;
	for (int i = 0; i < m; i++)
		degForSet[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			G[i][j] = 0;
}

void killSet(int id) {
	int x = id >> 6;
	ull z = (ull)1 << (id & 63);
	for (int i = 0; i < n; i++) {
		if (G[i][id]) {
			inSet[i][x] ^= z;
			needCheck[i] = true;
		}
	}
}

bool check(int v, int u) {
	for (int i = 0; i < k; i++)
		if (inSet[v][i] & notInSet[u][i])
			return false;
	return true;
}
int check(int v) {
	for (int u : alive)
		if (u != v && check(v, u))
			return u;
	return -1;
}

void solve() {
	scanf("%d%d", &n, &m);
	k = 0;
	while(k * 64 < m) k++;
	clear();
	for (int j = 0; j < m; j++) {
		scanf("%s", str);
		for (int i = 0; i < n; i++)
			if (str[i] == '1') {
				G[i][j] = 1;
				degForSet[j]++;
			}
		if (degForSet[j] <= 1) continue;
		for (int i = 0; i < n; i++) {
			if (G[i][j])
				inSet[i][j >> 6] |= (ull)1 << (j & 63);
			else
				notInSet[i][j >> 6] |= (ull)1 << (j & 63);
		}
	}
	alive.clear();
	for (int i = 0; i < n; i++)
		alive.push_back(i);
	ansSz = 0;
	while((int)alive.size() > 2) {
		bool fnd = false;
		for (int it = 0; it < (int)alive.size(); it++) {
			int v = alive[it];
			if (!needCheck[v]) continue;
			needCheck[v] = false;
			int p = check(v);
			if (p == -1) continue;
			fnd = true;
			ans[ansSz][0] = v;
			ans[ansSz][1] = p;
			ansSz++;
			for (int i = 0; i < m; i++) {
				if (!G[v][i]) continue;
				degForSet[i]--;
				if (degForSet[i] == 1)
					killSet(i);
			}
			swap(alive[it], alive.back());
			alive.pop_back();
			break;
		}
		if (!fnd) {
			printf("NO\n");
			return;
		}
	}
	if ((int)alive.size() == 2) {
		int v = alive[0], u = alive[1];
		ans[ansSz][0] = v;
		ans[ansSz][1] = u;
		ansSz++;
	}
	printf("YES\n");
	for (int i = 0; i < ansSz; i++)
		printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}