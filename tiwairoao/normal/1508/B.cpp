#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

int a[N + 5], n; ll k;

void solve() {
	scanf("%d%lld", &n, &k), k--; int t = n, l = n;
	for(int i=n;i>1;i--) {
		if( !(k & 1) ) {
			for(int j=i;j<=l;j++) a[t--] = j;
			l = i - 1;
		}
		k >>= 1;
	}
	for(int i=1;i<=l;i++) a[t--] = i;
	if( k ) puts("-1");
	else {
		for(int i=1;i<=n;i++) printf("%d ", a[i]);
		puts("");
	}
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}