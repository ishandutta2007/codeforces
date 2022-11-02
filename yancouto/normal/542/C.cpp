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

int n;
int seen[203][203];
int f[203];

pii solve(int i) {
	seen[i][i] = 1;
	int r = i;
	for(int k = 2; ; k++) {
		r = f[r];
		if(seen[i][r]) return pii(seen[i][r] - 1, k - seen[i][r]);
		seen[i][r] = k;
	}
}

ull mdc(ull a, ull b) {
	if(b == 0) return a;
	return mdc(b, a % b);
}

int main() {
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &f[i]);
	ull mm = 1;
	int last = 0;
	for(i = 1; i <= n; i++) {
		pii p = solve(i);
		mm = (mm / mdc(mm, p.snd)) * p.snd;
		last = max(last, p.fst);
	}
	ull resp = mm;
	while(resp < last) resp += mm;
	printf("%I64u\n", resp);
}