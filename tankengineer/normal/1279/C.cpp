#include<cstdio>

const int N = 100005;

int n, m;

int a[N];

int pcnt;

bool popped[N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		pcnt = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			popped[a[i]] = false;
		}
		int head = 0;
		long long ans = 0;
		for (int i = 0; i < m; ++i) {
			int b;
			scanf("%d", &b);
			if (popped[b]) {
				++ans;
				--pcnt;
			} else {
				int k = pcnt;
				while (a[head] != b) {
					popped[a[head]] = true;
					++k;
					++head;
					++pcnt;
				}
				ans += 2 * k + 1;
				++head;
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}