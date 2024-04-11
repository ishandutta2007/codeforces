#include <bits/stdc++.h>
using namespace std;
int n, y;
char s[1020][10];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		if (s[i][0] == 'O' && s[i][1] == 'O') {
			s[i][0] = s[i][1] = '+';
			y = 1;
			break;
		}
		if (s[i][3] == 'O' && s[i][4] == 'O') {
			s[i][3] = s[i][4] = '+';
			y = 1;
			break;
		}
	}
	printf("%s\n", y ? "YES" : "NO");
	if (y) {
		for (int i = 0; i < n; i++) {
			printf("%s\n", s[i]);
		}
	}
	return 0;
}