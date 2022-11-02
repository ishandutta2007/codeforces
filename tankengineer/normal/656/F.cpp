#include<cstdio>

char s[10];

int main() {
	scanf("%s", s);
	int ans = 1;
	for (int i = 1; i < 7; ++i) {
		if (s[i] == '1') {
			ans += 10;
			++i;
		} else {
			ans += s[i] - '0';
		}
	}
	printf("%d\n", ans);
	return 0;
}