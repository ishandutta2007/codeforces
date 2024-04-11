#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 5;
const long long INF = 1e9 + 19;
const int BASE = 1e9 + 7;
 
using namespace std;

int ans[N];
vector< pair<int, int> > g[N];
int pw25[N], pw26[N], rpw26[N];
int fact[N], rfact[N];

int getLen() {
	char c = getchar();
	while (!(('a' <= c) && (c <= 'z'))) c = getchar();
	int l = 0;
	while (('a' <= c) && (c <= 'z')) {
		++l;
		c = getchar();
	}
	return l;
}

int C(int n, int k) {
	int res = (fact[n] * 1LL * rfact[k]) % BASE;
	res = (res * 1LL * rfact[n - k]) % BASE;
	return res;
}

int pw(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = (res * 1LL * x) % BASE;
		x = (x * 1LL * x) % BASE;
		y /= 2;
	}
	return res;
}

int main() {
	// freopen("input.txt", "r", stdin);
	int m, l;
	scanf("%d\n", &m);
	l = getLen();
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			l = getLen();
		} else {
			int n;
			scanf("%d", &n);
			if (n < l) {
				ans[i] = 0;
			} else {
				g[l].pb(mp(n, i));
			}
		}
	}
	// for (int i = 1; i < N; i++) {
	// 	for (int j = 0; j < (int)g[i].size(); j++) cerr << i << " " << g[i][j].first << endl;
	// }
	// return 0;
	pw25[0] = pw26[0] = 1;
	fact[0] = 1; rfact[0] = 1;
	for (int i = 1; i < N; i++) {
		pw25[i] = (pw25[i - 1] * 1LL * 25) % BASE;
		pw26[i] = (pw26[i - 1] * 1LL * 26) % BASE;
		rpw26[i] = pw(pw26[i], BASE - 2);
		fact[i] = (fact[i - 1] * 1LL * i) % BASE;
		rfact[i] = pw(fact[i], BASE - 2);
	}
	for (int len = 1; len < N; len++) {
		if (g[len].empty()) continue;
		sort(g[len].begin(), g[len].end());
		int j = 0;
		int csum = 0;
		for (int k = len; k <= g[len].back().first; k++) {
			int cur = C(k - 1, len - 1);
			// cerr << k << " " << len << " " << cur << endl;
			cur = (cur * 1LL * pw25[k-len]) % BASE;
			cur = (cur * 1LL * rpw26[k]) % BASE;
			csum += cur;
			if (csum >= BASE) csum -= BASE;
			while ((j < (int)g[len].size()) && (g[len][j].first == k)) {
				ans[g[len][j].second] = (csum * 1LL * pw26[k]) % BASE;
				++j;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (ans[i] != -1) {
			printf("%d\n", ans[i]);
		}
	}
}