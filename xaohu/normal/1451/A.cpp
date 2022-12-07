#include <bits/stdc++.h>
using namespace std;



int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int ans;
		if (n == 1) ans = 0;
		else if (n == 2) ans = 1;
		else if (n == 3) ans = 2;
		else if (n % 2 == 0) ans = 2;
		else ans = 3;
		printf("%d\n", ans);
	}
	return 0;
}