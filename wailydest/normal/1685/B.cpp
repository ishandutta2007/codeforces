#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 200000;
int t, a, b, c[2];
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &a, &b, c, c + 1);
		scanf("%s", s);
		int sum[2] = {0, 0}, have = 0;
		std::vector<int> big[2];
		for (int i = 0; s[i];) {
			int amt = 0, fi = s[i] - 'A';
			do {
				++sum[s[i] - 'A'];
				++amt;
				++i;
			} while (s[i] && s[i] != s[i - 1]);
			if (amt & 1) have += amt / 2;
			else {
				big[fi].push_back(amt / 2);
				have += amt / 2 - 1;
			}
		}
		bool ok = sum[0] == a + c[0] + c[1] && sum[1] == b + c[0] + c[1];
		int need = c[0] + c[1] - have;
		int can = 0;
		for (int t = 0; t < 2; ++t) {
			std::sort(big[t].begin(), big[t].end());
			int len = 0;
			for (int j = 0; j < (int)big[t].size(); ++j) if (len + big[t][j] <= c[t]) {
				len += big[t][j];
				++can;
			}
		}
		if (can < need) ok = 0;
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}