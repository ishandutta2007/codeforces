#include <bits/stdc++.h>
using namespace std;
char x[120];
char z[120];
bool ok() {
	for (int i = 0; x[i]; i++) {
		if (x[i] < z[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	scanf("%s", x);
	scanf("%s", z);
	if (ok()) {
		printf("%s\n", z);
	} else {
		printf("-1\n");
	}
	return 0;
}