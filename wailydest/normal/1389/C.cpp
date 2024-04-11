#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 200000;
const int A = 10;
char s[N + 1];
int t;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int n = strlen(s);
		int ans = ~(1 << 31);
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < A; ++j) {
				int g = 0;
				for (int k = 0, t = 0; k < n; ++k) {
					if (!t && s[k] == '0' + i) {
						++g;
						t = 1;
					}
					else if (t && s[k] == '0' + j) {
						++g;
						t = 0;
					}
				}
				ans = std::min(ans, n - (g - ((g & 1) && i != j ? 1 : 0)));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}