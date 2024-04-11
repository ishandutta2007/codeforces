#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int t, n, m, tot, S[N];
char s[N];

void rmain() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	int ans = 0;
	for(int i = 1; i <= n; ++ i) {
		ans += (s[i] == '0');
	}
	if(ans) {
		int g = __gcd(ans, n);
		if(m % (n / g)) {
			puts("-1");
			return;
		}
		ans = 1LL * ans * m / n;
	}
	for(int i = 1; i <= n; ++ i) 
	S[i] = S[i - 1] + (s[i] == '0');
	for(int i = 1; i <= n - m + 1; ++ i) {
		if(S[i + m - 1] - S[i - 1] == ans) {
			puts("1");
			printf("%d %d\n", i, i + m - 1);
			return;
		}
	}
	puts("2");
	for(int i = 1; i <= m; ++ i) {
		if(S[i] + S[n] - S[n - (m - i)] == ans) {
			printf("%d %d\n%d %d\n", 1, i, n - (m - i) + 1, n);
			return;
		}
	}
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}