#include <bits/stdc++.h>

typedef long long ll;

const int S = (1 << 20);

int read() {
	int x = 0, ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10 * x + ch - '0', ch = getchar();
	return x;
}

ll ans[2][25], res; int a[S + 5], t[S + 5];
void solve(int d, int l, int r) {
	if( l == r ) return ;
	int m = (l + r) >> 1; solve(d - 1, l, m), solve(d - 1, m + 1, r);
	
	int pl = l, pr = m + 1, p = l;
	while( pl <= m && pr <= r ) {
		if( a[pl] <= a[pr] ) t[p++] = a[pl++], ans[1][d] += pr - m - 1, res += pr - m - 1;
		else t[p++] = a[pr++];
	}
	while( pl <= m ) t[p++] = a[pl++], ans[1][d] += pr - m - 1, res += pr - m - 1;
	while( pr <= r ) t[p++] = a[pr++];
	
	pl = l, pr = m + 1, p = l;
	while( pl <= m && pr <= r ) {
		if( a[pl] < a[pr] ) t[p++] = a[pl++];
		else t[p++] = a[pr++], ans[0][d] += pl - l;
	}
	while( pl <= m ) t[p++] = a[pl++];
	while( pr <= r ) t[p++] = a[pr++], ans[0][d] += pl - l;
	
	for(int i=l;i<=r;i++) a[i] = t[i];
}

void write(ll x) {
	if( x / 10 ) write(x / 10);
	putchar(x % 10 + '0');
}

int s, n, m;
int main() {
	n = read(), s = (1 << n);
	for(int i=1;i<=s;i++) a[i] = read();
	solve(n, 1, s);
	
	m = read();
	for(int i=1,x;i<=m;i++) {
		x = read();
		for(int j=0;j<=x;j++) {
			res -= ans[1][j];
			std::swap(ans[0][j], ans[1][j]);
			res += ans[1][j];
		}
		write(res), puts("");
	}
}