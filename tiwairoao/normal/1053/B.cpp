#include<cstdio>
typedef long long ll;
const int MAXN = 300000;
int a[MAXN + 5], S[MAXN + 5];
int seq[MAXN + 5][2], cnt[2], pos[2];
int Function(ll x) {
	int ret = 0;
	while( x ) {
		if( x & 1 ) ret++;
		x >>= 1;
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		ll x;
		scanf("%I64d", &x);
		a[i] = Function(x);
		S[i] = S[i-1] + a[i];
	}
	ll ans = 0;
	for(int i=64;i>=1;i--) {
		int lst = -1;
		cnt[0] = cnt[1] = 0;
		pos[0] = pos[1] = 0;
		for(int j=1;j<=n;j++) {
			int t = (S[j]&1);
			if( a[j] > i ) {
				cnt[0] = cnt[1] = 0;
				pos[0] = pos[1] = 0;
			}
			else {
				seq[++cnt[S[j-1]&1]][S[j-1]&1] = j-1;
				if( a[j] == i ) lst = j-1;
				while( pos[t]+1 <= cnt[t] && seq[pos[t]+1][t] <= lst && S[j] - S[seq[pos[t]+1][t]] >= 2*i )
					pos[t]++;
				ans += pos[t];
			}
		}
	}
	printf("%I64d\n", ans);
}