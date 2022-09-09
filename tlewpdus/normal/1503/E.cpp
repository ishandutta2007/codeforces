#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; //1000000007

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}

int N, M;
ll fac[5010], fnv[5010];

ll C(int n, int r) {
	if (r<0||r>n) return 0;
	return fac[n]*fnv[r]%MOD*fnv[n-r]%MOD;
}
ll calc(int h, int l1, int l2) {
	return C(h+l1-1,l1)*C(h+l2-1,l2-1)%MOD;
}

int main() {
	scanf("%d%d",&N,&M);
	fac[0] = 1;
	for (int i=1;i<=5000;i++) fac[i] = fac[i-1]*i%MOD;
	fnv[5000] = ipow(fac[5000],MOD-2);
	for (int i=4999;i>=0;i--) fnv[i] = fnv[i+1]*(i+1)%MOD;
	ll ans = 0;
	for (int i=0;i+1<N;i++) {
		ll T = 0;
		for (int j=1;j<M;j++) {
			int l1 = j, l2 = M-j, h = N-i-1;
			ans += calc(h,l1,l2) * T % MOD;
			T = (T+calc(N-h,l2,l1))%MOD;
		}
	}
	for (int j=0;j+1<M;j++) {
		ll T = 0;
		for (int i=0;i<N;i++) {
			int l1 = i, l2 = N-i, h = M-j-1;
			ans += calc(h,l1,l2) * T % MOD;
			T = (T+calc(M-h,l2-1,l1+1))%MOD;
		}
	}
	printf("%lld\n",(ans*2%MOD+MOD)%MOD);

	return 0;
}