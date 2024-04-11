#include<cstdio>
const int MAXN = 1000000;
int ans[MAXN + 5], cnt;
void Function(int n, int x) {
	if( n == 1 ) {
		ans[++cnt] = x;
	}
	else if( n == 2 ) {
		ans[++cnt] = x;
		ans[++cnt] = 2*x;
	}
	else if( n == 3 ) {
		ans[++cnt] = x;
		ans[++cnt] = x;
		ans[++cnt] = 3*x;
	}
	else {
		for(int i=1;i<=n;i+=2)
			ans[++cnt] = x;
		Function(n/2, x*2);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	Function(n, 1);
	for(int i=1;i<n;i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[n]);
}