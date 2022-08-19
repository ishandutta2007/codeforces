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

const int N = 300300;

int n;
vector<int> g1[N];
vector<int> g2[N];
set<pii> setik;
int ord[N];
int res, ans;
int did[N];
int t[N][2];
int T;

void dfs2(int v) {
	ord[T] = v;
	t[v][0] = T++;
	for (int u : g2[v])
		dfs2(u);
	t[v][1] = T;
}
void dfs1(int v) {
	auto it = setik.lower_bound(mp(t[v][0], -1));
	if (it != setik.end() && it->second <= t[v][1]) {
		did[v] = -2;
	} else {
		did[v] = -1;
		if (it != setik.begin()) {
			it--;
			if (it->second >= t[v][1])
				did[v] = ord[it->first];
		}
		if (did[v] != -1) {
			setik.erase(it);
		} else {
			res++;
			ans = max(ans, res);
		}
		setik.insert(mp(t[v][0], t[v][1]));
	}
	/*
	eprintf("in %d did %d\n", v, did[v]);
	eprintf("set now:");
	for (pii t : setik)
		eprintf(" (%d %d)", t.first, t.second);
	eprintf("\n");
	*/
	for (int u : g1[v])
		dfs1(u);
	if (did[v] != -2) {
		setik.erase(mp(t[v][0], t[v][1]));
		if (did[v] != -1) {
			setik.insert(mp(t[did[v]][0], t[did[v]][1]));
		} else {
			res--;
		}
	}
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		g1[i].clear();
		g2[i].clear();
	}
	for (int v = 2; v <= n; v++) {
		int x;
		scanf("%d", &x);
		g1[x].push_back(v);
	}
	for (int v = 2; v <= n; v++) {
		int x;
		scanf("%d", &x);
		g2[x].push_back(v);
	}
	T = 0;
	dfs2(1);
	for (int v = 1; v <= n; v++)
		eprintf("%d : [%d %d]\n", v, t[v][0], t[v][1]);
	ans = res = 0;
	setik.clear();
	dfs1(1);
	printf("%d\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int z;
	scanf("%d", &z);
	while(z--) solve();

	return 0;
}