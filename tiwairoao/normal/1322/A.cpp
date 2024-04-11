#include <cstdio>

const int MAXN = 1000000;

char s[MAXN + 5]; int n, a[MAXN + 5];
int main() {
	scanf("%d%s", &n, s + 1);
	for(int i=1;i<=n;i++) a[i] = a[i - 1] + (s[i] == ')' ? -1 : 1);
	if( a[n] ) {
		puts("-1");
		return 0;
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		ans += (s[i] == ')' && a[i] < 0) || (s[i] == '(' && a[i] <= 0);
	printf("%d\n", ans);
}