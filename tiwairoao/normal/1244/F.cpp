#include<cstdio>
const int MAXN = 200000;
char s[MAXN + 5];
int n, k;
int lst(int x) {return x == 1 ? n : x - 1;}
int nxt(int x) {return x == n ? 1 : x + 1;}
char func(char ch, int k) {
	if( k & 1 )
		return (ch == 'W' ? 'B' : 'W');
	else return ch;
}
bool tag[MAXN + 5];
int lf[MAXN + 5]; char lc[MAXN + 5];
int rf[MAXN + 5]; char rc[MAXN + 5];
int main() {
	scanf("%d%d%s", &n, &k, s + 1);
	int pos = -1;
	for(int i=1;i<=n;i++)
		if( s[nxt(i)] == s[i] || s[lst(i)] == s[i] )
			pos = i, tag[i] = true;
	if( pos == -1 ) {
		for(int i=1;i<=n;i++)
			putchar(func(s[i], k));
	}
	else {
		lf[pos] = rf[pos] = 0, lc[pos] = rc[pos] = s[pos];
		for(int i=nxt(pos);i!=pos;i=nxt(i)) {
			if( tag[i] ) lf[i] = 0, lc[i] = s[i];
			else lf[i] = lf[lst(i)] + 1, lc[i] = lc[lst(i)];
		}
		for(int i=lst(pos);i!=pos;i=lst(i)) {
			if( tag[i] ) rf[i] = 0, rc[i] = s[i];
			else rf[i] = rf[nxt(i)] + 1, rc[i] = rc[nxt(i)];
		}
		for(int i=1;i<=n;i++) {
			if( lf[i] > k && rf[i] > k )
				putchar(func(s[i], k));
			else if( lf[i] <= rf[i] )
				putchar(lc[i]);
			else putchar(rc[i]);
		}
	}
}