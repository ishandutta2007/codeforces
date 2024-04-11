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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 400400;
int n, m;
vector<int> T[N];
vector<pii> g[N];
int h[N], par[N];
vector<int> path[N];
string str[N];
int sz[N];
char cc[N][2];
vector<int> a[N][2];
int col[N];
string ans;

void Fail() {
	cout << "NO\n";
	exit(0);
}

void dfsTree(int v, int p) {
	par[v] = p;
	for (int u : T[v]) if (u != p) {
		h[u] = h[v] + 1;
		dfsTree(u, v);
	}
}
vector<int> getPath(int v, int u) {
	vector<int> p1, p2;
	while(v != u) {
		if (h[v] > h[u]) {
			p1.push_back(v);
			v = par[v];
		} else {
			p2.push_back(u);
			u = par[u];
		}
	}
	p1.push_back(v);
	reverse(all(p2));
	for (int x : p2) p1.push_back(x);
	return p1;
}

void myBan(int v) {
	int c = 0;
	if (v < 0) {
		c = 1;
		v = -v;
	}
	if (col[v] == -1) col[v] = c ^ 1;
	if (col[v] == c) Fail();
}
void addEdge(int v, int u) {
	int c = 0;
	if (v < 0) {
		v = -v;
		c ^= 1;
	}
	if (u < 0) {
		u = -u;
		c ^= 1;
	}
	g[v].push_back(mp(u, c));
	g[u].push_back(mp(v, c));
}
void dfsCol(int v) {
	for (pii e : g[v]) {
		int u = e.first;
		int c = col[v] ^ e.second;
		if (col[u] == -1) {
			col[u] = c;
			dfsCol(u);
		} else {
			if (col[u] != c) Fail();
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		T[v].push_back(u);
		T[u].push_back(v);
	}
	dfsTree(1, 0);
	for (int i = 1; i <= m; i++)
		col[i] = -1;
	for (int i = 1; i <= m; i++) {
		int v, u;
		cin >> v >> u;
		path[i] = getPath(v, u);
		cin >> str[i];
		assert((int)path[i].size() == (int)str[i].size());
		for (int j = 0; j < (int)path[i].size(); j++) {
			v = path[i][j];
			char c1 = str[i][j], c2 = str[i][(int)path[i].size() - 1 - j];
			if (c1 == c2) {
				if (sz[v] == 0) {
					sz[v] = 1;
					cc[v][0] = c1;
				} else {
					int pos = 0;
					while(cc[v][pos] != c1 && pos < sz[v]) pos++;
					if (pos == sz[v]) Fail();
					for (int p = 0; p < sz[v]; p++) if (p != pos)
						for (int x : a[v][p])
							myBan(x);
					cc[v][0] = cc[v][pos];
					a[v][0] = a[v][pos];
					sz[v] = 1;
				}
			} else {
				if (sz[v] == 0) {
					sz[v] = 2;
					cc[v][0] = c1;
					a[v][0].push_back(i);
					cc[v][1] = c2;
					a[v][1].push_back(-i);
				} else {
					bool ok1 = false;
					bool ok2 = false;
					int pos = 0;
					while(pos < sz[v]) {
						if (cc[v][pos] == c1) {
							a[v][pos].push_back(i);
							ok1 = true;
							pos++;
						} else if (cc[v][pos] == c2) {
							a[v][pos].push_back(-i);
							ok2 = true;
							pos++;
						} else {
							for (int x : a[v][pos])
								myBan(x);
							for (int p = pos + 1; p < sz[v]; p++) {
								cc[v][p - 1] = cc[v][p];
								a[v][p - 1] = a[v][p];
							}
							sz[v]--;
						}
					}
					if (!ok1) myBan(i);
					if (!ok2) myBan(-i);
					assert(sz[v] > 0);
				}
			}
		}
	}
	for (int v = 1; v <= n; v++)
		for (int p = 0; p < sz[v]; p++) if (!a[v][p].empty()) {
			int x = a[v][p][0];
			for (int y : a[v][p])
				addEdge(x, y);
		}
	for (int v = 1; v <= m; v++) if (col[v] != -1)
		dfsCol(v);
	for (int v = 1; v <= m; v++) if (col[v] == -1) {
		col[v] = 0;
		dfsCol(v);
	}
	ans.resize(n);
	for (int i = 0; i < n; i++)
		ans[i] = 'a';
	for (int v = 1; v <= m; v++) {
		if (col[v] == 1) {
			reverse(all(path[v]));
		}
		for (int i = 0; i < (int)path[v].size(); i++)
			ans[path[v][i] - 1] = str[v][i];
	}
	cout << "YES\n" << ans << "\n";

	return 0;
}