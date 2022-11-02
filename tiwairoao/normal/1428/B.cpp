#include <bits/stdc++.h>

const int N = 300000;

char s[N + 5];
void solve() {
	int n; scanf("%d%s", &n, s);
	
	bool flag = true;
	for(int i=0;i<n;i++) if( s[i] == '<' ) {flag = false; break;}
	if( flag ) {printf("%d\n", n); return ;}
	
	flag = true;
	for(int i=0;i<n;i++) if( s[i] == '>' ) {flag = false; break;}
	if( flag ) {printf("%d\n", n); return ;}
	
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += (s[i] == '-');
		ans += (s[i] == '-' && s[(i + 1) % n] != '-');
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) solve();
}