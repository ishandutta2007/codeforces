#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;

bitset<405>bts[405];
int f[405], nxt[30], n, m, l, sz;
char ans[205], s[205], vc[30], t1[2], t2[2];
bool check(int p, int k) {
	int x; memset(f, -1, sizeof f);
	for(int i=0;i<p;i++) {
		x = ((i << 1) | (vc[s[i] - 'a'] == 'C'));
		if( f[x] == -1 ) {
			if( !bts[x][x^1] ) {
				f[x] = 1, f[x^1] = 0;
				for(int j=0;j<l;j++)
					if( bts[x][j] ) f[j] = 1, f[j^1] = 0;
			} else return false;
		} else if( f[x] == 0 ) return false;
		ans[i] = s[i];
	}
	
	x = ((p << 1) | (vc[k] == 'C'));
	if( f[x] == -1 ) {
		if( !bts[x][x^1] ) {
			f[x] = 1, f[x^1] = 0;
			for(int j=0;j<l;j++)
				if( bts[x][j] ) f[j] = 1, f[j^1] = 0;
		} else return false;
	} else if( f[x] == 0 ) return false;
	ans[p] = k + 'a';
	
	for(int i=p+1;i<n;i++) {
		x = ((i << 1) | (vc[0] == 'C'));
		if( f[x] == -1 ) {
			if( !bts[x][x^1] ) {
				f[x] = 1, f[x^1] = 0;
				for(int j=0;j<l;j++)
					if( bts[x][j] ) f[j] = 1, f[j^1] = 0;
				ans[i] = 'a';
			} else if( !bts[x^1][x] && nxt[0] != -1 ) {
				f[x] = 0, f[x^1] = 1;
				for(int j=0;j<l;j++)
					if( bts[x^1][j] ) f[j] = 1, f[j^1] = 0;
				ans[i] = nxt[0] + 'a';
			} else return false;
		} else if( f[x] == 1 ) ans[i] = 'a';
		else if( nxt[0] != -1 ) ans[i] = nxt[0] + 'a';
		else return false;
	}
	
	puts(ans); return true;
}
int main() {
	scanf("%s%d%d", vc, &n, &m);
	l = (n << 1), sz = strlen(vc);
	for(int i=0,p1,p2;i<m;i++) {
		scanf("%d%s%d%s", &p1, t1, &p2, t2);
		p1 = ((p1 - 1) << 1 | (t1[0] == 'C'));
		p2 = ((p2 - 1) << 1 | (t2[0] == 'C'));
		bts[p1][p2] = bts[p2^1][p1^1] = true;
	}
	scanf("%s", s);
	
	for(int i=0;i<sz;i++) {
		nxt[i] = -1;
		for(int j=i;j<sz;j++)
			if( vc[j] != vc[i] ) {
				nxt[i] = j;
				break;
			}
	}
	
	for(int k=0;k<l;k++)
		for(int i=0;i<l;i++)
			if( bts[i][k] ) bts[i] |= bts[k];
	
	memset(f, -1, sizeof f);
	for(int i=0;i<=n;i++) {
		if( i == n ) {
			puts(s);
			return 0;
		}
		else {
			bool flag = true;
			
			int x = ((i << 1) | (vc[s[i] - 'a'] == 'C'));
			if( f[x] == -1 ) {
				if( !bts[x][x^1] ) {
					f[x] = 1, f[x^1] = 0;
					for(int j=0;j<l;j++)
						if( bts[x][j] ) f[j] = 1, f[j^1] = 0;
					flag = true;
				} else flag = false;
			} else flag = (f[x] == 1);
			
			if( !flag ) {
				for(;i>=0;i--) {
					bool f[2] = {};
					for(int p=s[i]-'a'+1;p<sz;p++)
						if( !f[vc[p] == 'C'] ) {
							f[vc[p] == 'C'] = true;
							if( check(i, p) ) return 0;
						}
				}
				puts("-1"); return 0;
			}
		}
	}
}