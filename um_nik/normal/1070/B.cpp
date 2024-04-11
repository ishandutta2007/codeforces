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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair<ll, int> pli;

const int M = 200200;
const int N = (int)75e5;
int go[N][2];
int b[N];
int m;
pli ans[M];
int ansSz;

int newNode() {
	go[m][0] = go[m][1] = -1;
	b[m] = 0;
	return m++;
}

void read() {
	newNode();
	int n;
	cin >> n;
	string s;
	vector<int> term;
	while(n--) {
		cin >> s;
		int t = 0;
		if (s[0] == '+') t = 1;
		s[0] = ' ';
		for (int i = 0; i < (int)s.length(); i++)
			if (s[i] == '.' || s[i] == '/')
				s[i] = ' ';
		istringstream is(s);
		vector<int> a;
		int x;
		while(is >> x)
			a.push_back(x);
		if ((int)a.size() == 4) a.push_back(32);
		ll mask = 0;
		for (int i = 0; i < 4; i++)
			mask = (mask << 8) | a[i];
		int L = 32 - a[4];
		int v = 0;
		for (int i = 31; i >= L; i--) {
			b[v] |= 1 << t;
			int c = (mask >> i) & 1;
			if (go[v][c] == -1)
				go[v][c] = newNode();
			v = go[v][c];
		}
		b[v] |= 1 << t;
		term.push_back(v);
	}
	for (int v : term) {
		if (b[v] == 3) {
			cout << "-1\n";
			exit(0);
		}
	}
}

void dfs(int v, int L, ll mask) {
	if ((b[v] & 1) == 0) return;
	if (b[v] == 1) {
		ans[ansSz++] = mp(mask, 32 - L);
		return;
	}
	L--;
	if (L < 0) throw;
	for (int c = 0; c < 2; c++) {
		if (go[v][c] == -1) continue;
		dfs(go[v][c], L, mask ^ ((ll)c << L));
	}
}

void printIP(ll mask, int L) {
	printf("%lld.%lld.%lld.%lld/%d\n", (mask >> 24) & 255, (mask >> 16) & 255, (mask >> 8) & 255, mask & 255, L);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	dfs(0, 32, 0);
	cout << ansSz << "\n";
	for (int i = 0; i < ansSz; i++)
		printIP(ans[i].first, ans[i].second);

	return 0;
}