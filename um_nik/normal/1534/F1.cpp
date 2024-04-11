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

const int N = 400400;
string a[N];
vector<int> id[N];
vector<int> closest[N];
vector<int> g[N];
int k;
int n, m;
int b[N];
int topmost[N];
int uL[N];
int uR[N];
vector<pii> segm;

void addEdge(int v, int u) {
	g[v].push_back(u);
}

void dfs(int v, int p, int* us) {
	us[v] = p;
	for (int u : g[v]) {
		if (us[u] != -1) continue;
		dfs(u, p, us);
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
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++) {
		id[i] = vector<int>(m, -1);
		closest[i] = vector<int>(m, -1);
	}
	for (int y = 0; y < m; y++) {
		for (int x = n - 1; x >= 0; x--) {
			if (a[x][y] == '#') {
				id[x][y] = k++;
				closest[x][y] = id[x][y];
			} else if (x + 1 < n) {
				closest[x][y] = closest[x + 1][y];
			}
		}
	}
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (a[x][y] == '.') continue;
			int v = id[x][y];
			if (x + 1 < n && closest[x + 1][y] != -1)
				addEdge(v, closest[x + 1][y]);
			if (x > 0 && id[x - 1][y] != -1)
				addEdge(v, id[x - 1][y]);
			if (y > 0) {
				int u = closest[x][y - 1];
				if (u != -1) addEdge(v, u);
			}
			if (y + 1 < m) {
				int u = closest[x][y + 1];
				if (u != -1) addEdge(v, u);
			}
		}
	}
	for (int y = 0; y < m; y++) {
		topmost[y] = -1;
		for (int x = 0; x < n; x++) {
			if (id[x][y] != -1) {
				topmost[y] = id[x][y];
				break;
			}
		}
	}
	for (int v = 0; v < k; v++) {
		uL[v] = uR[v] = -1;
	}

	for (int i = 0; i < m; i++) {
		if (topmost[i] == -1) continue;
		int v = topmost[i];
		if (uL[v] != -1) continue;
		dfs(v, i, uL);
	}
	for (int i = m - 1; i >= 0; i--) {
		if (topmost[i] == -1) continue;
		int v = topmost[i];
		if (uR[v] != -1) continue;
		dfs(v, i, uR);
	}
	for (int i = 0; i < m; i++) {
		if (b[i] == 0) continue;
		int cur = b[i];
		for (int j = n - 1; j >= 0; j--) {
			if (id[j][i] == -1) continue;
			cur--;
			if (cur == 0) {
				segm.push_back(mp(uL[id[j][i]], uR[id[j][i]]));
				break;
			}
		}
	}
	sort(all(segm));
	for (pii s : segm) eprintf("(%d %d) ", s.first, s.second);
	eprintf("\n");
	int ans = 0;
	int cur = m;
	for (pii s : segm) {
		if (cur < s.first) {
			ans++;
			cur = s.second;
		} else {
			cur = min(cur, s.second);
		}
	}
	if (cur < m) ans++;
	printf("%d\n", ans);

	return 0;
}