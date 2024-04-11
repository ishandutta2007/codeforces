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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int a[112345], b[112345];

int st[112345], sn;
int stv[112345];

int main() {
	int i, j;
	ll n, k, m;
	scanf("%lld %lld %lld", &n, &k, &m);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 0; i < n - 1 && a[i] == a[i + 1]; i++);
	if(i == n - 1) { printf("%lld\n", (n * m) % k); return 0; }
	for(i = 0; i < n; i++) {
		if(sn && stv[sn - 1] == a[i]) st[sn - 1]++;
		else { st[sn] = 1; stv[sn++] = a[i]; }
		while(sn && st[sn - 1] >= k) {
			st[sn - 1] %= k;
			if(st[sn - 1] == 0) sn--;
		}
	}
	n = 0;
	for(i = 0; i < sn; i++) {
		while(st[i]--)
			a[n++] = stv[i];
	}
	ll tot = n * m;
	if(tot == 0) { printf("0\n"); return 0; }
	for(i = 0; i < n - 1 && a[i] == a[i + 1]; i++);
	if(i == n - 1) { printf("%lld\n", (n * m) % k); return 0; }

	int l = 0, r = n - 1;
	while(true) {
		if(a[l] != a[r]) { debug("dif\n"); break; }
		int x = a[l];
		ll sz = 0;
		while(l <= r && a[l] == x) l++, sz++;
		while(l <= r && a[r] == x) r--, sz++;
		if(l == r + 1) {
			debug("all rest\n");
			if((sz * m) % k) {
				debug("rest not divis\n");
				tot -= ll((sz * m) / k) * k;
				break;
			} else {
				debug("rest divis\n");
				printf("0\n");
				return 0;
			}
		}
		if((sz % k)) {
			debug("not divis k\n");
			tot -= (m - 1ll) * ll(sz / k) * k;
			break;
		} else {
			debug("divis k continue\n");
			tot -= (m - 1ll) * sz;
		}
	}
	debug("out\n");
	printf("%lld\n", tot);
}