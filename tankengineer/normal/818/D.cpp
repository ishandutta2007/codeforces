#include<cstdio>

const int C = 1000000;

int n, alice;

int cnt[C + 1];

int main() {
	scanf("%d%d", &n, &alice);

	for (int i = 0; i < n; ++i) {
		int c;
		scanf("%d", &c);
		if (c == alice) {
			++cnt[c];
		} else {
			if (cnt[c] < cnt[alice]) {
				continue;
			} else {
				++cnt[c];
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= C; ++i) {
		if (i != alice && cnt[i] >= cnt[alice]) {
			ans = i;
			break;
		}
	}

	printf("%d\n", ans);
	return 0;
}