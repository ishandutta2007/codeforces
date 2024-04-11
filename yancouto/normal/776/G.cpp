#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

ll n;
ll memo[20][20][2][2];
ll solve(int i, int mx, bool pre, bool hit) {
	if(i < 0) return hit;
	ll &r = memo[i][mx][pre][hit];
	if(r != -1) return r;
	r = 0;
	bool b = ((mx / 4) == i);
	for(int d = 0; d < 16; d++) {
		if(d > mx) break;
		if(pre && d > ((n >> (4 * i)) & 15)) break;
		if(b && ((d >> (mx % 4)) & 1) == 0) continue;
		r += solve(i - 1, mx, pre && (d == ((n >> (4 * i)) & 15)), hit || (d == mx));
	}
	return r;
}

ll solve(ll x) {
	if(x <= 0) return 0;
	n = x;
	memset(memo, -1, sizeof memo);
	ll tot = 0;
	for(int i = 1; i <= 15; i++)
		tot += solve(15, i, true, false);
	return tot;
}

int main() {
	int q;
	scanf("%d", &q);
	while(q--) {
		ull a, b;
		scanf("%llx %llx", &a, &b);
		ll A = a, B = b;
		printf("%lld\n", solve(B) - solve(A - 1));
	}
}