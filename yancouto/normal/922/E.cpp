#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
ll W, B, X;

int c[1123];
ll cost[1123];

#define tot first
#define cur second

ll memo[1009][10009];
bool seen[1009][10009];
ll solve(int i, int left) {
	if(i < 0) return left? -1e16 : W;
	ll &r = memo[i][left];
	if(seen[i][left]) return r;
	seen[i][left] = true;
	r = solve(i - 1, left);
	for(ll j = 1; j <= left && j <= c[i]; j++) {
		ll pr = solve(i - 1, left - j);
		//printf("(%d, %d) r = max(%lld, min(%lld - %lld * %lld, %lld + %lld * %lld))\n", i, left, r, pr, cost[i], j, W, left, B);
		if(pr >= cost[i] * j)
			r = max(r, min(pr - cost[i] * j, W + ll(left) * B));
	}
	if(r >= 0)
		r = min(r + X, W + ll(left) * B);
	//printf("solve(%d, %d) = %lld\n", i, left, r);
	return r;
}

int main() {
	int i;
	scanf("%d %lld %lld %lld", &n, &W, &B, &X);
	for(i = 0; i < n; i++) scanf("%d", &c[i]);
	for(i = 0; i < n; i++) scanf("%lld", &cost[i]);
	i = 0;
	while(solve(n - 1, i + 1) >= 0) i++;
	printf("%d\n", i);
}