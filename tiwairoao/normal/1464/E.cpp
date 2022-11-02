#include <bits/stdc++.h>

const int N = 100000;
const int P = 998244353;
const int IV2 = (P + 1) >> 1;

inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int)(1ll * x * y % P);}
int mpow(int b, int p) {
	int r; for(r = 1; p; p >>= 1, b = mul(b, b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

std::vector<int>G[N + 5];
void adde(int u, int v) {G[u].push_back(v);}

int f[(1 << 17) + 5], s;
void fwt(int *a, int n, int type) {
	for(int j=1;j<n;j<<=1) for(int i=0;i<n;i++) if( i & j ) {
		int x = a[i], y = a[i - j];
		if( type == 1 ) a[i - j] = add(x, y), a[i] = sub(y, x);
		else a[i - j] = mul(add(x, y), IV2), a[i] = mul(sub(y, x), IV2);
	}
}

bool tag[N + 5];
int sg[N + 5], a[N + 5], ind[N + 5], pro, n, m;
void calc() {
	for(int i=1;i<=n;i++) for(auto to : G[i]) ind[to]++;
	
	std::queue<int>que; int p = 0;
	for(int i=1;i<=n;i++) if( !ind[i] ) que.push(i);
	while( !que.empty() ) {
		int x = que.front(); a[++p] = x, que.pop();
		for(auto to : G[x]) {
			ind[to]--; if( ind[to] == 0 ) que.push(to);
		}
	}
	for(int i=n;i>=1;i--) {
		for(auto to : G[a[i]]) tag[sg[to]] = true;
		while( tag[sg[a[i]]] ) sg[a[i]]++; f[sg[a[i]]] = add(f[sg[a[i]]], pro);
		for(auto to : G[a[i]]) tag[sg[to]] = false;
	}
}

int main() {
	scanf("%d%d", &n, &m), pro = mpow(n + 1, P - 2);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d", &u, &v), adde(u, v);
	calc();
	
	for(s = 1; s <= n; s <<= 1);
	fwt(f, s, 1);
	for(int i=0;i<s;i++) f[i] = mpow(sub(1, f[i]), P - 2);
	fwt(f, s, -1);
	printf("%d\n", sub(1, mul(f[0], pro)));
}