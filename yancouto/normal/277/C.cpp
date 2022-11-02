#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n, m, k;

int go(int tot, int all, unordered_map<int, vector<pii> > &cut, unordered_map<int, int> &uncut) {
	int x = 0;
	for(auto &it : cut) {
		sort(it.snd.begin(), it.snd.end());
		int last = 0, s = 0, cut = 0;
		for(pii p : it.snd) {
			if(s) cut += p.fst - last;
			s += p.snd;
			last = p.fst;
		}
		uncut[it.fst] = all - cut;
		x ^= (all - cut);
		// printf("%d uncut\n", all - cut);
	}
	if((tot - 1 - cut.size()) % 2) x ^= (all);
	return x;
}

int go2(int last, int tot, int all, unordered_map<int, vector<pii> > &cut) {
	if(((tot - 1 - cut.size()) % 2) && (all & (1 << last))) {
		for(int i = 1; i <= tot; i++)
			if(!cut.count(i))
				return i;
	}
	return 0;
}

int go3(int last, int tot, int all, unordered_map<int, int> &uncut) {
	for(auto &it : uncut) {
		if(it.snd & (1 << last))
			return it.fst;
	}
	return 0;
}


int main() {
	int i, j, xb, yb, xe, ye;
	scanf("%d %d %d", &n, &m, &k);
	unordered_map<int, vector<pii> > cutm, cutn;
	for(i = 0; i < k; i++) {
		scanf("%d %d %d %d", &xb, &yb, &xe, &ye);
		if(xb == xe) {
			if(ye < yb) swap(ye, yb);
			cutm[xb].pb(pii(yb, 1));
			cutm[xb].pb(pii(ye, -1));
		} else {
			if(xe < xb) swap(xe, xb);
			cutn[yb].pb(pii(xb, 1));
			cutn[yb].pb(pii(xe, -1));
		}
	}
	unordered_map<int, int> uncutm, uncutn;
	int x = go(n, m, cutm, uncutm) ^ go(m, n, cutn, uncutn);
	if(!x) { puts("SECOND"); return 0; }
	puts("FIRST");
	int last = 0;
	for(i = 0; (1 << i) <= x; i++)
		if((1 << i) & x)
			last = i;
	int a = go2(last, n, m, cutm);
	if(a) {
		printf("%d %d %d %d\n", a, 0, a, m - (m ^ x));
		return 0;
	}
	a = go2(last, m, n, cutn);
	if(a) {
		printf("%d %d %d %d\n", 0, a, n - (n ^ x), a);
		return 0;
	}
	a = go3(last, n, m, uncutm);
	if(a) {
		int last = 0, s = 0, cut = 0; int qt = uncutm[a] - (x ^ uncutm[a]);
		for(pii p : cutm[a]) {
			if(s) cut += p.fst - last;
			s += p.snd;
			if((p.fst - cut) >= qt) {
				printf("%d %d %d %d\n", a, 0, a, p.fst - ((p.fst - cut) - qt));
				return 0;
			}
			last = p.fst;
		}
		printf("%d %d %d %d\n", a, 0, a, n - ((n - cut) - qt));
		return 0;
	}
	a = go3(last, m, n, uncutn);
	if(a) {
		int last = 0, s = 0, cut = 0; int qt = uncutn[a] - (x ^ uncutn[a]);
		for(pii p : cutn[a]) {
			if(s) cut += p.fst - last;
			s += p.snd;
			if((p.fst - cut) >= qt) {
				printf("%d %d %d %d\n", 0, a, p.fst - ((p.fst - cut) - qt), a);
				return 0;
			}
			last = p.fst;
		}
		printf("%d %d %d %d\n", 0, a, m - ((m - cut) - qt), a);
	}
	return 0;
}