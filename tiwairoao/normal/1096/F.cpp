#include<cstdio>
const int MAXN = 200000;
const int MOD = 998244353;
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
}
int inv(int x) {
	return pow_mod(x, MOD-2);
}
int n, p[MAXN + 5], tree[2][MAXN + 5];
bool tag[MAXN + 5];
inline int lowbit(int x) {
	return x & -x;
}
void update(int x, int k, int t) {
	for(int i=x;i<=n;i+=lowbit(i))
		tree[t][i] = (tree[t][i] + k)%MOD;
}
int sum(int x, int t) {
	int ret = 0;
	for(int i=x;i;i-=lowbit(i))
		ret = (ret + tree[t][i])%MOD;
	return ret;
}
int main() {
	int ans = 0, cnt = 0, tot = 0;
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &p[i]);
		if( p[i] == -1 ) {
			cnt++;
			continue;
		}
		tag[p[i]] = true; update(p[i], 1, 0);
		ans = (ans + i - cnt - sum(p[i], 0))%MOD;
	}
	ans = (ans + 1LL*inv(4)*cnt%MOD*(cnt-1)%MOD)%MOD;
	for(int i=1;i<=n;i++)
		if( !tag[i] ) update(i, 1, 1);
	for(int i=1;i<=n;i++)
		if( p[i] == -1 )
			ans = (ans + tot)%MOD;
		else tot = (tot + 1LL*sum(p[i], 1)*inv(cnt)%MOD)%MOD;
	tot = 0;
	for(int i=n;i>=1;i--)
		if( p[i] == -1 )
			ans = (ans + tot)%MOD;
		else tot = (tot + 1LL*(cnt - sum(p[i], 1))*inv(cnt)%MOD)%MOD;
	printf("%d\n", ans);
}