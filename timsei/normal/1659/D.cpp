#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int t, n, a, b, c[N], x[N], S[N];
char s[N];
bool vis[N];

void rmain() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%lld", &c[i]);
		c[i] += i;
		vis[i] = 1;
	}
	
	int cur = 0;
	while(c[cur + 1] == cur + 1 && cur <= n) {
		++ cur;
	}
	if(cur >= n) {
		for(int i = 1; i <= n; ++ i) printf("0 ");
		puts("");
		return;
	}
	for(int i = 1; i <= cur; ++ i) {
		vis[i] = 0;
	}
	for(int i = cur + 1; i <= n; ++ i) {
		int now = c[i] - vis[i] * (i - 1);
		if(now <= n) vis[now] = 0;
	}
	for(int i = 1; i <= n; ++ i) printf("%d ", vis[i]);
	puts("");
}

main() {
	for(cin >> t; t --;) {
		rmain();
	}
}