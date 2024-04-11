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

string s;
int pairing[N];
vector<int> g[N];
int val[N];
int n, m;
int starId;
int st[N];
int stSz;
bool used[N];

int parse(int l, int r) {
	if (l == r) {
		if (s[l] != '*') throw;
		return starId++;
	}
	if (s[l] != '(' || s[r] != ')') throw;
	int v = m++;
	g[v].clear();
	val[v] = 0;
	char typ = '0';
	l++;
	while(true) {
		if (s[l] == '(') {
			g[v].push_back(parse(l, pairing[l]));
			l = pairing[l] + 1;
		} else if (s[l] == '*') {
			g[v].push_back(parse(l, l));
			l++;
		} else throw;
		if (l == r) break;
		if (s[l] == 'S' || s[l] == 'P') {
			if (typ == '0')
				typ = s[l];
			if (typ != s[l]) throw;
		} else throw;
		l++;
	}
	if (typ == 'S') {
		int bst = -1;
		for (int u : g[v]) {
			if (bst == -1 || val[bst] > val[u])
				bst = u;
		}
		val[v] = val[bst];
		g[v].clear();
		g[v].push_back(bst);
	} else {
		for (int u : g[v])
			val[v] += val[u];
	}
	return v;
}

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v])
		dfs(u);
}

void solve() {
	ll zzz;
	cin >> zzz;
	getline(cin, s);
	n = 0;
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == ' ') continue;
		s[n++] = s[i];
	}
	s.resize(n);
	m = 0;
	starId = 0;
	for (int i = 0; i < n; i++) {
		pairing[i] = -1;
		if (s[i] == '*') m++;
		if (s[i] == '(') {
			st[stSz++] = i;
		}
		if (s[i] == ')') {
			stSz--;
			if (stSz < 0) throw;
			pairing[i] = st[stSz];
			pairing[st[stSz]] = i;
		}
	}
	if (stSz != 0) throw;
	for (int i = 0; i < m; i++) {
		g[i].clear();
		val[i] = 1;
	}
	int V = parse(0, n - 1);
	for (int i = 0; i < m; i++)
		used[i] = false;
	dfs(V);
	cout << "REVOLTING";
	for (int i = 0; i < starId; i++) {
		if (used[i]) {
			cout << " " << zzz * val[V];
		} else {
			cout << " 0";
		}
	}
	cout << "\n";
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}