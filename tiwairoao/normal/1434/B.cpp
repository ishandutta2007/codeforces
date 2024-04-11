#include <bits/stdc++.h>

const int N = 100000;

struct seg{
	int l, r, i;
	friend bool operator < (const seg &a, const seg &b) {
		return a.r - a.l < b.r - b.l;
	}
}c[N + 5];

int fa[N + 5], a[N + 5], b[N + 5], n;
int find(int x) {return fa[x] = (fa[x] == x ? x : find(fa[x]));}

int ans[N + 5], stk[N + 5], tp;
int main() {
	scanf("%d", &n);
	for(int i=1,cnt=0,p=0;i<=2*n;i++) {
		char op[2]; scanf("%s", op);
		if( op[0] == '+' ) cnt++;
		else scanf("%d", &a[++p]), b[p] = cnt;
	}
	
	a[0] = (1 << 30), stk[tp = 1] = 0;
	for(int i=1;i<=n;i++) {
		while( a[stk[tp]] < a[i] ) tp--;
		c[i] = (seg){b[stk[tp]] + 1, b[i], a[i]}, stk[++tp] = i;
	}
	
	std::sort(c + 1, c + n + 1);
	for(int i=0;i<=n+3;i++) fa[i] = i;
	for(int i=1;i<=n;i++) {
		int p = find(c[i].l);
		if( p > c[i].r ) {
			puts("NO");
			return 0;
		}
		ans[p] = c[i].i, fa[p] = p + 1;
	}
	puts("YES"); for(int i=1;i<=n;i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}