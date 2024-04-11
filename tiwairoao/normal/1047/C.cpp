#include<cstdio>
const int MAXM= 15000000;
const int MAXN = 300000;
bool Is_prm[MAXM + 5];
int prm[MAXM + 5], pcnt = 0;
void Sieve() {
	for(int i=2;i<=MAXM;i++) {
		if( !Is_prm[i] )
			prm[++pcnt] = i;
		for(int j=1;1LL*i*prm[j]<=MAXM;j++) {
			Is_prm[i*prm[j]] = true;
			if( i % prm[j] == 0 ) break;
		}
	}
}
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x%y);
}
int cnt[MAXM + 5], a[MAXN + 5];
int main() {
	Sieve(); int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	int g = a[1];
	for(int i=1;i<=n;i++)
		g = gcd(g, a[i]);
	for(int i=1;i<=n;i++)
		cnt[a[i]/g]++;
	if( cnt[1] == n ) {
		printf("%d\n", -1);
		return 0;
	}
	int ans = MAXM;
	for(int i=1;i<=pcnt;i++) {
		int tot = 0;
		for(int j=prm[i];j<=MAXM;j+=prm[i])
			tot += cnt[j];
		if( n - tot < ans ) ans = n - tot;
	}
	printf("%d\n", ans);
}