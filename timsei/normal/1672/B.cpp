#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

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

char s[N];

void rmain() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int tot = 0;
	if(s[n] != 'A') {
		for(int i = 1; i <= n; ++ i) {
			if(s[i] == 'B') -- tot;
			else ++ tot;
			if(tot < 0) {
				puts("NO");
				return;
			}
		}
		puts("YES");
	} else puts("NO");
}

int main() {
	prework();
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}