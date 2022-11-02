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
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int a[5], b[5];
int main() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) a[i % 5]++;
	for(i = 1; i <= m; i++) b[i % 5]++;
	ll tot = 0;
	for(i = 0; i < 5; i++) tot += ll(a[i]) * ll(b[(5 - i) % 5]);
	printf("%lld\n", tot);
}