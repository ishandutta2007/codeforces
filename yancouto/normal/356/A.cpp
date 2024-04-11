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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const int MAX = 300009;
struct ev {
	int sta;
	pii info;
	ev() {}
	ev(int a, int b, int c) : sta(a), info(b, c) {}
	bool operator < (const ev &o) const { return sta < o.sta; }
} p[MAX << 2];
int pi;
int n, m;

int main() {
	pi = 0;
	int i, j, l, r, x;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &l, &r, &x);
		if(l != x) { p[pi++] = ev(l, i, x); p[pi++] = ev(x, i, -x); }
		if(r != x) { p[pi++] = ev(x + 1, i, x); p[pi++] = ev(r + 1, i, -x); }
	}
	sort(p, p + pi);
	set<pii> s; int cur = 0;
	for(i = 1; i <= n; i++) {
		while(cur < pi && p[cur].sta < i) cur++;
		for(; cur < pi && p[cur].sta == i; cur++)
			if(p[cur].info.snd < 0)
				s.erase(pii(p[cur].info.fst, -p[cur].info.snd));
			else
				s.insert(p[cur].info);
		if(s.empty()) printf("0 ");
		else 
			printf("%d ", s.begin()->snd);
	}
	putchar('\n');
	return 0;
}