#include <bits/stdc++.h>

const int N = 10000;

char s[N + 5];

int main() {
	scanf("%s", s);
	for(int i=2;s[i];i++) {
		int a = s[i - 2] - 'A', b = s[i - 1] - 'A', c = s[i] - 'A';
		if( (a + b) % 26 != c ) {puts("NO"); return 0;}
	}
	puts("YES");
}