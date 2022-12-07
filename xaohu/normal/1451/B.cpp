#include <bits/stdc++.h>
using namespace std;

int n, q, l, r, len;
char s[200];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &q, s + 1);
		while (q--) {
			scanf("%d%d", &l, &r);
			vector<int> L(n + 1, n + 1), R(n + 1, 0);
			L[0] = 0;
			R[0] = n + 1;
			len = r - l + 1;
			int now = 0;
			for (int i = 1; i <= n; ++i) {
				if (now >= len) break;
				if (s[i] == s[l + now]) 
					L[++now] = i;
			}
			now = 0;
			for (int i = n; 1 <= i; --i) {
				if (now >= len) break;
				if (s[i] == s[r - now])
					R[++now] = i;
			}
			bool ok = 0;
			for (int i = 1; i < len; ++i)
				if (L[i] + 1 < R[len - i])
					ok = 1;
			printf(ok ? "YES\n" : "NO\n");
		}
	}
	return 0;
}