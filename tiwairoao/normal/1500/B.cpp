#include <bits/stdc++.h>

typedef long long ll;

const int N = 1000000;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int a[N + 5], b[N + 5], n, m, m1, d;

int c[2*N + 5];

int tmp[2*N + 5];
ll calc(int x) {
	ll ret = 0;
	for(int i=0;i<d;i++) {
		int cnt = 0;
		for(int j=i,t=0;t<m1;j=(j+n>=m?j+n-m:j+n),t++) tmp[cnt++] = j;
		for(int j=0;j<cnt;j++) tmp[j + cnt] = tmp[j];
		
		for(int j=0;j<x;j++) c[b[tmp[j]]]++;
		for(int j=0;j<cnt;j++) {
			if( tmp[j] < n ) ret += c[a[tmp[j]]];
			c[b[tmp[j]]]--, c[b[tmp[j + x]]]++;
		}
		for(int j=0;j<x;j++) c[b[tmp[j]]]--;
	}
	return 1ll * x * n - ret;
}

ll solve(ll k) {	
	int l = 0, r = m1;
	while( l < r ) {
		int mid = (l + r + 1) >> 1;
		if( calc(mid) > k ) r = mid - 1;
		else l = mid;
	}
	
	ll ret = 1ll * n * l; k -= calc(l);
	
	while( k >= 0 ) {
		if( a[ret % n] != b[ret % m] ) k--;
		ret++;
	}
	
	return ret;
}

ll fun1() {
	ll ret = 0;
	for(int i=0;i<d;i++) {
		for(int j=i;j<n;j+=d) c[a[j]]++;
		for(int j=i;j<m;j+=d) ret += c[b[j]];
		for(int j=i;j<n;j+=d) c[a[j]]--;
	}
	return ret;
}

int main() {
	ll k; scanf("%d%d%lld", &n, &m, &k), k--, d = gcd(n, m);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	for(int i=0;i<m;i++) scanf("%d", &b[i]);
	
	if( n > m ) {
		for(int i=0;i<n;i++) std::swap(a[i], b[i]);
		std::swap(n, m);
	}
	m1 = m / d;
	
	/*
	{
		for(int i=0;;i++) {
			if( a[i % n] != b[i % m] ) k--;
			if( k < 0 ) {
			printf("%d\n", i + 1);
			return 0;}
		}
		return 0;
	}*/
	
	ll t = 1ll * n / d * m, s = t - fun1(); assert( s );
	ll ans = (k / s) * t; k %= s;
	printf("%lld\n", ans + solve(k));
}