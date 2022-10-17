#include <bits/stdc++.h>
using namespace std;
char s[100020];
int main() {
	scanf("%s", s);
	int n = strlen(s);
	int f = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] <= 'a' + f) {
			s[i] = 'a' + f;
			f++;
		}
		if (f == 26) {
			break;
		}
	}
	if (f == 26) {
		printf("%s\n", s);
	} else {
		printf("-1\n");
	}
	return 0;
}