#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = 3e3 + 10;

int r, c, n, k;
pair<int, int> a[N];
vector<int> g[N];
int prv[N], nxt[N];
int cu, cv, u[N], v[N], take[N];
int cur_ans;
long long ans;

bool cmp(pair<int, int> u, pair<int, int> v) {
	if (u.sc != v.sc) return u.sc < v.sc;
	return u.fr < v.fr;
}

int getPrv(int x) {
	if (x < 0) return x;
	if (prv[x] != x) prv[x] = getPrv(prv[x]);
	return prv[x];
}

int getNxt(int x) {
	if (x == n) return x;
	if (nxt[x] != x) nxt[x] = getNxt(nxt[x]);
	return nxt[x];
}

void ers(int x) {
	if ((x == 0) || (x == n - 1)) return;
	cu = cv = 0;
	for (int i = x; (cu <= k); i = getPrv(i - 1)) {
		u[cu++] = i;
		if (u[cu - 1] == 0) break;
	}
	for (int i = x; (cv <= k); i = getNxt(i + 1)) {
		v[cv++] = i;
		if (v[cv - 1] == n - 1) break;
	}
	// cerr << cu << " " << cv << endl;
	// for (int i = 0; i < cu; i++) cerr << u[i] << " ";
	// 	cerr << endl;
	// for (int i = 0; i < cv; i++) cerr << v[i] << " ";
	// 	cerr << endl;
	prv[x] = x - 1;
	nxt[x] = x + 1;
	for (int i = 0; i + 1 < cu; i++) {
		if (k-i < cv) {
			cur_ans -= (a[u[i]].sc - a[u[i+1]].sc) * (a[v[k-i]].sc - a[v[k-i-1]].sc);
		}
	}

}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d%d%d", &r, &c, &n, &k);
	// r = c = n = 3000;
	//k = 10;
	vector< vector<bool> > used(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].fr, &a[i].sc);
		--a[i].fr; --a[i].sc;
		// a[i] = mp(i + 1, n - i);
		// a[i].fr = rand() % r;
		// a[i].sc = rand() % c;
		// while (used[a[i].fr][a[i].sc]) {
		// 	a[i].fr = rand() % r;
		// 	a[i].sc = rand() % c;			
		// }
		// used[a[i].fr][a[i].sc] = 1;
	}
	a[n++] = mp(r-1, -1);
	a[n++] = mp(r-1, c);
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		g[a[i].fr].pb(i);
	}
	for (int i = 0; i < r; i++) {
		memset(take, 0, sizeof(take));
		for (int j = i; j < r; j++) {
			for (int e = 0; e < (int)g[j].size(); e++) take[g[j][e]] = 1;
		}
		// cerr << i << ": ";
		// for (int j = 0; j < c; j++) cerr << take[j] << " ";
		// cerr << endl;
		int lst = 0;
		for (int j = 0; j < n; j++) {
			if (take[j]) lst = j;
			prv[j] = lst;
		}
		lst = n - 1;
		for (int j = n - 1; j >= 0; j--) {
			if (take[j]) lst = j;
			nxt[j] = lst;
		}
		int v = 0, cs = 0;
		cur_ans = 0;
		for (int u = 1; (u + 1 < n) && (v + 1 < n); u++) {
			while ((v + 1 < n) && (cs < k)) {
				++v;
				cs += take[v];
			}
			// cerr << cs << endl;
			cur_ans += (a[u].sc - a[u - 1].sc) * (c - a[v].sc);
			cs -= take[u];
		}
		// cerr << i << " " << r - 1 << ": " << cur_ans << endl;
		for (int j = r - 1; j >= i; j--) {
			ans += cur_ans;
			for (int e = 0; e < (int)g[j].size(); e++) ers(g[j][e]);
		}
	}
	cout << ans << endl;
	return 0;	
}