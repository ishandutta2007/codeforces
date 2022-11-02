#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = -1;
const int C = -1;

int n, m;
vector<int> nom;
vector< vector<int> > a;
vector< vector<int> > g, e;

void addEdge(int x0, int y0, int x1, int y1, int cost) {
	int u = x0 * m + y0;
	int v = x1 * m + y1;
	if (cost == 0) {
		e[u].pb(v);
		e[v].pb(u);
	} else {
		g[v].pb(u);
	}
}

	queue<int> q;

void dfs1(int x) {
	if (nom[x] != -1) return;
	q.push(x);
	nom[x] = 0;
	vector<int> v;
	v.pb(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : e[x]) {
			if (nom[y] == -1) {
				nom[y] = 0;
				q.push(y);
				v.pb(y);
			}
		}
	}
	int mx = 0;
	for (auto x : v) {
		for (auto y : g[x]) {
			dfs1(y);
			mx = max(mx, nom[y]);
		}
	}
	++mx;
	for (auto x : v) nom[x] = mx;
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	a.assign(n, vector<int>(m));
	g.resize(n * m);
	e.resize(n * m);
	nom.assign(n * m, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < n; i++) {
		vector< pair<int, int> > b(m);
		for (int j = 0; j < m; j++) b[j] = mp(a[i][j], j);
		sort(b.begin(), b.end());
		for (int j = 0; j + 1 < m; j++) {
			int cost = (b[j + 1].fr != b[j].fr);
			addEdge(i, b[j].sc, i, b[j + 1].sc, cost);
		}
	}	
	for (int j = 0; j < m; j++) {
		vector< pair<int, int> > b(n);
		for (int i = 0; i < n; i++) b[i] = mp(a[i][j], i);
		sort(b.begin(), b.end());
		for (int i = 0; i + 1 < n; i++) {
			int cost = (b[i + 1].fr != b[i].fr);
			addEdge(b[i].sc, j, b[i + 1].sc, j, cost);
		}
	}
	for (int i = 0; i < n * m; i++) dfs1(i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = i * m + j;
			assert(nom[u] != -1);
			printf("%d ", nom[u]);
		}
		puts("");
	}
	return 0;
}