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
int mn[1000009], mx[1000009], tim[1000009];


int main() {
	int i, x;
	scanf("%d", &n);
	int mxtim = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d", &x);
		if(mn[x] == 0) mn[x] = i;
		mx[x] = i;
		tim[x]++;
		mxtim = max(mxtim, tim[x]);
	}
	int l = 1, r = n+1;
	for(i = 0; i < 1000009; i++) {
		if(tim[i] == mxtim && (mx[i] - mn[i] + 1) < (r - l + 1)) {
			l = mn[i];
			r = mx[i];
		}
	}
	printf("%d %d\n", l, r);
	return 0;
}