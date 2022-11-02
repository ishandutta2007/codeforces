#include <bits/stdc++.h>

const int N = 200000;

int nxt[2*N + 5], lst[2*N + 5];

int a[2][N + 5], p[2*N + 5]; bool b[2*N + 5];
inline int f(int x) {return a[!b[x]][p[x]];}
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d", &a[0][i], &a[1][i]);
		p[a[0][i]] = p[a[1][i]] = i, b[a[0][i]] = 0, b[a[1][i]] = 1;
	}
	for(int i=1;i<=(n<<1);i++) nxt[i] = i + 1, lst[i] = i - 1;
	
	int ans = 0, l = 1, r = (n << 1);
	while( l < r ) {
		if( p[l] == p[r] ) l++, r--;
		else {
			int s1 = (b[l]) + (b[r]), s2 = (!b[l]) + (!b[r]);
			
			nxt[lst[f(l)]] = nxt[f(l)], lst[nxt[f(l)]] = lst[f(l)];
			nxt[lst[f(r)]] = nxt[f(r)], lst[nxt[f(r)]] = lst[f(r)];
			while( true ) {
				if( f(r) > f(l) ) {
					puts("-1"); return 0;
				} else if( nxt[l] < f(r) ) {
					if( f(nxt[l]) > f(l) ) {
						puts("-1"); return 0;
					}
					
					l = nxt[l];
					nxt[lst[f(l)]] = nxt[f(l)];
					lst[nxt[f(l)]] = lst[f(l)];
					s1 += (b[l]), s2 += (!b[l]);
				} else if( lst[r] > f(l) ) {
					if( f(lst[r]) < f(r) ) {
						puts("-1"); return 0;
					}
					
					r = lst[r];
					nxt[lst[f(r)]] = nxt[f(r)];
					lst[nxt[f(r)]] = lst[f(r)];
					s1 += (b[r]), s2 += (!b[r]);
				} else break;
			}
			
			l = nxt[l], r = lst[r], ans += std::min(s1, s2);
		}
	}
	printf("%d\n", ans);
}