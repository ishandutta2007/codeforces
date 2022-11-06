#include<stdio.h>
char a[130][10];
char in[10];
int main() {
	int n;
	scanf("%s%d", in, &n);
	for (int i = 0; i < n; i++)scanf("%s", a[i]);
	bool s0 = false, s1 = false;
	for (int i = 0; i < n; i++) {
		if (a[i][0] == in[0] && a[i][1] == in[1]) {
			printf("YES\n");
			return 0;
		}
		if (a[i][1] == in[0]) s0 = true;
		if (a[i][0] == in[1]) s1 = true;
	}
	if (s0 && s1) {
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}