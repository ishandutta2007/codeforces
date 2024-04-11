#include <bits/stdc++.h>

typedef long long ll;

const int N = 500000;

int c[N + 5], n, k;

int id[N + 5], res[N + 5];
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d", &c[i]);
	std::sort(c + 1, c + n + 1);
	
	ll s = 0, t = 0;
	for(int i=n;i>=1;i--) {
		if( c[i] >= 0 ) s += t, t += c[i];
		else break;
	}	
	
	int tmp = 0, pos = k + 1;
	for(int i=1;i<=n;i++) if( c[i] < 0 ) {
		if( pos > k ) tmp++, pos = 0;
		id[i] = tmp, res[i] = (pos++), s += 1ll * (tmp - 1) * c[i];
	}
	
	ll ans = tmp * t + s, tot = 0;
	for(int i=n;i>=1;i--) if( c[i] < 0 ) {
		tot += c[i];
		if( res[i] != 0 ) {
			s += tot, tmp++;
			ans = std::max(ans, tmp * t + s);
		}
	}
	printf("%lld\n", ans);
}