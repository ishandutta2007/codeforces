#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, t, A[N], ans;

char s[N];

void rmain() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int ans = 9;
	for(int i = 1; i <= n; ++ i) ans = min(ans, (int)s[i] - '0');
	if(n >= 3) {
		printf("%d\n", ans);
		return;
	} else {
		if(n == 2) {
			putchar(s[2]);
			puts("");
			return;
		} else {
			puts(s);
		}
	}
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}