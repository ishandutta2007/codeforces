#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int S[N], n, tmp[N];

void prework(int n = 50) {
	S[1] = 0;
	for(int i = 2; i <= n; ++ i) {
		memset(tmp, 0, sizeof(tmp));
		for(int j = 1; j < i; ++ j) {
			tmp[S[i - j] ^ S[j]] = 1;
		}
		for(S[i] = 0; tmp[S[i]]; ++ S[i]);
	}
}

void rmain() {
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; ++ i) {
		int x; scanf("%d",&x);
		ans = ans ^ S[x];
	}
	if(ans) puts("errorgorn");
	else puts("maomao90");
}

int main() {
	prework();
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}