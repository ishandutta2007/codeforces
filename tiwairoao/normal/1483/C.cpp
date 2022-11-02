#include <bits/stdc++.h>

typedef long long ll;

const int N = 300000;

int h[N + 5], b[N + 5], n;

int ch[2][N + 5], rt;
void build() {
	static int stk[N + 5]; int tp = 0;
	for(int i=1;i<=n;i++) {
		while( tp && h[stk[tp]] > h[i] ) ch[0][i] = stk[tp--]; 
		if( tp ) ch[1][stk[tp]] = i;
		stk[++tp] = i;
	}
	rt = stk[1];
}

ll f[2][2][N + 5];
void dfs(int x, int l, int r) {
	if( !x ) return ;
	dfs(ch[0][x], l, x - 1), dfs(ch[1][x], x + 1, r);
	
	f[0][0][x] = b[x] + f[0][1][ch[0][x]] + f[1][0][ch[1][x]];
	f[1][0][x] = std::max(b[x] + f[1][1][ch[0][x]] + f[1][0][ch[1][x]],
		f[1][0][ch[1][x]]);
	f[0][1][x] = std::max(b[x] + f[0][1][ch[0][x]] + f[1][1][ch[1][x]],
		f[0][1][ch[0][x]]);
	f[1][1][x] = std::max({b[x] + f[1][1][ch[0][x]] + f[1][1][ch[1][x]],
		f[1][1][ch[0][x]], f[1][1][ch[1][x]]});
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &h[i]);
	for(int i=1;i<=n;i++) scanf("%d", &b[i]);
	build(), dfs(rt, 1, n);
	printf("%lld\n", f[0][0][rt]);
}