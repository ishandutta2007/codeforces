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

const int C = (int)1e6;
const int S = 300;
const int MAX_ANS = 9;

int cnt = 0;
int pr[] = {2, 3, 5, 7, 11, 13, 17};
int a[8];
int ID;
map<ll, int> dist[S];
map<ll, int> dist_small[S];
int ans[S][S];
int count_ans[50];
map<vector<int>, int> toId;
int d[C + 5];

void brute2(int n, int m, int cost, ll prod) {
	if (n == 7) {
		//cnt++;
		if (cost <= MAX_ANS / 2) {
			if (dist_small[ID].count(prod) == 0)
				dist_small[ID][prod] = cost;
			else
				dist_small[ID][prod] = min(dist_small[ID][prod], cost);
		}
		if (dist[ID].count(prod) == 0)
			dist[ID][prod] = cost;
		else
			dist[ID][prod] = min(dist[ID][prod], cost);
		return;
	}
	for (int i = 0; i <= m; i++) {
		int z = abs(i - a[n]);
		if (z > MAX_ANS - cost) continue;
		brute2(n + 1, i, cost + z, prod * (i + 1));
	}
}

void brute(int n, int m, int x) {
	if (n == 7) {
		cnt = 0;
		brute2(0, 50, 0, 1);
		//cerr << cnt << endl;
		vector<int> cur;
		for (int i = 0; i < 7; i++)
			if (a[i] > 0)
				cur.push_back(a[i]);
		toId[cur] = ID;
		ID++;
		return;
	}
	for (int i = 0; x > 0 && i <= m; i++) {
		a[n] = i;
		brute(n + 1, i, x);
		x /= pr[n];
	}
}

int read() {
	int x;
	scanf("%d", &x);
	vector<int> cur;
	while(x > 1) {
		int t = 0;
		int y = d[x];
		while(x % y == 0) {
			x /= y;
			t++;
		}
		cur.push_back(t);
	}
	sort(cur.begin(), cur.end());
	reverse(cur.begin(), cur.end());
	return toId[cur];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int x = 2; x <= C; x++)
		d[x] = -1;
	for (int x = 2; x <= C; x++) {
		if (d[x] != -1) continue;
		for (int y = x; y <= C; y += x)
			if (d[y] == -1)
				d[y] = x;
	}

	brute(0, 20, (int)1e6);
//	cerr << ID << endl;

	for (int v = 0; v < ID; v++) {
		for (int u = 0; u < ID; u++) {
			ans[v][u] = MAX_ANS + 1;
			for (auto t : dist_small[v]) {
				if (dist[u].count(t.first) > 0)
					ans[v][u] = min(ans[v][u], t.second + dist[u][t.first]);
			}
		}
	}
	for (int v = 0; v < ID; v++)
		for (int u = 0; u < ID; u++)
			ans[v][u] = ans[u][v] = min(ans[v][u], ans[u][v]);
/*
	for (int v = 0; v < ID; v++)
		for (int u = 0; u < v; u++)
			count_ans[ans[v][u]]++;
	for (int i = 0; i <= MAX_ANS + 1; i++)
		cerr << count_ans[i] << " ";
	cerr << endl;
*/

	int t;
	scanf("%d", &t);
	while(t--) {
		int v = read();
		int u = read();
		printf("%d\n", ans[v][u]);
	}

	return 0;
}