#include<cstdio>

const int N = 1000005, C = 26;

int n, k;

char s[N];

int first[C], last[C];

int main() {
	scanf("%d%d%s", &n, &k, s);
	for (int i = 0; i < C; ++i) {
		first[i] = -1;
		last[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		int d = s[i] - 'A';
		if (first[d] == -1) {
			first[d] = i;
		}
		last[d] = i;
	}
	bool ans = false;
	for (int i = 0; i < n; ++i) {
		int d = s[i] - 'A';
		if (first[d] == i) {
			--k;
			if (k < 0) {
				ans = true;
				break;
			}
		}
		if (last[d] == i) {
			++k;
		}
	}
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}