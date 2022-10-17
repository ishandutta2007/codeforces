#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, g;
int main() {
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	printf("%s\n", (a + b + c + 4) / 5 + (d + e + f + 9) / 10 > g ? "NO" : "YES");
	return 0;
}