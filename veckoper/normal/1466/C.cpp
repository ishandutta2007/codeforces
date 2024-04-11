#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int Case, n, f[2][27][27];
char s[N];
int main() {
	scanf("%d", &Case);
	while (Case--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		memset(f[0], 0, sizeof f[0]);
		for (int i = 1; i <= n; ++i) {
			for (int a = 0; a < 26; ++a)
				for (int b = 0; b < 26; ++b) {
					f[i & 1][a][b] = 1e9;
					if (a == b) continue;
					for (int c = 0; c < 26; ++c) if (a != c)
						f[i & 1][a][b] = min(f[i & 1][a][b], f[~i & 1][b][c]);
					f[i & 1][a][b] += (a != s[i] - 'a');
				}
		}
		int ans = 1e9;
		for (int a = 0; a < 26; ++a)
			for (int b = 0; b < 26; ++b) 
				ans = min(ans, f[n & 1][a][b]);
		printf("%d\n", ans);
	}
	return 0;
}