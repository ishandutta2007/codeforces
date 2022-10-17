#include <bits/stdc++.h>
using namespace std;
char s[20];
int n;
bool check() {
	char t[20];
	memcpy(t, s, sizeof s);
	reverse(t, t + n);
	return strcmp(s, t) == 0;
}
int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		char c = s[i];
		for (char j = 'a'; j <= 'z'; j++) {
			if (j == c) {
				continue;
			}
			s[i] = j;
			if (check()) {
				printf("YES\n");
				return 0;
			}
		}
		s[i] = c;
	}
	printf("NO\n");
	return 0;
}