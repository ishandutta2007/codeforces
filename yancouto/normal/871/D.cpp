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

const int N = 10000009;

int phi[N], pr[N], dv[N];

ll c2(ll n) {
	return (n * (n - 1ll)) / 2ll;
}

int main() {
	int i, j;
	for(i = 2; i < N; i++) phi[i] = i;
	for(i = 2; i < N; i++) {
		if(dv[i]) continue;
		pr[i] = 1;
		for(j = i; j < N; j += i) {
			phi[j] = int(phi[j] / i) * (i - 1);
			if(!dv[j]) dv[j] = i;
		}
	}
	scanf("%d", &n);
	for(i = n - 1; i >= 0; i--)
		pr[i] += pr[i + 1];
	ll pnc = 0;
	for(i = 2; i <= n; i++)
		pnc += ll(i - phi[i] - 1);
	ll tot = pnc + (c2(n - 1) - pnc) * 2ll;
	//printf("pnc %lld (c2 - pnc) %lld init tot %lld\n", pnc, c2(n - 1), tot);
	for(i = 2; i <= n; i++) {
		ll p = dv[i];
		int mn = max<int>(p + 1, (n / p) + 1);
		if(mn > n) continue;
		tot -= 2ll * pr[mn];
		int mn2 = n / 2;
		if(mn2 >= mn) tot += 3ll * (pr[mn] - pr[mn2 + 1]);
		//printf("at [%d] tot -= 2 * (pr[%d] = %d)\n", i, mn, pr[mn]);
		//printf("at [%d] tot += 3 * (pr[%d]  - (pr[%d] = %d))\n", i, mn, mn2 + 1, pr[mn2 + 1]);
	}
	printf("%lld\n", tot);
}