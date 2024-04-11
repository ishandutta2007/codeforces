#include <cstdio>

const int N = 100000;
const int A = 26;
int t, n, next[A];
bool into[N];
char s[N + 1];

int cnt = 0;
bool test(int a, int b) {
	if (a == b) return 0;
	if (next[a] == b) return 1;
	if (next[a] != -1 || into[b]) return 0;
	if (cnt == A - 1) {
		++cnt;
		next[a] = b;
		into[b] = 1;
		return 1;
	}
	int cur = b;
	while (cur != -1 && cur != a) cur = next[cur];
	if (cur == -1) {
		++cnt;
		next[a] = b;
		into[b] = 1;
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		cnt = 0;
		for (int i = 0; i < A; ++i) {
			next[i] = -1;
			into[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0;; ++j) if (test(j, s[i] - 'a')) {
				printf("%c", 'a' + j);
				break;
			}
		}
		printf("\n");
	}
	return 0;
}