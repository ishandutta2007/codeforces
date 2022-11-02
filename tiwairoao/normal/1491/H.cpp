#include <bits/stdc++.h>

const int B = 320;
const int N = 100000;

int a[N + 5], n;

int nxt[N + 5], id[N + 5];
int le[N + 5], ri[N + 5], tg[N + 5], vis[N + 5], bcnt;
void pushtag(int x) {
	if( tg[x] ) {
		for(int i=le[x];i<=ri[x];i++)
			a[i] = std::max(a[i] - tg[x], 1);
	}
	tg[x] = 0;
}
void rebuild1(int x) {
	vis[x] = false;
	for(int i=le[x];i<=ri[x];i++) {
		if( a[i] < le[x] ) nxt[i] = a[i];
		else nxt[i] = nxt[a[i]], vis[x] = true;
	}
}
void build() {
	for(int i=1;i<=n;i++) {
		if( (i - 1) % B == 0 ) le[++bcnt] = i;
		ri[bcnt] = i, id[i] = bcnt;
	}
	for(int i=1;i<=bcnt;i++) rebuild1(i);
}

void sub(int l, int r, int x) {
	int p = id[l], q = id[r];
	if( p == q ) {
		if( !vis[p] ) pushtag(p);
		for(int i=l;i<=r;i++) a[i] = std::max(a[i] - x, 1);
		rebuild1(p);
	} else {
		if( !vis[p] ) pushtag(p);
		for(int i=l;i<=ri[p];i++) a[i] = std::max(a[i] - x, 1);
		rebuild1(p);
		
		for(int i=p+1;i<=q-1;i++) {
			if( vis[i] ) {
				for(int j=le[i];j<=ri[i];j++)
					a[j] = std::max(a[j] - x, 1);
				rebuild1(i);
			} else tg[i] += x;
		}
		
		if( !vis[q] ) pushtag(q);
		for(int i=le[q];i<=r;i++) a[i] = std::max(a[i] - x, 1);
		rebuild1(q);
	}
}
int gnxt(int x) {return std::max(nxt[x] - tg[id[x]], 1);}
int ga(int x) {return std::max(a[x] - tg[id[x]], 1);}
int query(int u, int v) {
	while( gnxt(u) != gnxt(v) ) {
		if( gnxt(v) < gnxt(u) ) u = gnxt(u);
		else v = gnxt(v);
	}
	
	while( ga(u) != ga(v) ) {
		if( ga(v) < ga(u) ) u = ga(u);
		else v = ga(v);
	}
	if( u == v ) return u;
	else return ga(u);
}

int main() {
	int q; scanf("%d%d", &n, &q);
	for(int i=2;i<=n;i++) scanf("%d", &a[i]);
	build();
	
	for(int i=1,t,l,r,x,u,v;i<=q;i++) {
		scanf("%d", &t);
		if( t == 1 ) {
			scanf("%d%d%d", &l, &r, &x), sub(l, r, x);
		} else {
			scanf("%d%d", &u, &v), printf("%d\n", query(u, v));
		}
	}
}