#include <cstdio>

const int N = 200;
const int A = 26;
int t, n, k, cnt[A];
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &n, &k, s);
		for (int i = 0; i < A; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];
		for (int i = 0; i < k; ++i) {
			int l;
			for (l = 0; l < n / k && cnt[l]; ++l) --cnt[l];
			printf("%c", 'a' + l);
		}
		printf("\n");
	}
	return 0;
}