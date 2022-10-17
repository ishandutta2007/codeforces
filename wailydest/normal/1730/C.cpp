#include <cstdio>
#include <cstring>
#include <vector>

const int A = 10;
const int N = 200005;
int t, n, cnt[N];
char s[N];
std::vector<int> ord[A];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		n = strlen(s);
		for (int i = n - 1; i >= 0; --i) ord[s[i] - '0'].push_back(i);
		for (int i = 0, j = 0; s[i]; ++i) {
			int di;
			for (di = 0; !cnt[di] && ord[di].empty(); ++di);
			if (cnt[di]) --cnt[di];
			else {
				for (; j < ord[di].back(); ++j) {
					ord[s[j] - '0'].pop_back();
					++cnt[std::min(s[j] - '0' + 1, 9)];
				}
				++j;
				ord[di].pop_back();
			}
			printf("%d", di);
		}
		printf("\n");
	}
	return 0;
}