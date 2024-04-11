#include <bits/stdc++.h>
using namespace std;

int n, k, cnt[26][2];
char s[1 << 20], t[1 << 20];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 26; ++i)
			cnt[i][0] = cnt[i][1] = 0;
		scanf("%d%d%s%s", &n, &k, s + 1, t + 1);
		for (int i = 1; i <= n; ++i) {
			cnt[s[i] - 'a'][0]++;
			cnt[t[i] - 'a'][1]++;
		}
		bool ok = 1;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i][0] < cnt[i][1]) {
				ok = 0;
				break;
			}
			int r = cnt[i][0] - cnt[i][1];
			if (r % k) {
				ok = 0;
				break;
			}
			if (r)
				cnt[i + 1][0] += r;
		}
		printf(ok ? "Yes\n" : "No\n");
	}
	return 0;
}