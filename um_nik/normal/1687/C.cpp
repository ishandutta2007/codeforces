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
vector<int> g[N];
int n;
ll a[N], b[N];
set<int> setik;
int q[N];
int topQ;

void fixSegm(int l, int r) {
	if (l > r) swap(l, r);
	while(true) {
		auto it = setik.lower_bound(l);
		if (it == setik.end()) break;
		if (*it > r) break;
		int x = *it;
		setik.erase(it);
		q[topQ++] = x;
	}
}

bool solve() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		g[i].clear();
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i + 1]);
		a[i + 1] += a[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i + 1]);
		b[i + 1] += b[i];
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		g[l].push_back(r);
		g[r].push_back(l);
	}
	if (a[n] != b[n]) return false;
	topQ = 0;
	setik.clear();
	for (int i = 0; i <= n; i++) {
		if (a[i] == b[i])
			q[topQ++] = i;
		else
			setik.insert(i);
	}
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (int u : g[v]) {
			if (setik.count(u)) continue;
			fixSegm(v, u);
		}
	}
	return setik.empty();
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}