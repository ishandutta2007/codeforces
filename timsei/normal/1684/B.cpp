#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, t, A[N], ans;

char s[N];

void rmain() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d %d %d\n", a + b + c, b + c, c);
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}