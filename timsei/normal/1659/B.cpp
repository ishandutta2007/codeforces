#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, r, b, cnt[N];
char s[N];

void rmain() {
	scanf("%d%d", &n, &r);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++ i) s[i] = s[i] - '0', cnt[i] = 0;
	if(r & 1)  {
		for(int i = 1; i <= n; ++ i) s[i] = s[i] ^ 1;
	}
	for(int i = 1; i <= n; ++ i) {
		if(r && !s[i]) {
			s[i] ^= 1;
			-- r; ++ cnt[i];
		} 
	}
	while(r) {
		cnt[n] += r;
		if(r & 1) s[n] ^= 1;
		r = 0;
	}
	for(int i = 1; i <= n; ++ i) putchar(s[i] + '0');
	puts("");
	for(int i = 1; i <= n; ++ i) printf("%d ", cnt[i]);
	puts("");
	
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}