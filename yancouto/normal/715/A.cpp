#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

int main() {
	scanf("%d", &n);
	printf("2\n");
	for(ll i = 2; i <= n; i++) {
		ll v = i * (i + 1) * (i + 1) - (i - 1);
		assert(v <= 1000000000000000000ll);
		printf("%lld\n", v);
	}
}