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
int n, k;
ull S;
ull fat[22];
int fn;
int a[26];
struct val {
	ull v;
	int k;
	val() {}
	val(ull a, int b) : v(a), k(b) {}
	bool operator < (const val &o) const { return v < o.v || (v == o.v && k < o.k); }
} h[2][1600000];
int hn[2], lim[2];

void half(int i, ull v, int kk, int ind) {
	if(v > S) return;
	if(kk > k) return;
	if(i == lim[ind]) {
		h[ind][hn[ind]++] = val(v, kk);
//		printf("%d\n", hn[ind]);
		return;
	}
	half(i + 1, v, kk, ind);
	half(i + 1, v + a[i], kk, ind);
	if(a[i] <= fn)
		half(i + 1, v + fat[a[i]], kk + 1, ind);
}

int main() {
	int i, j;
	fat[0] = 1;
	for(fn = 1; fat[fn - 1] < 10000000000000000llu; fn++) {
		fat[fn] = fat[fn - 1] * fn;
	}
	scanf("%d %d %I64u", &n, &k, &S);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	lim[0] = ((n + 1)/2);
//	printf("lim[0] = %d\n", lim[0]);
	half(0, 0, 0, 0);
	sort(h[0], h[0] + hn[0]);
	lim[1] = n;
	half(lim[0], 0, 0, 1);
	sort(h[1], h[1] + hn[1]);
	ull tot = 0;
	for(i = 0; i < hn[1]; i++)
		tot += upper_bound(h[0], h[0] + hn[0], val(S - h[1][i].v, k - h[1][i].k)) - lower_bound(h[0], h[0] + hn[0], val(S - h[1][i].v, 0));
	printf("%I64u\n", tot);
	return 0;
}