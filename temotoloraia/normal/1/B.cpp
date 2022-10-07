#include <cstdio>
int main() {
	int n, a, b, i;
	char s[100];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		if (sscanf(s, "%*[A-Z]%d%*[A-Z]%d", &a, &b) == 2) {
			i = 0;
			while (b) {
				s[i++] = 'A' + ((b - 1) % 26);
				b = (b - 1) / 26;
			}
			for (i--;i >= 0;i--) putchar(s[i]);
			printf("%d\n", a);
		} else {
			i = a = 0;
			for (;'A' <= s[i] && s[i] <= 'Z';i++)
				a = a * 26 + s[i] - 'A' + 1;
			sscanf(s + i, "%d", &b);
			printf("R%dC%d\n", b, a);
		}
	}
	return 0;
}