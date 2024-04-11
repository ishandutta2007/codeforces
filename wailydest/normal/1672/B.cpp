#include <cstdio>
#include <cstring>

const int N = 200000;
int t, n;
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		n = strlen(s);
		int sum = 0;
		bool ok = 1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'A') ++sum;
			else --sum;
			if (sum < 0) ok = 0;
		}
		printf("%s\n", ok && s[n - 1] == 'B' ? "YES" : "NO");
	}
	return 0;
}