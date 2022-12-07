#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			printf("%d ", (i + 1) % n + 1);
		puts("");
	}
	return 0;
}