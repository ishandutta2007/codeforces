#include <bits/stdc++.h>

const int N = 100000;

char s[3][(N << 1) + 5]; int n;

int a[N + 5], b[N + 5];
void print(int i1, int j1, int o) {
	a[0] = -1;
	int c = 0; for(int l=0;l<(n<<1);l++) if( s[i1][l] - '0' == o ) {
		a[++c] = l; if( c == n ) break;
	}
	a[++c] = (n << 1);
	
	b[0] = -1;
	c = 0; for(int l=0;l<(n<<1);l++) if( s[j1][l] - '0' == o ) {
		b[++c] = l; if( c == n ) break;
	}
	b[++c] = (n << 1);
	
	for(int i=1;i<=n+1;i++) {
		for(int j=a[i-1]+1;j<=a[i]-1;j++) putchar(s[i1][j]);
		for(int j=b[i-1]+1;j<=b[i]-1;j++) putchar(s[j1][j]);
		if( i != n + 1 ) putchar(o + '0');
	}
	puts("");
}

int cnt[3][2];
void solve() {
	scanf("%d", &n);
	for(int o=0;o<3;o++) {
		scanf("%s", s[o]), cnt[o][0] = cnt[o][1] = 0;
		for(int i=0;i<(n<<1);i++) cnt[o][s[o][i] - '0']++;
	}
	
	for(int i1=0;i1<=1;i1++) for(int i2=i1+1;i2<=2;i2++) {
		for(int o=0;o<=1;o++) if( cnt[i1][o] >= n && cnt[i2][o] >= n ) {
			print(i1, i2, o); return ;
		}
	}
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}