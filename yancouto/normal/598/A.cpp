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
	for_tests(t, tt) {
		int i, j, n;
		scanf("%d", &n);
		ll tot = (ll(n) * ll(n + 1)) / 2ll;
		int lg = 31 - __builtin_clz(n);
		tot -= 2ll * ((1ll << (lg + 1)) - 1);
		printf("%I64d\n", tot);
	}
}