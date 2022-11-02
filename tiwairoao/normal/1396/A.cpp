#include <bits/stdc++.h>

const int N = 100000;

typedef long long ll;

void exgcd(ll a, ll b, ll &x, ll &y) {
	if( b == 0 ) {x = 1; y = 0;}
	else {
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
}

ll a[N + 5]; int n;

int main() {
	scanf("%d", &n); for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	if( n == 1 ) {
		printf("1 1\n%lld\n", -a[1]);
		puts("1 1\n0");
		puts("1 1\n0");
	} else {
		ll x, y; exgcd(n, n - 1, x, y);
		
		printf("1 %d\n", n);
		for(int i=1;i<=n;i++) {
			ll t = (a[i] % n + n) % n;
			t -= t * x * n;
			printf("%lld ", t - a[i]), a[i] = t;
		}
		puts("");
		
		printf("1 %d\n", n - 1);
		for(int i=1;i<=n-1;i++) printf("%lld ", -a[i]);
		puts("");
		
		printf("%d %d\n%lld\n", n, n, -a[n]);
	}
}