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

const int N = 200200;
int n, m;
bool REV = false;
vector<pii> a[N], b[N];
int mt[N];
bool used[N];
vector<int> cc;

bool dfs(int v, int u) {
	if (mt[v] != -1) {
		if (mt[v] == u) return true;
		return false;
	}
	if (used[u]) return false;
	used[u] = 1;
	mt[v] = u;
	cc.push_back(v);
	if ((int)a[v].size() != (int)b[u].size()) return false;
	for (int i = 0; i < (int)a[v].size(); i++) {
		if (a[v][i].first != b[u][i].first) return false;
		if (!dfs(a[v][i].second, b[u][i].second)) return false;
	}
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	if (n > m) {
		REV = true;
		swap(n, m);
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++) {
				int z;
				scanf("%d", &z);
				if (z == 0) continue;
				a[y].push_back(mp(z, n + x));
				a[n + x].push_back(mp(z, y));
			}
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++) {
				int z;
				scanf("%d", &z);
				if (z == 0) continue;
				b[y].push_back(mp(z, n + x));
				b[n + x].push_back(mp(z, y));
			}
	} else {
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				int z;
				scanf("%d", &z);
				if (z == 0) continue;
				a[x].push_back(mp(z, n + y));
				a[n + y].push_back(mp(z, x));
			}
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				int z;
				scanf("%d", &z);
				if (z == 0) continue;
				b[x].push_back(mp(z, n + y));
				b[n + y].push_back(mp(z, x));
			}
	}
	for (int i = 0; i < n + m; i++) {
		sort(all(a[i]));
		sort(all(b[i]));
		mt[i] = -1;
		used[i] = 0;
	}
	for (int v = 0; v < n; v++) if (mt[v] == -1) {
		for (int x = 0; x < n; x++) {
			if (dfs(v, x)) {
				cc.clear();
				break;
			} else {
				for (int u : cc) {
					used[mt[u]] = 0;
					mt[u] = -1;
				}
				cc.clear();
			}
		}
		if (mt[v] == -1) {
			printf("-1\n");
			return 0;
		}
	}
	int u = n;
	for (int v = n; v < n + m; v++) if (mt[v] == -1) {
		while(used[u]) u++;
		mt[v] = u;
		used[u] = 1;
	}

	for (int i = 0; i < n + m; i++)
		eprintf("%d -- %d\n", i, mt[i]);

	vector<array<int, 3>> ans;
	for (int i = 0; i < n; i++) {
		if (mt[i] == -1) continue;
		vector<int> cyc;
		int v = i;
		while(mt[v] != -1) {
			cyc.push_back(v);
			int u = mt[v];
			mt[v] = -1;
			v = u;
		}
		//reverse(all(cyc));
		for (int j = (int)cyc.size() - 2; j >= 0; j--) {
			ans.push_back({(int)REV, cyc[j], cyc[j + 1]});
		}
	}
	for (int i = n; i < n + m; i++) {
		if (mt[i] == -1) continue;
		vector<int> cyc;
		int v = i;
		while(mt[v] != -1) {
			cyc.push_back(v);
			int u = mt[v];
			mt[v] = -1;
			v = u;
		}
		//reverse(all(cyc));
		for (int j = (int)cyc.size() - 2; j >= 0; j--) {
			ans.push_back({(int)REV ^ 1, cyc[j] - n, cyc[j + 1] - n});
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d %d %d\n", 1 + ans[i][0], ans[i][1] + 1, ans[i][2] + 1);

	return 0;
}