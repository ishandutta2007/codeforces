#include <iostream>
#include <cstring>
using namespace std;
char s[100020];
int c[26], cnt;
int main() {
	scanf("%s", s);
	int n = strlen(s);
	if (n < 26) {
		printf("-1\n");
		return "fuck", 0;
	}
	for (int i = 0; i < 25; i++) {
		if (s[i] != '?') {
			if (c[s[i] - 'A'] > 1) {
				cnt--;
			}
			c[s[i] - 'A']++;
			if (c[s[i] - 'A'] > 1) {
				cnt++;
			}
		}
	}
	for (int i = 25; i < n; i++) {
		if (s[i] != '?') {
			if (c[s[i] - 'A'] > 1) {
				cnt--;
			}
			c[s[i] - 'A']++;
			if (c[s[i] - 'A'] > 1) {
				cnt++;
			}
		}
		if (cnt == 0) {
			for (int j = 0; j < n; j++) {
				if (s[j] == '?') {
					if (j < i - 25 || j > i) {
						s[j] = 'A';
					} else {
						for (int k = 0; k < 26; k++) {
							if (c[k] == 0) {
								c[k] = 1;
								s[j] = 'A' + k; 
								break;
							}
						}
					}
				}

			}
			puts(s);
			return 0;
		}

		if (s[i - 25] != '?') {
			if (c[s[i - 25] - 'A'] > 1) {
				cnt--;
			}
			c[s[i - 25] - 'A']--;
			if (c[s[i - 25] - 'A'] > 1) {
				cnt++;
			}
		}

	}
	puts("-1");
	return 0;
}