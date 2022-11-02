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
	int i, j, n;
	scanf("%d", &n);
	ll tot = 0; ll a, mx = 0;
	for(i = 0; i < n; i++) {
		scanf("%I64d", &a);
		tot += a;
		mx = max(mx, a);
	}
	printf("%I64d\n", max(mx, (tot + ll(n) - 2ll) / ll(n - 1)));
}