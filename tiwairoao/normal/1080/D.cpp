#include<cstdio>
typedef long long ll;
ll pow(ll b, int p) {
	ll ret = 1;
	while( p ) {
		if( p & 1 ) ret = ret*b;
		b = b*b;
		p >>= 1;
	}
	return ret;
}
ll GetTotal(int b) {
	return (pow(4, b) - 1)/3;
}
void solve() {
	int n; ll k;
	scanf("%d%lld", &n, &k);
	if( n >= 32 ) {
		printf("YES %d\n", n-1);
		return ;
	}
	else {
		ll p = 0, q = 0, tmp = 1;
		for(int i=n-1;i>=0;i--) {
			q += (1LL<<(n-i)) - 1;
			p += 1LL*tmp*GetTotal(i);
			tmp = (tmp-1)*2 + 5;
			if( q <= k && q >= k-p ) {
				printf("YES %d\n", i);
				return ;
			}
			else if( q > k ) break;
		}
		puts("NO");
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++) solve();
}