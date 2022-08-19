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

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

map<pll, int> toId;
int n, m;
int getId(pll p) {
	if (toId.count(p) == 0) {
		toId[p] = n++;
	}
	return toId[p];
}

pll getFrac(ll x, ll y) {
	ll g = gcd(x, y);
	return mp(x / g, y / g);
}

const int N = 400200;
vector<int> g[N];
int ed[N][2];
bool used[N];
bool usedEd[N];
vector<pii> ans;

int getOther(int id, int v) {
	return ed[id][0] ^ ed[id][1] ^ v;
}

bool dfs(int v, int par) {
	used[v] = 1;
	int lst = -1;
	for (int id : g[v]) {
		if (id == par) continue;
		if (usedEd[id]) continue;
		int u = getOther(id, v);
		if (!used[u]) {
			if (dfs(u, id)) continue;
		}
		usedEd[id] = true;
		if (lst == -1) {
			lst = id;
		} else {
			ans.push_back(mp(lst, id));
			lst = -1;
		}
	}
	if (lst != -1 && par != -1) {
		usedEd[par] = true;
		ans.push_back(mp(lst, par));
		return true;
	} else {
		return false;
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		ll a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		int v = getId(getFrac(c * b, d * (a + b)));
		int u = getId(getFrac((c + d) * b, d * a));
		ed[i][0] = v;
		ed[i][1] = u;
		g[v].push_back(i);
		g[u].push_back(i);
	}
	for (int v = 0; v < n; v++) {
		if (used[v]) continue;
		dfs(v, -1);
	}
	printf("%d\n", (int)ans.size());
	for (pii t : ans)
		printf("%d %d\n", t.first + 1, t.second + 1);

	return 0;
}