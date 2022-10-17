#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 1; i <= 200000; i++) {
		a *= 10;
		if (a / b == c) {
			printf("%d\n", i);
			return 0;
		}
		a %= b;
	}
	printf("-1\n");
	return 0;
}