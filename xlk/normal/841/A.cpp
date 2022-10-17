#include <bits/stdc++.h>
using namespace std;
int n, k, c[100];
char s[1020];
int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		c[s[i] - 'a']++;
	}
	int z = 0;
	for (int i = 0; i < 26; i++) {
		z = max(z, c[i]);
	}
	printf("%s", z > k ? "NO" : "YES");
	return 0;
}