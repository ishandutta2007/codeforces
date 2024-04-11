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
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n;
struct tree {
	int x, a, seen;
	inline void read() { scanf("%d %d", &x, &a); }
	tree() : seen(0), x(0) {}
	bool operator < (const tree &o) const { return x < o.x; }
} ts[200], ts2[200];

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		ts[i].read();
		ts2[i] = ts[i];
	}
	ts[n] = tree();
	ts2[n] = tree();
	ts[n].seen = ts2[n].seen = 1;
	n++;
	sort(ts, ts + n);
	sort(ts2, ts2 + n);
	int z = lower_bound(ts, ts  + n, tree()) - ts;
	i = z;
	int coll = 0;
	int left = 1;
	while(i >= 0 && i < n) {
		if(!ts[i].seen) {
			ts[i].seen = 1;
			coll += ts[i].a;
			left = -left;
		}
		i -= left;
	}
	i = z;
	int colr = 0;
	int right = 1;
	while(i >= 0 && i < n) {
		if(!ts2[i].seen) {
			ts2[i].seen = 1;
			colr += ts2[i].a;
			right = -right;
		}
		i += right;
	}
	printf("%d\n", max(coll, colr));
}