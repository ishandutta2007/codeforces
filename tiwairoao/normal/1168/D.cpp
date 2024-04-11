#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 150000;

int ch[2][N + 5], a[N + 5], p[N + 5], c[N + 5], n, q;

int dep[N + 5], lfd;
bool check() {
	lfd = -1;
	for(int i=2;i<=n;i++) dep[i] = dep[p[i]] + 1;
	for(int i=2;i<=n;i++) if( !a[i] ) {
		if( lfd == -1 ) lfd = dep[i];
		else if( lfd != dep[i] ) return false;
	}
	return true;
}

int g[N + 5], f[26][N + 5], cnt;
int b[26][N + 5], u[N + 5], d[N + 5];
void add(int x, int k, int del) {
	b[k][x] += del;
	for(int y=u[x];x!=1;x=y,y=u[y]) {
		if( g[y] > lfd - dep[y] ) cnt--; g[y] -= f[k][y];
		int c0 = d[ch[0][y]], c1 = d[ch[1][y]];
		f[k][y] = max(f[k][c0] + b[k][c0], f[k][c1] + b[k][c1]);
		g[y] += f[k][y]; if( g[y] > lfd - dep[y] ) cnt++;
	}
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i=2;i<=n;i++) {
		char s[2]; scanf("%d%s", &p[i], s);
		c[i] = (s[0] == '?') ? -1 : s[0] - 'a';
		ch[a[p[i]]++][p[i]] = i;
	}
	if( !check() ) {
		for(int i=1,x;i<=q;i++) {
			char s[2]; scanf("%d%s", &x, s);
			puts("Fou");
		}
	} else {
		for(int i=2;i<=n;i++) u[i] = (p[i] != 1 && a[p[i]] == 1 ? u[p[i]] : p[i]);
		for(int i=n;i>=2;i--) d[i] = (a[i] == 1 ? d[ch[0][i]] : i);
		for(int i=2;i<=n;i++) if( c[i] != -1 ) add(d[i], c[i], 1);
		
		for(int i=1,x;i<=q;i++) {
			char s[2]; scanf("%d%s", &x, s);
			if( c[x] != -1 ) add(d[x], c[x], -1);
			c[x] = (s[0] == '?') ? -1 : (s[0] - 'a');
			if( c[x] != -1 ) add(d[x], c[x], 1);
			
			if( cnt ) puts("Fou");
			else {
				int ans = 0;
				for(int j=0;j<26;j++) ans += (j + 1) * (f[j][1] + lfd - g[1]);
				printf("Shi %d\n", ans);
			}
		}
	}
}