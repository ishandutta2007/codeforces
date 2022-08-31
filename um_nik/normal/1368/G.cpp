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

const int L = (1 << 17);
struct Node {
	int l, r;
	pii val;
	int addAll;

	Node() : l(-1), r(-1), val(mp(0, 0)), addAll(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val(mp(0, _r - _l)), addAll(0) {}

	void add(int x) {
		val.first += x;
		addAll += x;
	}
};
Node tree[2 * L + 5];

void build() {
	for (int i = 0; i < L; i++)
		tree[L + i] = Node(i, i + 1);
	for (int i = L - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void push(int v) {
	assert(v < L);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		tree[u].add(tree[v].addAll);
	tree[v].addAll = 0;
}
pii merge(pii v, pii u) {
	if (v.first != u.first) return min(v, u);
	return mp(v.first, v.second + u.second);
}
void update(int v) {
	assert(v < L);
	tree[v].val = merge(tree[2 * v].val, tree[2 * v + 1].val);
}
void addOnSegm(int v, int l, int r, int x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].add(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		addOnSegm(u, l, r, x);
	update(v);
}

const int N = 100200;
vector<string> s;
vector<vector<int>> id;
int n, m;
vector<int> g[2][N];
int t[2][N][2];
int T[2];

struct Event {
	int x, y1, y2, add;

	Event() : x(), y1(), y2(), add() {}
	Event(int _x, int _y1, int _y2, int _add) : x(_x), y1(_y1), y2(_y2), add(_add) {}

	bool operator < (const Event &e) const {
		return x < e.x;
	}
};
Event ev[2 * N];
int evSz;

bool checkCell(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int k, int v) {
	t[k][v][0] = T[k]++;
	for (int u : g[k][v])
		dfs(k, u);
	t[k][v][1] = T[k];
}

void read() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	id = vector<vector<int>>(n, vector<int>(m, 0));
	int k = 1;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			if (id[x][y] != 0) continue;
			if (s[x][y] == 'U') {
				id[x][y] = id[x + 1][y] = k++;
			} else if (s[x][y] == 'D') {
				id[x][y] = id[x - 1][y] = k++;
			} else if (s[x][y] == 'L') {
				id[x][y] = id[x][y + 1] = k++;
			} else if (s[x][y] == 'R') {
				id[x][y] = id[x][y - 1] = k++;
			} else throw;
		}
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			int xx = x, yy = y;
			if (s[x][y] == 'U') {
				xx += 2;
			} else if (s[x][y] == 'D') {
				xx -= 2;
			} else if (s[x][y] == 'L') {
				yy += 2;
			} else if (s[x][y] == 'R') {
				yy -= 2;
			} else throw;
			int to = (!checkCell(xx, yy) ? 0 : id[xx][yy]);
			g[(x + y) & 1][to].push_back(id[x][y]);
		}
	n = k;
	for (int i = 0; i < 2; i++) {
		T[i] = 0;
		dfs(i, 0);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int i = 1; i < n; i++) {
		ev[evSz++] = Event(t[0][i][0], t[1][i][0], t[1][i][1], 1);
		ev[evSz++] = Event(t[0][i][1], t[1][i][0], t[1][i][1], -1);
	}
	sort(ev, ev + evSz);
	build();
	ll ans = 0;
	for (int i = 0; i < evSz; i++) {
		if (i > 0) {
			int val = L;
			assert(tree[1].val.first == 0);
			val -= tree[1].val.second;
			ans += (ll)val * (ev[i].x - ev[i - 1].x);
		}
		addOnSegm(1, ev[i].y1, ev[i].y2, ev[i].add);
	}
	printf("%lld\n", ans);

	return 0;
}