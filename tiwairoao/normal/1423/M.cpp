#include <bits/stdc++.h>

typedef std::vector<int> vi;

const int N = 1000000;

int ans = int(1E9);
void report() {printf("! %d\n", ans), fflush(stdout);}
int query(int x, int y) {
	printf("? %d %d\n", x + 1, y + 1), fflush(stdout);
	int k; scanf("%d", &k), ans = std::min(ans, k); return k;
}

int nw[N + 5], val[N + 5], lst[N + 5], nxt[N + 5];
int get(int x, int y) {
	if( nw[x] != y ) nw[x] = y, val[x] = query(x, y);
	return val[x];
}
void cut(int x) {
	lst[nxt[x]] = lst[x], nxt[lst[x]] = nxt[x];
}
vi reduce(const vi &r, const vi &c) {
	int n = (int)r.size(), m = (int)c.size(), k = m;
	
	for(int i=0;i<n;i++) nw[r[i]] = val[r[i]] = -1;
	for(int i=0;i<m;i++) nxt[i] = i + 1, lst[i + 1] = i; nxt[m] = 0, lst[0] = m;
	for(int p=0,q=0;k>n;) {
		if( get(r[p], c[q]) <= get(r[p], c[nxt[q]]) ) {
			if( p + 1 == n ) cut(nxt[q]), k--;
			else p++, q = nxt[q];
		} else {
			p--, q = lst[q], cut(nxt[q]), k--;
			if( p < 0 ) p++, q = nxt[q];
		}
	}
	
	vi c1; for(int p=nxt[m];p!=m;p=nxt[p]) c1.push_back(c[p]);
	return c1;
}

int pos[N + 5];
void smawk(const vi &r, const vi &c) {
	vi c1 = reduce(r, c);
	if( r.size() == 1 )
		pos[r[0]] = c1[0];
	else {
		vi r1; for(int i=1;i<(int)r.size();i+=2) r1.push_back(r[i]);
		smawk(r1, c1);
		
		int mn = int(1E9), p = 0;
		while( true ) {
			int k = query(r[0], c1[p]);
			if( k < mn ) mn = k, pos[r[0]] = c1[p];
			if( c1[p] == pos[r[1]] ) break;
			p++;
		}
		
		for(int i=2;i+1<(int)r.size();i+=2) {
			mn = int(1E9);
			while( true ) {
				int k = query(r[i], c1[p]);
				if( k < mn ) mn = k, pos[r[i]] = c1[p];
				if( c1[p] == pos[r[i + 1]] ) break;
				p++;
			}
		}
		
		if( r.size() & 1 ) {
			mn = int(1E9);
			while( p < (int)c1.size() ) {
				int k = query(r[r.size() - 1], c1[p]);
				if( k < mn ) mn = k, pos[r[r.size() - 1]] = c1[p];
				p++;
			}
		}		
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vi r(n), c(m);
	for(int i=0;i<n;i++) r[i] = i;
	for(int j=0;j<m;j++) c[j] = j;
	smawk(r, c), report();
}