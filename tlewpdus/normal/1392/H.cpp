#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}

int N, M;

const int MAXN = 2000010;
ll fac[4000100], fnv[4000100];
ll inv[MAXN+10];
ll f[2000100];

int main() {
	scanf("%d%d",&N,&M);
	fac[0] = 1;
	for (int i=1;i<=2*MAXN;i++) fac[i] = fac[i-1]*i%MOD;
	fnv[2*MAXN] = ipow(fac[2*MAXN],MOD-2);
	for (int i=2*MAXN-1;i>=0;i--) fnv[i] = fnv[i+1]*(i+1)%MOD;
	for (int i=1;i<=MAXN;i++) inv[i] = fac[i-1]*fnv[i]%MOD;
	f[0] = 0;
	ll fis = 0, fips = 0;
	for (int n=1;n<=N;n++) {
		ll t = 1+N*inv[n]%MOD*n%MOD*inv[M+1]%MOD;
		ll mul = (n+M)*inv[n]%MOD;
		f[n] = ((fips - fis + MOD) * fac[n] %MOD * fnv[n+M] %MOD + t) * mul  %MOD;
		fis = (fis + f[n] * fac[n+M-1] %MOD * fnv[n-1])%MOD;
		fips = (fips+f[n] * fac[n+M]%MOD* fnv[n])%MOD;
	}
	printf("%lld\n",(f[N]%MOD+MOD)%MOD);

	return 0;
}