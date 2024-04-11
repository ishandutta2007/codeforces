#include<cstdio>
const int MAXN = 200000;
int a[MAXN + 5], n;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		a[i] = (x < 0); a[i] ^= a[i-1];
	}
	long long ans1 = 0, ans2 = 0;
	int tmp[2] = {1, 0};
	for(int i=1;i<=n;i++) {
		ans1 += tmp[a[i]];
		ans2 += tmp[!a[i]];
		tmp[a[i]]++;
	}
	printf("%lld %lld\n", ans2, ans1);
}