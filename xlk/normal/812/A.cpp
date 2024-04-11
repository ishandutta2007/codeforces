#include <bits/stdc++.h>
using namespace std;
int a[4][4];
bool solve() {
	for (int i = 0; i < 4; i++) {
		if (a[i][3] && (a[i][0] || a[i][1] || a[i][2] || a[(i + 1) % 4][0] || a[(i + 2) % 4][1] || a[(i + 3) % 4][2])) {
			return true;
		}
	}
	return false;
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%s\n", solve() ? "YES" : "NO");
	return 0;
}