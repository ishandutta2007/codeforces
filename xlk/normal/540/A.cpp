#include <bits/stdc++.h>
using namespace std;
int n, s;
char a[1020], b[1020];
int main() {
	scanf("%d%s%s", &n, a, b);
	for (int i = 0; i < n; i++) {
		s += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i]));
	}
	printf("%d\n", s);
	return 0;
}