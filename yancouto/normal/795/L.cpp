#include <bits/stdc++.h>
using namespace std;

char s[212345];
int pr[212345];

int main() {
	int i, j, n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for(i = 1; i < n; i++)
		if(s[i] == '0')
			pr[i] = i;
		else pr[i] = pr[i - 1];
	for(i = 0; i <= n; i++) {
		int j = 0;
		int ct = 2;
		while(j + i + 1 < n - 1) {
			int k = min(j + i + 1, n - 1);
			if(pr[k] <= j) break;
			j = pr[k];
			ct++;
		}
		if(j + i + 1 >= n - 1 && ct <= k) {
			printf("%d\n", i);
			return 0;
		}
	}
}