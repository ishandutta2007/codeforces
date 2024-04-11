#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[100], b[100100];
int main() {
	int n;
	scanf("%d", &n);
	int x = (1 << 26) - 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s%s", a, b);
		int c = 0;
		for (int j = 0; b[j]; j++) {
			c |= (1 << (b[j] - 'a'));
		}
		if (x == (-x&x) && a[0] == '!') ans++;
		if (x == (-x&x) && a[0] == '?' && c != x) ans++;

		if (a[0] == '!') {
			x &= c;
		}
		if (a[0] == '.' || (a[0] == '?' && i != n)) {
			x &= (~c);
		}
	}
	printf("%d", ans);
	return 0;
}