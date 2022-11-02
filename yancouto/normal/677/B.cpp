#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

int main() {
	int i, j, n, h, k, x;
	scanf("%d %d %d", &n, &h, &k);
	ll tot = 0, cur = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		if(cur + x <= h) cur += x;
		else cur = x, tot++;
		tot += cur / k;
		cur %= k;
	}
	tot += (cur + ll(k) - 1ll) / k;
	printf(LLD "\n", tot);
}