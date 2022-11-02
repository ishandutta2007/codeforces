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

int main() {
	ll n, k;
	scanf("%I64d %I64d", &n, &k); n--; k--;
	if(n == 0) { puts("0"); return 0; }
	if((k * (k + 1ll)) / 2ll < n) { puts("-1"); return 0; }
	ll l = 1, r = k;
	while(l < r) {
		ll m = (l + r + 1ll) / 2ll;
		if((((m + k) * (k - m + 1ll)) / 2ll) >= n) l = m;
		else r = m - 1;
	}
	printf("%I64d\n", k - l + 1);
}