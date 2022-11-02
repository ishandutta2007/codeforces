#include <bits/stdc++.h>

const int N = 500;

char s[N + 5][N + 5]; int n, m;

char t[N + 5][N + 5];
void solve() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%s", s[i] + 1);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) t[i][j] = s[i][j];
		t[i][m + 1] = 0;
	}
	
	if( n % 3 == 0 ) {
		for(int i=2;i<=n;i+=3) {
			for(int j=1;j<=m;j++) t[i][j] = 'X';
			
			if( i + 2 <= n ) {
				bool flag = false;
				for(int j=1;j<=m;j++) {
					if( t[i + 1][j] == 'X' ) {t[i + 2][j] = 'X'; flag = true; break;}
					if( t[i + 2][j] == 'X' ) {t[i + 1][j] = 'X'; flag = true; break;}
				}
				if( !flag ) t[i + 1][1] = t[i + 2][1] = 'X';
			}
		}
	} else {
		for(int i=1;i<=n;i+=3) {
			for(int j=1;j<=m;j++) t[i][j] = 'X';
			
			if( i + 2 <= n ) {
				bool flag = false;
				for(int j=1;j<=m;j++) {
					if( t[i + 1][j] == 'X' ) {t[i + 2][j] = 'X'; flag = true; break;}
					if( t[i + 2][j] == 'X' ) {t[i + 1][j] = 'X'; flag = true; break;}
				}
				if( !flag ) t[i + 1][1] = t[i + 2][1] = 'X';
			}
		}
	}
	for(int i=1;i<=n;i++) puts(t[i] + 1);
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) solve();
}