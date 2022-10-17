#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
char s[200020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%s", s);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '1') {
			int j = i;
			for (; s[j] == '1'; j++) {

			}
			sort(a + i, a + j + 1);
			i = j;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}