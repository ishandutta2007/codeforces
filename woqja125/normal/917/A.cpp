#include<cstdio>
char in[5010];
int main() {
	int n, ans = 0;
	scanf("%s", in);
	for (n = 0; in[n]; n++);
	for (int i = 0; i < n; i++) {
		int l = 0, r = 0;
		for (int j = i; j < n; j++) {
			if (in[j] == '(') l++, r++;
			if (in[j] == ')') l--, r--;
			if (in[j] == '?') l--, r++;
			if (r < 0) break;
			if (l < 0) l += 2;
			if (l <= 0 && r >= 0 && r % 2 == 0) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}