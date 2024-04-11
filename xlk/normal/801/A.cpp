#include <bits/stdc++.h>
using namespace std;
char s[120];
int n;
int calc() {
	int re = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'V' && s[i + 1] == 'K') {
			re++;
		}
	}
	return re;
}
int main() {
	scanf("%s", s);
	n = strlen(s);
	int ans = calc();
	for (int i = 0; i < n; i++) {
		s[i] = 'V' + 'K' - s[i];
		ans = max(ans, calc());
		s[i] = 'V' + 'K' - s[i];
	}
	printf("%d\n", ans);
	return 0;
}