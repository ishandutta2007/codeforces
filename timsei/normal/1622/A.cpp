#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int T, n, m, a, b, c;

void rmain() {
	scanf("%d%d%d", &a, &b, &c);
	if((a + b + c) & 1) {
		puts("NO");
		return;
	}
	if(a > b) swap(a, b);
	if(b > c) swap(b, c);
	if(a + b == c) {
		puts("YES");
		return;
	} else {
		if(a == b || b == c || c == a) {
			puts("YES");
			return;
		}
	}
	puts("NO");
} 

int main() {
	for(cin >> T; T --;) rmain();
}