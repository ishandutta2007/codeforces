#include <bits/stdc++.h>
using namespace std;
int a, b;
long long z = 1;
int main() {
	scanf("%d%d", &a, &b);
	for (int i = 0; i < a && i < b; i++) {
		z *= i + 1;
	}
	printf("%lld\n", z);
	return 0;
}