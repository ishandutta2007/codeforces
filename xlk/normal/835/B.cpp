#include <bits/stdc++.h>
using namespace std;
int k;
char s[100020];
int main() {
	scanf("%d", &k);
	scanf("%s", s);
	int n = strlen(s);
	sort(s, s + n);
	int c = 0;
	for (int i = 0; i < n; i++) {
		c += s[i] - '0';
	}
	if (c >= k) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		c = c - s[i] + '9';
		if (c >= k) {
			printf("%d\n", i + 1);
			break;
		}
	}
	return 0;
}