#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
ll ma[18][18], a[18];
ll memo[(1 << 18) + 1][18];
int m, n;
ll solve(int bm, int l) {
	if(__builtin_popcount(bm) == m) return 0;
	ll &r = memo[bm][l];
	if(r != -1) return r;
	for(int i = 0; i < n; i++)
		if(!(bm & (1 << i)))
			r = max(r, solve(bm | (1 << i), i) + a[i] + ma[l][i]);
	return r;
}

int main() {
	int i, k, u, v;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for(i = 0; i < k; i++) {
		scanf("%d %d", &u, &v);
		scanf("%I64d", &ma[--u][--v]);
	}
	ll mx = 0;
	memset(memo, -1, sizeof memo);
	for(i = 0; i < n; i++)
		mx = max(mx, solve(1 << i, i) + a[i]);
	printf("%I64d\n", mx);
}