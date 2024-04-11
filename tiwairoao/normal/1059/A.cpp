#include<cstdio>
const int MAXN = 100000;
int t[MAXN + 5], l[MAXN + 5];
int main() {
	int n, L, a;
	scanf("%d%d%d", &n, &L, &a);
	for(int i=1;i<=n;i++)
		scanf("%d%d", &t[i], &l[i]);
	t[n+1] = L, l[n+1] = 0;
	int ans = 0;
	for(int i=0;i<=n;i++) {
		int s = t[i] + l[i];
		int p = t[i+1];
		ans += (p-s)/a;
	}
	printf("%d\n", ans);
}