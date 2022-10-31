#include <bits/stdc++.h>

const int N = 10000000;
const int P = int(1E9) + 7;

inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int)(1ll * x * y % P);}
int mpow(int b, int p) {
	int r; for(r = 1; p; p >>= 1, b = mul(b, b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

int s[N + 5], pw2[N + 5];
int prm[N / 10 + 5], mu[N + 5], pcnt; bool nprm[N + 5];
void init() {
	mu[1] = 1;
	for(int i=2;i<=N;i++) {
		if( !nprm[i] ) prm[++pcnt] = i, mu[i] = -1;
		for(int j=1;i*prm[j]<=N;j++) {
			nprm[i * prm[j]] = true;
			if( i % prm[j] == 0 ) {
				mu[i * prm[j]] = 0;
				break;
			} else mu[i * prm[j]] = -mu[i];
		}
	}
	pw2[0] = 1; for(int i=1;i<=N;i++) pw2[i] = mul(2, pw2[i - 1]);
	
	for(int i=1;i<=pcnt;i++)
		for(int j=N/prm[i];j>=1;j--)
			s[j] = add(s[j], s[prm[i] * j]);
}

int main() {
	int n; scanf("%d", &n);
	for(int i=1,x;i<=n;i++) scanf("%d", &x), s[x]++;
	init();
	
	int ans = 0;
	for(int i=1;i<=N;i++) {
		if( !mu[i] || s[i] < 1 ) continue;
		
		int del = mul(sub(s[i], n), sub(pw2[s[i]], 1));
		if( mu[i] == 1 ) ans = add(ans, del);
		else ans = sub(ans, del);
	}
	printf("%d\n", ans);
}