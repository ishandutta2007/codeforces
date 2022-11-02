#include <bits/stdc++.h>

const int N = 5000;
const int S = (1 << 20);

bool dp[S + 5];
int id[26], cnt; bool tag[26];
int le[26], ri[26], tot[26];
char str[N + 5]; int n, a, b;
int main() {
	scanf("%d%d%d%s", &n, &a, &b, str);
	for (int i = 0; i < 26; i++) id[i] = -1;
	for (int i = 0; i < n; i++) {
		int c = str[i] - 'a';
		if (id[c] == -1) le[id[c] = (cnt++)] = i;
		ri[id[c]] = i, tot[id[c]]++;
	}

	int s = (1 << cnt); dp[0] = 1;
	for (int i = 1; i < s; i++) {
		int l = n, r = 0, t = 0, p = 0; bool f = false;
		for (int j = 0; j < cnt; j++) if ((i >> j) & 1) {
			p |= (1 << j); if (dp[p] && dp[i ^ p]) {dp[i] = true; break;}
			l = std::min(l, le[j]), r = std::max(r, ri[j]), t += tot[j];
			f |= dp[i ^ (1 << j)];
		}
		if (dp[i]) continue;
		if (f && a * (r - l + 1) <= b * t) dp[i] = true;
	}

	int ans = 0;
	for (int i = 0; i < cnt; i++) if (dp[(s - 1) ^ (1 << i)])
		tag[str[le[i]] - 'a'] = true, ans++;
	printf("%d", ans);
	for (int i = 0; i < 26; i++) if (tag[i]) putchar(' '), putchar('a' + i);
	puts("");
}