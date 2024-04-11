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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 500500;
int n;
vector<int> g[N];
char s[N];

bool solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	scanf("%s", s);
	if (n < 3) return false;
	if (n == 3) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == 'W')
				cnt++;
		return cnt >= 2;
	}
	for (int v = 0; v < n; v++)
		if (s[v] == 'W' && (int)g[v].size() > 1)
			return true;
	for (int v = 0; v < n; v++) {
		int d = (int)g[v].size();
		if (d >= 4) return true;
		if (d < 3) continue;
		bool ok = s[v] == 'W';
		int cnt = 0;
		for (int u : g[v]) {
			ok |= s[u] == 'W';
			if ((int)g[u].size() > 1) cnt++;
		}
		if (ok || cnt >= 2) return true;
	}
	vector<int> a;
	for (int v = 0; v < n; v++)
		if ((int)g[v].size() == 3)
			a.push_back(v);
	if ((int)a.size() == 0) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == 'W')
				cnt++;
		if (cnt < 2) return false;
		return n & 1;
	} else if ((int)a.size() == 1) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == 'W')
				cnt++;
		if (cnt < 1) return false;
		return n % 2 == 0;
	} else if ((int)a.size() == 2) {
		return n & 1;
	} else throw;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("White\n");
		else
			printf("Draw\n");
	}

	return 0;
}