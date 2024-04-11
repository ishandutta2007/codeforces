#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

char s[N];

void rmain() {
	int n;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int lst = -1, sz = 0;
	s[0] = 'c'; s[n + 1] = 'c';
	for(int i = 1; i <= n; ++ i) {
		if(s[i] != s[i - 1] && s[i] != s[i + 1]) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}