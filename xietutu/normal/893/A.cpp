#include <bits/stdc++.h>
using namespace std;
int n, a, b;
bool flag;
int main() {
	scanf("%d", &n);
	flag = true;
	a = 1; b = 2;
	for (int i = 1; i <= n; ++i) {
		int w;
		scanf("%d", &w);
		int c = 6 - a - b;
		if (w == c) {
			flag = false;
			puts("NO");
			break;
		}
		else {
			if (w != a) swap(a, b);
			b = c;
		}
	}
	if (flag) puts("YES");
}