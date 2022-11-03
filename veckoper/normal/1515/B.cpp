#include <bits/stdc++.h>
using namespace std;
int Case, n;
inline bool Calc(int n) {
	int x = sqrt(n);
	while ((x + 1) * (x + 1) <= n) ++x;
	while (x * x > n) --x;
	return x * x == n;
}
int main() {
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d", &n);
		if ((n % 2 == 0 && Calc(n / 2)) || (n % 4 == 0 && Calc(n / 4))) {
			puts("YES");
		} else puts("NO");
	}
	return 0;
}