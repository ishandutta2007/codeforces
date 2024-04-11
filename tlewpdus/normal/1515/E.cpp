#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N;
ll M;
ll D[410][410];
ll fac[410], fnv[410];
ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%M*(n%2?a:1)%M;
}
ll comb(ll n, ll r) {
	return fac[n]*fnv[r]%M*fnv[n-r]%M;
}

int main () {
	scanf("%d%lld",&N,&M);
	fac[0] = 1;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%M;
	fnv[N] = ipow(fac[N],M-2);
	for (int i=N-1;i>=0;i--) fnv[i] = fnv[i+1]*(i+1)%M;
	D[0][0] = 1;
	for (int i=1;i<=N;i++) {
		for (int j=1;j<=i;j++) {
			for (int k=1;k<=i;k++) {
				D[i][j] = (D[i][j]+D[i-k][j-1]*fnv[k])%M;
			}
		}
	}
	ll ans = 0;
	ll p = ipow(2,N-1);
	ll half = ipow(2,M-2);
	for (int i=0;i+1<=N-i;i++) {
		ans += p * fac[N-i] % M * D[N-i][i+1] % M;
		p = p*half%M*half%M;
	}
	printf("%lld\n",(ans%M+M)%M);

	return 0;
}