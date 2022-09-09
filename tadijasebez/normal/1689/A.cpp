#include <bits/stdc++.h>

using namespace std;

const int N = 105;
char s[N], t[N];

int main() {
	int tc;
	scanf("%i",&tc);
	while(tc--) {
		int n, m, k;
		scanf("%i %i %i", &n, &m, &k);
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		int i = 1, j = 1, c1 = 0, c2 = 0;
		sort(s + 1, s + 1 + n);
		sort(t + 1, t + 1 + m);
		while (i <= n && j <= m) {
			if (c2 == k || (c1 < k && s[i] < t[j])) {
				c1++;
				c2 = 0;
				printf("%c", s[i]);
				i++;
			} else {
				c2++;
				c1 = 0;
				printf("%c", t[j]);
				j++;
			}
		}
		printf("\n");
	}
    return 0;
}