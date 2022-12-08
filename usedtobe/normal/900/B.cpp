#include<bits/stdc++.h>
using namespace std;
int a, b, c, tot;
map<int, bool> ma;
int main() {
	scanf("%d%d%d", &a, &b ,&c);
	while (1) {
		int p = a * 10 % b;
		if (ma.find(p) != ma.end()) {
			puts("-1");
			return 0;
		}
		++tot;
		if (a * 10 / b == c) return printf("%d\n", tot), 0;
		ma[p] = 1;
		a = p;
		if (a == 0 && c == 0) return printf("%d\n", tot + 1), 0;
	}
	return 0;
}