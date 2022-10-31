#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int B = 320;

int read() {
	int x = 0, ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10 * x + ch - '0', ch = getchar();
	return x;
}

int hd[B + 5], tl[B + 5], siz[B + 5], ans[B + 5][N + 5], bcnt;
int lst[3*N + 5], nxt[3*N + 5], id[N + 5], a[N + 5], n, cnt;

void link(int x, int y) {nxt[x] = y, lst[y] = x;}
void build() {
	int p = 0; cnt = n;
	for(int i=1;i<=n;i++) {
		if( (i - 1) % B == 0 ) {
			if( bcnt ) link(p, tl[bcnt] = (++cnt));
			p = hd[++bcnt] = (++cnt);
		}
		link(p, i), p = i, siz[id[i] = bcnt]++, ans[bcnt][a[i]]++;
	}
	link(p, tl[bcnt] = (++cnt));
}

int find(int p) {
	for(int i=1;i<=bcnt;i++) {
		if( siz[i] >= p ) {
			for(int j=nxt[hd[i]],k=1;j!=tl[i];k++,j=nxt[j])
				if( k == p ) return j;
			break;
		} else p -= siz[i];
	}
	assert(false); return -1;
}
void modify(int l, int r) {
	if( l == r ) return ;

	int p = find(l), q = find(r), x = id[p], y = id[q];
	if( x == y )
		link(lst[q], nxt[q]), link(lst[p], q), link(q, p);
	else {
		link(lst[q], nxt[q]), ans[y][a[q]]--;
		link(lst[p], q), link(q, p), ans[x][a[q]]++;
		id[q] = x;
		for(int i=x;i<y;i++) {
			int k = lst[tl[i]];
			link(lst[k], nxt[k]), ans[i][a[k]]--;
			link(k, nxt[hd[i + 1]]), link(hd[i + 1], k), ans[i + 1][a[k]]++;
			id[k] = i + 1;
		}
	}
}
int query(int l, int r, int k) {
	int p = find(l), q = find(r), x = id[p], y = id[q];
	if( x == y ) {
		int ret = 0;
		for(int i=p;i!=nxt[q];i=nxt[i]) ret += (a[i] == k);
		return ret;
	} else {
		int ret = 0;
		for(int i=p;i!=tl[x];i=nxt[i]) ret += (a[i] == k);
		for(int i=x+1;i<=y-1;i++) ret += ans[i][k];
		for(int i=q;i!=hd[y];i=lst[i]) ret += (a[i] == k);
		return ret;
	}
}

int main() {
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	build();
	
	int q = read();
	for(int i=1,lastans=0;i<=q;i++) {
		int opt = read(), l = (read() + lastans - 1) % n + 1, r = (read() + lastans - 1) % n + 1;
		if( l > r ) swap(l, r);
		if( opt == 1 ) {
			modify(l, r);
		} else {
			int k = (read() + lastans - 1) % n + 1;
			printf("%d\n", lastans = query(l, r, k));
		}
/*
		printf("! ");
		for(int x=1;x<=bcnt;x++)
			for(int i=nxt[hd[x]];i!=tl[x];i=nxt[i])
				printf(" %d", a[i]);
		puts("");
*/
	}
}