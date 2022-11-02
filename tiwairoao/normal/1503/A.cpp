#include <bits/stdc++.h>

const int N = 200000;

char s[N + 5]; int n;

void solve() {
	scanf("%d%s", &n, s + 1);
	
	int c = 0; for(int i=1;i<=n;i++) c += (s[i] == '1');
	if( s[1] == '0' || s[n] == '0' || (c & 1) ) puts("NO");
	else {
		puts("YES");
		for(int i=1,t=0,o=0;i<=n;i++) {
			if( s[i] == '1' ) t++, putchar(t <= (c >> 1) ? '(' : ')');
			else o ^= 1, putchar(o ? '(' : ')');
		}
		puts("");
		for(int i=1,t=0,o=0;i<=n;i++) {
			if( s[i] == '1' ) t++, putchar(t <= (c >> 1) ? '(' : ')');
			else o ^= 1, putchar(o ? ')' : '(');
		}
		puts("");
	}
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}