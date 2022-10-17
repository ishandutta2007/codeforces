#include <cstdio>

const int A = 26;
const int N = 200000;
int t, amt[A];
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		for (int i = 0; i < A; ++i) amt[i] = 0;
		for (int i = 0; s[i]; ++i) ++amt[s[i] - 'a'];
		int i;
		for (i = 0; amt[s[i] - 'a'] > 1; ++i) --amt[s[i] - 'a'];
		printf("%s\n", s + i);
	}
	return 0;
}