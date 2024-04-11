#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100020];
int sa[100020];
int sb[100020];
pair<int, int> f[100020];
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 1) {
			if (s[i] == 'a' || s[i] == 'b') {
				s[i] ^= 'a' ^ 'b';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		sa[i + 1] = sa[i];
		sb[i + 1] = sb[i];
		if (s[i] == 'a') {
			sa[i + 1]++;
		}
		if (s[i] == 'b') {
			sb[i + 1]++;
		}
	}
	for (int i = m; i <= n; i++) {
		pair<int, int> u = f[i - m];
		if ((i - m) % 2 == 0) {
			if (sb[i] - sb[i - m] == 0) {
				u.first++;
				u.second -= m - (sa[i] - sa[i - m]);
			}
			f[i] = max(f[i - 1], u);
		} else {
			if (sa[i] - sa[i - m] == 0) {
				u.first++;
				u.second -= m - (sb[i] - sb[i - m]);
			}
			f[i] = max(f[i - 1], u);
		}
	}
	printf("%d\n", -f[n].second);
	return 0;
}