#include <bits/stdc++.h>
using namespace std;

int sum[26][200005];
char s[200005];

int main() {
	scanf("%s", s + 1); int len = strlen(s + 1);
	for (int j = 0; j < 26; ++ j)
		for (int i = 1; i <= len; ++ i) {
			sum[j][i] = sum[j][i - 1] + ((s[i] - 'a') == j);
		}
	int CASE; scanf("%d", &CASE);
	for (int Case = 1; Case <= CASE; ++ Case) {
		int l, r; scanf("%d%d", &l, &r);
		int cnt = 0;
		for (int j = 0; j < 26; ++ j) {
			cnt += ((sum[j][r] - sum[j][l - 1]) != 0);
		}
		if (cnt >= 3) printf("Yes\n");
		else if (cnt == 2) {
			if (s[l] != s[r]) printf("Yes\n");
			else printf("No\n");
		} else {
			if (l == r) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}