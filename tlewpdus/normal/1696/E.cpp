#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N;
int A[200100];
ll fac[500100];
ll fnv[500100];

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}
ll comb(ll n, ll r) {
	if (r<0||r>n) return 0;
	return fac[n]*fnv[r]%MOD*fnv[n-r]%MOD;
}

int main() {
	scanf("%d",&N);
	fac[0] = 1;
	for (int i=1;i<=400005;i++) fac[i]=fac[i-1]*i%MOD;
	fnv[400005]=ipow(fac[400005],MOD-2);
	for (int i=400004;i>=0;i--) fnv[i]=fnv[i+1]*(i+1)%MOD;

	for (int i=0;i<=N;i++) scanf("%d",&A[i]);
	A[N+1] = 0;
	ll ans = 0;
	for (int i=0;i<=N;i++) {
			ans = (ans+comb(A[i]+i+1,i+1)-1)%MOD;
			ans = (ans-(comb(A[i+1]+i+1,i+1)-1))%MOD;
	}
	printf("%lld\n",(ans+MOD)%MOD);

	return 0;
}